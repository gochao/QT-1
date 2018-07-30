#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qaudiolevel.h"
#include <QAudioProbe>
#include <QAudioRecorder>
#include <QMediaRecorder>
#include<QMediaPlayer>
#include<QCameraInfo>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QCoreApplication>
#include<QFileDialog>
#include<QDebug>
#include<synchapi.h>
#include <QTimer>
#include<QByteArray>
#include<QtNetwork>
#include<QMap>
#include<QFileDialog>
#include<QJsonDocument>
#include<QJsonParseError>
#include<QScriptEngine>
#include<QScriptValue>
#include<QScriptValueIterator>
#include<QStandardItemModel>
#include<QMessageBox>
#include <QtGlobal>

static qreal getPeakValue(const QAudioFormat &format);
static QVector<qreal> getBufferLevels(const QAudioBuffer &buffer);

template <class T>
static QVector<qreal> getBufferLevels(const T *buffer, int frames, int channels);


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentIndex = 0;
    ui->mainWidget->setCurrentIndex(currentIndex);
    ui->nextStepBtn->hide();
    ui->lastStepBtn->hide();

    facetime = 0;
    expenseType = 3 ;
    busiTalble = false;


    //照相机配置
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.count() > 0){
        foreach (const QCameraInfo &cameraInfo, cameras) {
            qDebug()<<cameraInfo.description();
        }
        camera = new QCamera(cameras.at(0));
    }

    viewfinder = new QCameraViewfinder(this);
    ui->imageLayout->addWidget(viewfinder);
    camera->setViewfinder(viewfinder);
    viewfinder->resize(600,350);
    imageCapture = new QCameraImageCapture(camera);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(sendPhoto(int,QImage)));

    //语音识别设置
    audioRecorder = new QAudioRecorder(this);
    probe = new QAudioProbe;
    connect(probe, SIGNAL(audioBufferProbed(QAudioBuffer)),
            this, SLOT(processBuffer(QAudioBuffer)));
    probe->setSource(audioRecorder);
    recordNum = 0;
    recordHigh = 0;
    recordLow = 0;
    recordSend = false;
    this->setRecord();
    this->startRecord();

    //初始化音频播放变量
    player = new QMediaPlayer;
    playStatus = false;
    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(playChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//人脸识别按钮单击事件
void MainWindow::on_faceBtn_clicked()
{
    facetime = 0;
    currentIndex = 1;
    ui->mainWidget->setCurrentIndex(currentIndex);
    camera->start();

    timer = new QTimer( this );
    connect(timer, SIGNAL(timeout()), this, SLOT(faceCheck()));
    timer->start(2000);
}

void MainWindow::on_idBtn_clicked()
{
    ui->mainWidget->setCurrentIndex(2);
}


//人脸识别
void MainWindow::faceCheck(){
    qDebug()<<camera->status()<<endl;
    if(timer->isActive()){
        timer->stop();
    }
    if(QCamera::ActiveStatus == camera->status()){
        QMap<QString ,QByteArray> faceParam;
        faceParam.clear();
        list.clear();
        facetime ++;
        Sleep(100);
        imageCapture->capture();
    }
}

//人脸查找发送图片
void MainWindow::sendPhoto(int id,QImage image){
    QString baseDir = QCoreApplication::applicationDirPath();
    QString fileDir = baseDir.append("/files/face/");
    QString str_time;
    QDateTime time = QDateTime::currentDateTime();
    str_time = time.toString("yyyy-MM-dd_hh-mm-ss");
    fileDir.append(str_time);
    fileDir.append(".jpg");

    QPixmap pixmap = QPixmap::fromImage(image);
    pixmap.save(fileDir);
qDebug()<<fileDir<<endl;
    QFile file(fileDir);
    if (!file.open(QIODevice::ReadOnly)||file.size()==0)
        {
           file.close();
           return ;
        }
    QByteArray fdata = file.readAll();
    file.close();
    manager = new QNetworkAccessManager(this);
    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(faceReply(QNetworkReply*)));
    QUrlQuery params;
    fdata = fdata.toBase64();
    fdata = fdata.replace("+","-");
    fdata = fdata.replace("/","_");
    params.addQueryItem("image",fdata);
    params.addQueryItem("group_id","expenseRobot");
    params.addQueryItem("imageType",".jpg");

    QString  data = params.toString();

    QNetworkRequest request = this->getHttpRequest("http://127.0.0.1:8000/face/search/");
    request.setHeader(QNetworkRequest::ContentLengthHeader, data.size());
    manager->post(request,params.toString().toUtf8());
}

