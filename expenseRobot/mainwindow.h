#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include<QMediaRecorder>
#include "voicecheck.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QTimer;
class QByteArray;
class QNetworkAccessManager;
class QNetworkReply;
class QAudioRecorder;
class QAudioProbe;
class QAudioBuffer;
class QNetworkRequest;
class QMediaPlayer;
class QAudioLevel;
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QNetworkRequest getHttpRequest(QString url);
    QByteArray  Image_To_Base64(QString ImgPath);
    void toLastStep();
    void toNextStep();
    void instructionExp(QString instruction);
private:
    void startRecord();
    void stopRecord();
    void setRecord();
    void sendPlayText(QByteArray text);

private slots:
    void on_faceBtn_clicked();

    void on_idBtn_clicked();

    void faceCheck();

    void faceReply(QNetworkReply * reply);
    void billReply(QNetworkReply * reply);
    void voiceReply(QNetworkReply * reply);
    void playReply(QNetworkReply * reply);
    void sendPhoto(int id,QImage image);
    void on_lastStepBtn_clicked();

    void on_nextStepBtn_clicked();

    void on_mainWidget_currentChanged(int arg1);

    void on_costBtn_clicked();

    void on_busiBtn_clicked();

    void on_abroadBtn_clicked();

    void on_busiBodyAddBtn_clicked();

    void on_busiBodyDelBtn_clicked();

    void on_fileChooseBtn_clicked();

    void on_continueExpenseBtn_clicked();

    void on_logoutBtn_clicked();

    void on_confirmBtn_clicked();

     void processBuffer(const QAudioBuffer&);

     void playChanged();

private:
    Ui::MainWindow *ui;
    QCamera * camera;
    QCameraViewfinder * viewfinder;
    QCameraImageCapture * imageCapture;
    QList<QByteArray > list;
    QNetworkAccessManager * manager;
    QTimer *timer;
    QAudioRecorder *audioRecorder;
    QAudioProbe *probe;
    QMediaPlayer * player;
    QList<QAudioLevel*> audioLevels;
    int facetime;
    int currentIndex;
    int expenseType;//报销类型
    bool busiTalble;
    int recordNum;//音频样本数量
    int recordLow;//低音音频样本数量
    int recordHigh;//高音样本数量
    bool recordSend;//是否发送语音指令
    bool playStatus;//是否播放过音频文件
    //VoiceCheck *voiceThread;
};

#endif // MAINWINDOW_H
