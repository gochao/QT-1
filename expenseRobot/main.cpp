#include "mainwindow.h"
#include <QApplication>
#include<QSplitter>
#include<QListWidget>
#include<QTextCodec>
#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    MainWindow * mainWindow = new MainWindow(0);
    mainWindow->show();


    return a.exec();
}
