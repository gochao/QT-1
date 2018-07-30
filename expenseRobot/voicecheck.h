#ifndef VOICECHECK_H
#define VOICECHECK_H
#include<QThread>
#include <iostream>
#include <QAudioInput>
#include<QWidget>
#include<QFile>
class QAudioRecorder;
class QTimer;
class VoiceCheck : public QThread
{
    Q_OBJECT
public:
    explicit VoiceCheck(QObject * parent = 0);
    void stop();
private slots:
    void stopRecording();
protected:
    void run();

private:
    volatile bool stopped;
    QFile outputFile;
    QTimer * timer;
    QAudioInput* audio;
};

#endif // VOICECHECK_H