QNetworkRequest MainWindow::getHttpRequest(QString url){
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded;charset=utf-8");
//    request.setRawHeader("Accept","text/html, application/xhtml+xml, */*");
//    request.setRawHeader("Accept-Language","zh-CN");
//    request.setRawHeader("X-Requested-With","XMLHttpRequest");
//    request.setRawHeader("User-Agent","Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0)");
//    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
//    request.setRawHeader("Accept-Encoding","gzip,deflate");
//    request.setRawHeader("Host","localhost:8888");
//    request.setRawHeader("Content-Length","18");
//    request.setRawHeader("Connection","Keep-Alive");
//    request.setRawHeader("Cache-Control","no-cache");
    return request;
}

QByteArray  MainWindow::Image_To_Base64(QString ImgPath){
    QImage image(ImgPath);
    QByteArray ba;
     QBuffer buf(&ba);
     image.save(&buf,"JPG",20);
     QByteArray hexed = ba.toBase64();
     buf.close();
     return hexed;
}

//人脸识别结果处理
void MainWindow::faceReply(QNetworkReply * reply){
    if(reply->error() ==    QNetworkReply::NoError){
        QByteArray all = reply->readAll();
        qDebug()<<endl<<endl<<all<<endl;
        QJsonParseError jsonError;
        QJsonDocument doucment = QJsonDocument::fromJson(all, &jsonError);  // 转化为 JSON 文档
        if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
            if(doucment.isObject()){  // JSON 文档为对象
                QJsonObject object = doucment.object();  // 转化为对象
                //获取result_num参数
                int result_num = 0;
                if(object.contains("result_num")){
                       QJsonValue numValue = object.value("result_num");
                       if(numValue.isDouble()){
                           result_num = numValue.toInt();
                       }
                }
                if(result_num >=1){//人脸识别有结果
                    if(object.contains("result")){
                        QJsonValue resultsValue = object.value("result");
                        if(resultsValue.isArray()){
                            //如果result是数组
                            QJsonArray resultsArray = resultsValue.toArray();
                            QString uid;
                            QString user_info;
                            double score = 80;//阈值为80分
                            int nSize = resultsArray.size();
                            for(int i = 0  ; i < nSize ; i ++){
                                QJsonValue resultValue = resultsArray.at(i);
                                double scoreTemp = 0;
                                if(resultValue.isObject()){
                                    QJsonObject resultObj = resultValue.toObject();
                                    //获取相似度分数
                                    if(resultObj.contains("scores")){
                                        QJsonValue scoresVal = resultObj.value("scores");
                                        if(scoresVal.isArray()){
                                            QJsonArray scoresArray = scoresVal.toArray();
                                            QJsonValue scoreVal = scoresArray.at(0);
                                            if(scoreVal.isDouble()){
                                                scoreTemp = scoreVal.toDouble();
                                            }
                                        }
                                    }
                                    if(scoreTemp > score){
                                        score = scoreTemp;
                                        //获取uid
                                        if(resultObj.contains("uid")){
                                            QJsonValue uidVal = resultObj.value("uid");
                                            if(uidVal.isString()){
                                                uid = uidVal.toString();
                                            }
                                        }
                                        //获取user_info
                                        if(resultObj.contains("user_info")){
                                            QJsonValue infoVal = resultObj.value("user_info");
                                            if(infoVal.isString()){
                                                user_info = infoVal.toString();
                                            }
                                        }
                                    }
                                }
                            }
                            if(score > 80){
                                //相似度分数大于80,识别成功
                                QString userInfo = "用户："+user_info;
                                ui->userInfo->setText(userInfo);
                                camera->stop();
                                this->toNextStep();
                                player->stop();
                                this->sendPlayText("请选择报销类型");
                            }else{
                                //相似度分数小于80,识别失败
                                if(facetime <= 5){
                                    this->faceCheck();
                                }else{
                                    camera->stop();
                                    QMessageBox::information(this, QString::fromUtf8("警告"),QString::fromUtf8("人脸识别失败，请更换识别方式"));
                                    this->toLastStep();
                            }
                        }
                    }
                }else{
                    if(facetime <= 5){
                        this->faceCheck();
                    }else{
                        camera->stop();
                        QMessageBox::information(this, QString::fromUtf8("警告"),QString::fromUtf8("人脸识别失败，请更换识别方式"));
                        this->toLastStep();
                    }
                }
            }
        }
       }
    }else{
        if(facetime <= 5){
            this->faceCheck();
        }else{
            camera->stop();
            this->toLastStep();
        }
    }
}

