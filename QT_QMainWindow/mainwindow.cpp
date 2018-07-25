#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏
    QMenuBar *mBar =  menuBar();
   //添加菜单
    QMenu *pFile = mBar-> addMenu("文件");

    QAction *pNew = pFile ->addAction("新建");

    connect(pNew, &QAction::triggered,
            [=]()
    {
         qDebug() << "新建被按下";
    });

    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("打开");
     //工具栏
    QToolBar *toolBar = addToolBar("toolBar");
    toolBar->addAction(pNew);
    QPushButton *b = new QPushButton(this);
    toolBar->addWidget(b);
    b->setText("bbb");

    connect(b, &QPushButton::clicked,
                  [=]()
    {
        b->setText("123");

    }
            );
    //状态栏
    QStatusBar *sBar = statusBar();
    QLabel *label =new QLabel(this);
    label->setText("Normal text file");
    sBar ->addWidget(label);
    sBar->addWidget(new QLabel("222",this));//从左往右添加
    sBar->addPermanentWidget(new QLabel("333",this));//从左往右添加

    //核心控件
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    //给浮动窗口添加控件
    QTextEdit *textEdit1 = new QTextEdit(this);
    dock->setWidget(textEdit1);
}

MainWindow::~MainWindow()
{

}
