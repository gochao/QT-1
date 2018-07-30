#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->myButton->setText("123");
    connect(ui->myButton, &QPushButton::clicked, this, &MainWindow::close);

    QString str = ui->lineEdit->text();
    qDebug() << str;

    ui->lineEdit->setText("xxxxxsss");

    ui->labelText->setText("xxxxeeee");
//    ui->labelImage->setPixmap(QPixmap("OnePiece.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