//上一步
void MainWindow::toLastStep(){
    if(currentIndex == 4 || currentIndex == 5 || currentIndex == 6){
        currentIndex = 3;
    }else if(currentIndex == 7){
        currentIndex = expenseType;
    }else if(currentIndex > 0 && currentIndex != 3){
        currentIndex -- ;
    }
    ui->mainWidget->setCurrentIndex(currentIndex);
}

//下一步
void MainWindow::toNextStep(){
    if(currentIndex == 1 || currentIndex == 2){
        currentIndex = 3;
    }else if(currentIndex == 3){
        currentIndex = expenseType;
    }else if(currentIndex == 4 || currentIndex == 5 || currentIndex == 6){
        currentIndex = 7;
    }else if(currentIndex < 9 && currentIndex > 0){
        currentIndex ++;
    }
    ui->mainWidget->setCurrentIndex(currentIndex);
    if(currentIndex == 9){
        this->sendPlayText("请确认报销数据");
    }
}

void MainWindow::on_lastStepBtn_clicked()
{
    this->toLastStep();
}


void MainWindow::on_nextStepBtn_clicked()
{
    this->toNextStep();
}

//当前页发生变化调用函数
void MainWindow::on_mainWidget_currentChanged(int arg1)
{
    ui->lastStepBtn->hide();
    ui->nextStepBtn->hide();
    if(currentIndex >1 && currentIndex != 3&& currentIndex != 10){
        ui->lastStepBtn->show();
    }
    if(currentIndex > 1 && currentIndex != 2 && currentIndex != 9 && currentIndex != 10){
        ui->nextStepBtn->show();
    }
    if(currentIndex == 4 && busiTalble == false){
        QTableWidget * table = ui->busiBodyTable;
        busiTalble = true;
        table->setColumnCount(19);//设置列数
        table->setRowCount(1);//设置行数
        /*设置列名*/
        QStringList headers;
        headers<<"人员类别"<<"出差人"<<"部门"<<"起始时间"<<"终止时间"<<"出差天数"<<"出发地点"<<"到达地点"<<"市间交通费"<<"交通费单据张数"<<"住宿费用"<<"住宿单据张数"<<"补贴天数"<<"交通补贴"<<"	伙食补贴"<<"其他费用金额"<<"其他费用单据张数"<<"其他费用说明"<<"小计";
        table->setHorizontalHeaderLabels(headers);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
}

//选择差旅报销单
void MainWindow::on_busiBtn_clicked()
{
    currentIndex = 4;
    expenseType = 4;
    ui->mainWidget->setCurrentIndex(currentIndex);
}

//选择费用报销单
void MainWindow::on_costBtn_clicked()
{
    currentIndex = 5;
    expenseType = 5;
    ui->mainWidget->setCurrentIndex(currentIndex);
}


//选择出国保险单
void MainWindow::on_abroadBtn_clicked()
{
    currentIndex = 6;
    expenseType = 6;
    ui->mainWidget->setCurrentIndex(currentIndex);
}

//增行
void MainWindow::on_busiBodyAddBtn_clicked()
{
    int rowCount = ui->busiBodyTable->rowCount();
    rowCount ++ ;
    ui->busiBodyTable->setRowCount(rowCount);
}

//删行
void MainWindow::on_busiBodyDelBtn_clicked()
{
    int rowIndex = ui->busiBodyTable->currentRow();
    if(rowIndex != -1){
        ui->busiBodyTable->removeRow(rowIndex);
    }
}

//选择文件
void MainWindow::on_fileChooseBtn_clicked()
{

    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(tr("打开图片"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置文件过滤器
    fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg)"));
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if(fileDialog->exec()){
        fileNames = fileDialog->selectedFiles();
    }
    QString fileName;
    fileName = fileNames.at(0);
    qDebug()<<fileName<<endl;
    manager = new QNetworkAccessManager(this);
    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(billReply(QNetworkReply*)));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)||file.size()==0)
        {
           file.close();
           return ;
        }
    QByteArray fdata = file.readAll();
    file.close();
    fdata = fdata.toBase64();
    fdata = fdata.replace("+","-");
    fdata = fdata.replace("/","_");

    QUrlQuery params;
    params.addQueryItem("image",fdata);
    params.addQueryItem("imageType",".jpg");
    QString  data = params.toString();

    QNetworkRequest request = this->getHttpRequest("http://127.0.0.1:8000/bill/");
    request.setHeader(QNetworkRequest::ContentLengthHeader, data.size());
    manager->post(request,params.toString().toUtf8());
}
//票据识别返回处理
void MainWindow::billReply(QNetworkReply * reply){
    if(reply->error() ==    QNetworkReply::NoError){
        QByteArray all = reply->readAll();
        qDebug()<<endl<<endl<<all<<endl;
        QJsonParseError jsonError;
        QJsonDocument doucment = QJsonDocument::fromJson(all, &jsonError);  // 转化为 JSON 文档
        if((!doucment.isEmpty()) && jsonError.error == QJsonParseError::NoError){//解析未发生错误
            if(doucment.isObject()){
                QJsonObject object = doucment.object();
                if(object.contains("success")){
                    int success = 0;
                    QJsonValue successVal = object.value("success");
                    if(successVal.isDouble()){
                        success = successVal.toInt();
                    }
                    if(success == 1){
                        int billType = 0;
                        if(object.contains("type")){
                            QJsonValue typeVal = object.value("type");
                            if(typeVal.isDouble()){
                                billType = typeVal.toInt();
                            }
                        }
                        QJsonObject infoObj;
                        if(object.contains("info")){
                            QJsonValue infoVal = object.value("info");
                            if(infoVal.isObject()){
                                infoObj = infoVal.toObject();
                            }
                        }
                        QString type;
                        QString billContent;
                        QString user;
                        QString start;
                        QString end;
                        QString billDate;
                        QString money;
                        QString other;
                        switch (billType) {
                        case 1://发票
                            type = "发票";
                            if(infoObj.contains("goods")){
                                QJsonValue goodsVal = infoObj.value("goods");
                                if(goodsVal.isString()){
                                    billContent = goodsVal.toString();
                                }
                            }
                            if(infoObj.contains("date")){
                                QJsonValue dateVal = infoObj.value("date");
                                if(dateVal.isString()){
                                    billDate = dateVal.toString();
                                }
                            }
                            if(infoObj.contains("price")){
                                QJsonValue priceVal = infoObj.value("price");
                                if(priceVal.isString()){
                                    money = priceVal.toString();
                                }
                            }
                            if(infoObj.contains("number")){
                                QJsonValue numberVal = infoObj.value("number");
                                if(numberVal.isString()){
                                    other = numberVal.toString();
                                }
                            }
                            break;
                        case 2://火车票
                            type = "火车票";
                            if(infoObj.contains("person")){
                                QJsonValue personVal = infoObj.value("person");
                                if(personVal.isString()){
                                    user = personVal.toString();
                                }
                            }
                            if(infoObj.contains("date")){
                                QJsonValue dateVal = infoObj.value("date");
                                if(dateVal.isString()){
                                    billDate = dateVal.toString();
                                }
                            }
                            if(infoObj.contains("departure")){
                                QJsonValue departureVal = infoObj.value("departure");
                                if(departureVal.isString()){
                                    start = departureVal.toString();
                                }
                            }
                            if(infoObj.contains("price")){
                                QJsonValue priceVal = infoObj.value("price");
                                if(priceVal.isString()){
                                    money = priceVal.toString();
                                }
                            }
                            if(infoObj.contains("destination")){
                                QJsonValue destinationVal = infoObj.value("destination");
                                if(destinationVal.isString()){
                                    end = destinationVal.toString();
                                }
                            }
                            break;
                        case 3://飞机票
                            type = "飞机票";
                            if(infoObj.contains("person")){
                                QJsonValue personVal = infoObj.value("person");
                                if(personVal.isString()){
                                    user = personVal.toString();
                                }
                            }
                            if(infoObj.contains("date")){
                                QJsonValue dateVal = infoObj.value("date");
                                if(dateVal.isString()){
                                    billDate = dateVal.toString();
                                }
                            }
                            if(infoObj.contains("departure")){
                                QJsonValue departureVal = infoObj.value("departure");
                                if(departureVal.isString()){
                                    start = departureVal.toString();
                                }
                            }
                            if(infoObj.contains("price")){
                                QJsonValue priceVal = infoObj.value("price");
                                if(priceVal.isString()){
                                    money = priceVal.toString();
                                }
                            }
                            if(infoObj.contains("destination")){
                                QJsonValue destinationVal = infoObj.value("destination");
                                if(destinationVal.isString()){
                                    end = destinationVal.toString();
                                }
                            }
                            break;
                        case 4://出租车票
                            type = "出租车票";
                        default:
                            break;
                        }
                        //添加一行数据
                        QTableWidget * table = ui->billTable;
                        int rowIndex = table->rowCount();
                        table->setRowCount(rowIndex + 1);
                        table->setRowHeight(rowIndex, 24);//设置行的高度
                        QTableWidgetItem *item = new QTableWidgetItem (type);
                        table->setItem(rowIndex, 0, item);
                        item = new QTableWidgetItem (billContent);
                        table->setItem(rowIndex, 1, item);
                        item = new QTableWidgetItem (billDate);
                        table->setItem(rowIndex, 2, item);
                        item = new QTableWidgetItem (user);
                        table->setItem(rowIndex, 3, item);
                        item = new QTableWidgetItem (money);
                        table->setItem(rowIndex, 4, item);
                        item = new QTableWidgetItem (start);
                        table->setItem(rowIndex, 5, item);
                        item = new QTableWidgetItem (end);
                        table->setItem(rowIndex, 6, item);
                        item = new QTableWidgetItem (other);
                        table->setItem(rowIndex, 7, item);
                    }
                }
            }
        }
    }
//    QString all = reply->readAll();
//    qDebug()<<endl<<all<<endl;
//    ui->billText->setText(all);
    //QTableWidget * table = ui->billTable;

}

