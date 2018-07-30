#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//界面操作完成

    ui->mybutton->setText("123");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_mybutton_clicked()
{
        static int i = 0;
        ui->stackedWidget->setCurrentIndex(++i % 4);
}
