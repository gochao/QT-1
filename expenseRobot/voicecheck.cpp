#include "voicecheck.h"
#include<QAudioRecorder>
#include <QtGui>
#include <QAudioInput>
#include<QFileDialog>
#include<QTimer>
#include<QDebug>
VoiceCheck::VoiceCheck(QObject * parent):
    QThread(parent)
{
    stopped = false;

}

void VoiceCheck::run(){
    stopped = false;
    outputFile.setFileName("E:\QtApp\test.wav");
    outputFile.open( QIODevice::WriteOnly | QIODevice::Truncate );
    QAudioFormat format;
        // set up the format you want, eg.
        format.setSampleSize(8);
        format.setCodec("audio/pcm");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::UnSignedInt);
        QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
        if (!info.isFormatSupported(format)) {
           qWarning()<<"default format not supported try to use nearest";
           format = info.nearestFormat(format);
        }
        audio = new QAudioInput(format, this);
        QTimer::singleShot(5000, this, SLOT(stopRecording()));
        audio->start(&outputFile);
        // Records audio for 3000ms
         qDebug() <<"record begin!" << endl;

    /*audioRecorder = new QAudioRecorder;
    timer = new QTimer( this );
    connect(timer, SIGNAL(timeout()), this, SLOT(stopVoice()));

    QStringList inputs = audioRecorder->audioInputs();
    audioRecorder->setAudioInput(inputs.at(0));
    audioRecorder->setOutputLocation(QUrl::fromLocalFile("E:\QtApp\test.wav"));
    audioRecorder->record();
    timer->start(50000);*/
}

void VoiceCheck::stopRecording()
 {
   audio->stop();
   outputFile.close();
   delete audio;
   qDebug() <<"record end!" << endl;
 }

void VoiceCheck::stop(){
    stopped = true;

}

/*void VoiceCheck::stopVoice(){
    qDebug()<<"test"<<endl;
    if(timer->isActive()){
        timer->stop();
    }
    audioRecorder->stop();
}*/