//继续报销
void MainWindow::on_continueExpenseBtn_clicked()
{
    currentIndex = 3;
    expenseType = 3;
    ui->mainWidget->setCurrentIndex(currentIndex);
}

//结束报销
void MainWindow::on_logoutBtn_clicked()
{
    currentIndex =0;
    expenseType = 3;
    ui->mainWidget->setCurrentIndex(currentIndex);
}

//确认并提交
void MainWindow::on_confirmBtn_clicked()
{
    currentIndex = 10;
    ui->mainWidget->setCurrentIndex(currentIndex);
}


//设置录音机
void MainWindow::setRecord(){
    audioRecorder->setAudioInput(audioRecorder->audioInputs().at(0));
    QAudioEncoderSettings settings;
    settings.setCodec("audio/pcm");
    settings.setSampleRate(16000);
    settings.setBitRate(128000);
    settings.setChannelCount(1);
    settings.setQuality(QMultimedia::VeryHighQuality);
    settings.setEncodingMode( QMultimedia::ConstantBitRateEncoding);
    QString container = "audio/x-wav";

    audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings(), container);
}

//开始录音
void MainWindow::startRecord(){
    QString baseDir = QCoreApplication::applicationDirPath();
    QString fileDir = baseDir.append("/files/voices/");
    QString str_time;
    QDateTime time = QDateTime::currentDateTime();
    str_time = time.toString("yyyy-MM-dd_hh-mm-ss");
    fileDir.append(str_time);
//    fileDir.append("-");
//    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//    int randNum =qrand()%10;
//    fileDir.append(randNum);
    fileDir.append(".wav");
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(fileDir));
    audioRecorder->record();
}

