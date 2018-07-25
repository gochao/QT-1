#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");
    QAction *p1 = menu->addAction("模态对话框");
    connect(p1, &QAction::triggered,

        [=]()
            {
             QDialog dlg;
             dlg.exec();//产生中断
             qDebug() << "111111";
            }
    );

    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2, &QAction::triggered,

            [=]()
    {
//        dlg.show();
//        qDebug() << "2222";


        QDialog *p = new QDialog(this);
        p->setAttribute(Qt::WA_DeleteOnClose);//内存泄漏
        p->show();
    }
    );

    QAction *p3 = menu->addAction("关于对话框");
    connect(p3, &QAction::triggered,

            [=]()
        {
            QMessageBox::about(this, "关于", "关于Qt");
        }
    );

    QAction *p4 = menu->addAction("问题对话框");
    connect(p4, &QAction::triggered,

            [=]()
    {
       int ret = QMessageBox::question(this, "问题", "are you ok?",
                                       QMessageBox::Yes|
                                       QMessageBox::Cancel
                                       );
       switch (ret) {
       case QMessageBox::Yes:
            qDebug() << "i am ok";
           break;
       case QMessageBox::Cancel:
           qDebug() << "i am bad";
           break;
       default:
           break;
       }
    }
    );

    //文件对话框
    QAction *p5 = menu->addAction("文件对话框");
    connect(p5, &QAction::triggered,

            [=]()
        {
            QString path = QFileDialog::getOpenFileName(
                        this,
                        "打开",
                        "../",  //上一级路径
                        "souce(*.cpp *.h);;Text(*.txt *.md);;all(*.*)"
                        );
            qDebug() << path;
        }
    );

}


MainWindow::~MainWindow()
{

}