//结束录音
void MainWindow::stopRecord(){
    audioRecorder->stop();
    QString fileDir = audioRecorder->outputLocation().toLocalFile();
    //qDebug()<<endl<<audioRecorder->outputLocation().toLocalFile()<<endl;
    QFile file(fileDir);
    if(recordSend == true){
        //发送语音指令，进行识别
        manager = new QNetworkAccessManager(this);
        QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(voiceReply(QNetworkReply*)));


        if (!file.open(QIODevice::ReadOnly)||file.size()==0)
            {
               file.close();
               return ;
            }
        QByteArray fdata = file.readAll();
        file.close();
        fdata = fdata.toBase64();
        fdata = fdata.replace("+","-");
        fdata = fdata.replace("/","_");

        QUrlQuery params;

        params.addQueryItem("audio",fdata);
        params.addQueryItem("audioType",".wav");
        QString  data = params.toString();

        QNetworkRequest request = this->getHttpRequest("http://127.0.0.1:8000/understand/recognition/");
        request.setHeader(QNetworkRequest::ContentLengthHeader, data.size());
        manager->post(request,params.toString().toUtf8());
    }

    file.remove();
    recordNum = 0;
    recordHigh = 0;
    recordLow = 0;
    recordSend = false;
    this->startRecord();
}

template <class T>
QVector<qreal> getBufferLevels(const T *buffer, int frames, int channels)
{
    QVector<qreal> max_values;
    max_values.fill(0, channels);

    for (int i = 0; i < frames; ++i) {
        for (int j = 0; j < channels; ++j) {
            qreal value = qAbs(qreal(buffer[i * channels + j]));
            if (value > max_values.at(j))
                max_values.replace(j, value);
        }
    }

    return max_values;
}

// This function returns the maximum possible sample value for a given audio format
qreal getPeakValue(const QAudioFormat& format)
{
    // Note: Only the most common sample formats are supported
    if (!format.isValid())
        return qreal(0);

    if (format.codec() != "audio/pcm")
        return qreal(0);

    switch (format.sampleType()) {
    case QAudioFormat::Unknown:
        break;
    case QAudioFormat::Float:
        if (format.sampleSize() != 32) // other sample formats are not supported
            return qreal(0);
        return qreal(1.00003);
    case QAudioFormat::SignedInt:
        if (format.sampleSize() == 32)
            return qreal(INT_MAX);
        if (format.sampleSize() == 16)
            return qreal(SHRT_MAX);
        if (format.sampleSize() == 8)
            return qreal(CHAR_MAX);
        break;
    case QAudioFormat::UnSignedInt:
        if (format.sampleSize() == 32)
            return qreal(UINT_MAX);
        if (format.sampleSize() == 16)
            return qreal(USHRT_MAX);
        if (format.sampleSize() == 8)
            return qreal(UCHAR_MAX);
        break;
    }

    return qreal(0);
}

// returns the audio level for each channel
QVector<qreal> getBufferLevels(const QAudioBuffer& buffer)
{
    QVector<qreal> values;

    if (!buffer.format().isValid() || buffer.format().byteOrder() != QAudioFormat::LittleEndian)
        return values;

    if (buffer.format().codec() != "audio/pcm")
        return values;

    int channelCount = buffer.format().channelCount();
    values.fill(0, channelCount);
    qreal peak_value = getPeakValue(buffer.format());
    if (qFuzzyCompare(peak_value, qreal(0)))
        return values;

    switch (buffer.format().sampleType()) {
    case QAudioFormat::Unknown:
    case QAudioFormat::UnSignedInt:
        if (buffer.format().sampleSize() == 32)
            values = getBufferLevels(buffer.constData<quint32>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 16)
            values = getBufferLevels(buffer.constData<quint16>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 8)
            values = getBufferLevels(buffer.constData<quint8>(), buffer.frameCount(), channelCount);
        for (int i = 0; i < values.size(); ++i)
            values[i] = qAbs(values.at(i) - peak_value / 2) / (peak_value / 2);
        break;
    case QAudioFormat::Float:
        if (buffer.format().sampleSize() == 32) {
            values = getBufferLevels(buffer.constData<float>(), buffer.frameCount(), channelCount);
            for (int i = 0; i < values.size(); ++i)
                values[i] /= peak_value;
        }
        break;
    case QAudioFormat::SignedInt:
        if (buffer.format().sampleSize() == 32)
            values = getBufferLevels(buffer.constData<qint32>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 16)
            values = getBufferLevels(buffer.constData<qint16>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 8)
            values = getBufferLevels(buffer.constData<qint8>(), buffer.frameCount(), channelCount);
        for (int i = 0; i < values.size(); ++i)
            values[i] /= peak_value;
        break;
    }

    return values;
}

void MainWindow::processBuffer(const QAudioBuffer& buffer)
{
    if (audioLevels.count() != buffer.format().channelCount()) {
        qDeleteAll(audioLevels);
        audioLevels.clear();
        for (int i = 0; i < buffer.format().channelCount(); ++i) {
            QAudioLevel *level = new QAudioLevel();
            audioLevels.append(level);
            ui->levelLayout->addWidget(level);
        }
    }

    QVector<qreal> levels = getBufferLevels(buffer);
    for (int i = 0; i < levels.count(); ++i)
        audioLevels.at(i)->setLevel(levels.at(i));

    //qDebug()<<endl<<levels<<endl;

    recordNum ++;
    if(levels.at(0) >= 0.35){
        recordHigh ++;
        recordLow = 0 ;
        qDebug()<<endl<<levels<<endl;
    }else{
        recordLow ++;
    }

    if(recordNum <= 150){
        //当录音时间小于6秒时
        if(recordHigh >= 2){
            if(recordLow >= 12){
                //当1秒之内无声音时，结束录音
                recordSend = true;
                this->stopRecord();
            }
        }
    }else{
        //当录音时间大于6秒时，结束录音
        if(recordHigh >= 2){
            recordSend = true;
        }else{
            recordSend = false;
        }
        this->stopRecord();
    }
}

//语音识别返回处理
void MainWindow::voiceReply(QNetworkReply * reply){
    if(reply->error() ==    QNetworkReply::NoError){
        QByteArray all = reply->readAll();
        qDebug()<<endl<<all<<endl;
        QJsonParseError jsonError;
        QJsonDocument doucment = QJsonDocument::fromJson(all, &jsonError);  // 转化为 JSON 文档
        if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {//JSON转换未出错
            if(doucment.isObject()){ // JSON 文档为对象
                QJsonObject object = doucment.object();
                int statusCode = 0;//定义statusCode
                if(object.contains("statusCode")){
                    QJsonValue statusCodeVal = object.value("statusCode");
                    statusCode = statusCodeVal.toString().toInt();

                }

                //如果statusCode == 1,识别成功，获取指令编码和识别字符串
                if(statusCode == 1){
                    QString instruction_number;
                    QString resultStr;
                    //获取指令编码
                    if(object.contains("instruction_number")){
                        QJsonValue instructionVal = object.value("instruction_number");
                        if(instructionVal.isString()){
                            instruction_number = instructionVal.toString().trimmed();
                        }
                    }
                    qDebug()<<endl<<instruction_number<<endl;
                    //获取识别字符串并拼接
                    if(object.contains("content")){
                        QJsonValue contentVal = object.value("content");
                        if(contentVal.isObject()){
                            QJsonObject contentObj = contentVal.toObject();
                            if(contentObj.contains("result")){
                                QJsonValue resultsVal = contentObj.value("result");
                                if(resultsVal.isArray()){
                                    QJsonArray resultArray =resultsVal.toArray();
                                    int size = resultArray.size();
                                    for(int i = 0; i < size ; i++){
                                        QJsonValue resultVal = resultArray.at(i);
                                        if(resultVal.isString()){
                                            QString resultStrT = resultVal.toString().trimmed();
                                            //去掉逗号
                                            resultStrT.replace(resultStrT.length()-1,1,"");
                                            resultStr.append(resultStrT);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    qDebug()<<endl<<resultStr<<endl;
                    this->instructionExp(instruction_number);
                }
            }
        }
    }
}

void MainWindow::instructionExp(QString instruction){
    if("0001" == instruction){
        //报销
    }else if("0002" == instruction){
        //身份证
        if(currentIndex == 0){
            //跳转至身份证识别
            ui->idBtn->click();
            this->sendPlayText("身份证识别中，请稍后");
        }
    }else if("0003" == instruction){
        //人脸
        if(currentIndex == 0){
            //跳转至人脸识别
            ui->faceBtn->click();
            this->sendPlayText("人脸识别中，请稍后");
        }
    }else if("0004" == instruction){
        //差旅报销单
        if(currentIndex == 3){
            //跳转至差旅报销单
            ui->busiBtn->click();
            this->sendPlayText("请填写报销信息");
        }
    }else if("0005" == instruction){
        //出国报销单
        if(currentIndex == 3){
            //跳转至出国报销单
            ui->abroadBtn->click();
            this->sendPlayText("请填写报销信息");
        }
    }else if("0006" == instruction){
        if(currentIndex == 9){
            //点击确认
            ui->confirmBtn->click();
        }
    }else if("0007" == instruction){
        //取消
    }else if("0008" == instruction){
        //提交
        if(currentIndex == 9 ){
            ui->confirmBtn->click();
        }
    }else if("0009" == instruction){
        //退出结束
        if(currentIndex == 10){
            //退出操作
            ui->logoutBtn->click();
        }
    }else if("0010" == instruction){
        //继续报销
        if(currentIndex == 10){
            //继续报销操作
            ui->continueExpenseBtn->click();
        }
    }else if("0011" == instruction){
        //上一步
         this->toLastStep();
    }else if("0012" == instruction){
        //下一步
        this->toNextStep();
    }else if("0013" == instruction){
        //跳转至费用报销
        if(currentIndex == 3){
            //跳转至出国报销单
            ui->costBtn->click();
        }
    }else if("0014" == instruction){
        //你好
        if(currentIndex == 0){
            QByteArray str ="你好，欢迎使用智能报销系统，请选择身份验证方式";
            this->sendPlayText(str);
        }
    }
}


//发送音频文本，进行语音合成
void MainWindow::sendPlayText(QByteArray text){
    manager = new QNetworkAccessManager(this);
    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(playReply(QNetworkReply*)));

    QUrlQuery params;

    text = text.toBase64();
    text = text.replace("+","-");
    text = text.replace("/","_");
    params.addQueryItem("text",text);
    QString  data = params.toString();

    QNetworkRequest request = this->getHttpRequest("http://127.0.0.1:8000/understand/synthesis/");
    request.setHeader(QNetworkRequest::ContentLengthHeader, data.size());
    manager->post(request,params.toString().toUtf8());
}

//语音合成
void MainWindow::playReply(QNetworkReply * reply){
    if(reply->error() ==    QNetworkReply::NoError){
        QByteArray all = reply->readAll();
        qDebug()<<endl<<endl<<all<<endl;
        QJsonParseError jsonError;
        QJsonDocument doucment = QJsonDocument::fromJson(all, &jsonError);  // 转化为 JSON 文档
        if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
            if(doucment.isObject()){
                QJsonObject object = doucment.object();
                int statusCode = 0;
                if(object.contains("statusCode")){
                    QJsonValue statusVal = object.value("statusCode");
                    if(statusVal.isString()){
                        statusCode = statusVal.toString().toInt();
                    }
                }
                qDebug()<<statusCode<<endl;
                if(statusCode == 1){
                    if(object.contains("content")){
                        QJsonValue contentVal = object.value("content");
                        QByteArray playData;
                        if(contentVal.isString()){
                            playData = contentVal.toString().toLocal8Bit();
                            playData = playData.replace("-","+");
                            playData = playData.replace("_","/");
                            playData = QByteArray::fromBase64(playData);

                            QString baseDir = QCoreApplication::applicationDirPath();
                            QString fileDir = baseDir.append("/files/player/");
                            QString str_time;
                            QDateTime time = QDateTime::currentDateTime();
                            str_time = time.toString("yyyy-MM-dd_hh-mm-ss");
                            fileDir.append(str_time);
                            fileDir.append(".wav");

                            QFile file(fileDir);
                            file.open(QIODevice::WriteOnly);
                            QDataStream out(&file);
                            out<<playData;
                            file.close();
                            //播放前，需停止语音识别功能
                            audioRecorder->stop();
                            player->setMedia(QUrl::fromLocalFile(fileDir));
                            player->play();
                            playStatus = true;
                        }
                    }
                }
            }
        }
    }
}

//音频播放状态改变时进行   `
void MainWindow::playChanged(){
//    qDebug()<<player->mediaStatus() <<endl;
//    qDebug()<<player->state()<<endl;
    if( QMediaPlayer::StoppedState==  player->state() && playStatus == true){
        //播放结束时，继续开启语音识别功能
        playStatus = false;

        qDebug()<<"Stop !"<<endl;
        recordNum = 0;
        recordHigh = 0;
        recordLow = 0;
        recordSend = false;
        this->startRecord();

    }
}
