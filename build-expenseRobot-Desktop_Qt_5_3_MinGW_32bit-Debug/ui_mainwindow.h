/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QStackedWidget *mainWidget;
    QWidget *welcome;
    QLabel *welcomeLabel;
    QPushButton *faceBtn;
    QPushButton *idBtn;
    QWidget *face;
    QLabel *faceLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *imageLayout;
    QTextEdit *faceText;
    QWidget *idCord;
    QLabel *faceLabel_2;
    QLabel *infoLabel;
    QWidget *expenseChoice;
    QLabel *expenseChoiceLabel;
    QPushButton *costBtn;
    QPushButton *busiBtn;
    QPushButton *abroadBtn;
    QWidget *busiExpense;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_9;
    QTableWidget *busiBodyTable;
    QPushButton *busiBodyAddBtn;
    QPushButton *busiBodyDelBtn;
    QLabel *expenseChoiceLabel_2;
    QWidget *costExpense;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLabel *expenseChoiceLabel_3;
    QWidget *abroadExpense;
    QLabel *expenseChoiceLabel_4;
    QLabel *label_29;
    QComboBox *comboBox_3;
    QLabel *label_30;
    QLineEdit *lineEdit_27;
    QLabel *label_31;
    QLabel *label_32;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_30;
    QLabel *label_33;
    QLabel *label_34;
    QLineEdit *lineEdit_31;
    QWidget *payInfo;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_13;
    QLabel *expenseChoiceLabel_9;
    QComboBox *comboBox_4;
    QLineEdit *lineEdit_12;
    QLabel *label_35;
    QLineEdit *lineEdit_32;
    QLabel *label_36;
    QLineEdit *lineEdit_33;
    QLabel *label_37;
    QWidget *bill;
    QLabel *expenseChoiceLabel_10;
    QPushButton *fileChooseBtn;
    QTableWidget *billTable;
    QWidget *confirm;
    QLabel *expenseChoiceLabel_11;
    QLabel *label_61;
    QLabel *label_62;
    QLineEdit *lineEdit_54;
    QLineEdit *lineEdit_55;
    QLineEdit *lineEdit_56;
    QLabel *label_63;
    QLabel *label_64;
    QLineEdit *lineEdit_57;
    QTableWidget *busiBodyTable_4;
    QPushButton *confirmBtn;
    QWidget *finish;
    QLabel *expenseChoiceLabel_19;
    QPushButton *continueExpenseBtn;
    QPushButton *logoutBtn;
    QPushButton *lastStepBtn;
    QPushButton *nextStepBtn;
    QLabel *userInfo;
    QWidget *layoutWidget;
    QVBoxLayout *levelLayout;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1269, 776);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        mainWidget = new QStackedWidget(MainWindow);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setGeometry(QRect(140, 100, 1011, 591));
        welcome = new QWidget();
        welcome->setObjectName(QStringLiteral("welcome"));
        welcomeLabel = new QLabel(welcome);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(340, 140, 371, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font.setPointSize(16);
        welcomeLabel->setFont(font);
        welcomeLabel->setAlignment(Qt::AlignCenter);
        faceBtn = new QPushButton(welcome);
        faceBtn->setObjectName(QStringLiteral("faceBtn"));
        faceBtn->setGeometry(QRect(250, 320, 151, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font1.setPointSize(14);
        faceBtn->setFont(font1);
        idBtn = new QPushButton(welcome);
        idBtn->setObjectName(QStringLiteral("idBtn"));
        idBtn->setGeometry(QRect(640, 320, 151, 71));
        idBtn->setFont(font1);
        mainWidget->addWidget(welcome);
        face = new QWidget();
        face->setObjectName(QStringLiteral("face"));
        faceLabel = new QLabel(face);
        faceLabel->setObjectName(QStringLiteral("faceLabel"));
        faceLabel->setGeometry(QRect(320, 20, 371, 61));
        faceLabel->setFont(font);
        faceLabel->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(face);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(270, 80, 481, 341));
        imageLayout = new QHBoxLayout(horizontalLayoutWidget);
        imageLayout->setObjectName(QStringLiteral("imageLayout"));
        imageLayout->setContentsMargins(0, 0, 0, 0);
        faceText = new QTextEdit(face);
        faceText->setObjectName(QStringLiteral("faceText"));
        faceText->setGeometry(QRect(350, 440, 321, 111));
        mainWidget->addWidget(face);
        idCord = new QWidget();
        idCord->setObjectName(QStringLiteral("idCord"));
        faceLabel_2 = new QLabel(idCord);
        faceLabel_2->setObjectName(QStringLiteral("faceLabel_2"));
        faceLabel_2->setGeometry(QRect(310, 40, 371, 61));
        faceLabel_2->setFont(font);
        faceLabel_2->setAlignment(Qt::AlignCenter);
        infoLabel = new QLabel(idCord);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setGeometry(QRect(420, 170, 141, 61));
        infoLabel->setFont(font1);
        infoLabel->setAlignment(Qt::AlignCenter);
        mainWidget->addWidget(idCord);
        expenseChoice = new QWidget();
        expenseChoice->setObjectName(QStringLiteral("expenseChoice"));
        expenseChoiceLabel = new QLabel(expenseChoice);
        expenseChoiceLabel->setObjectName(QStringLiteral("expenseChoiceLabel"));
        expenseChoiceLabel->setGeometry(QRect(320, 10, 371, 61));
        expenseChoiceLabel->setFont(font);
        expenseChoiceLabel->setAlignment(Qt::AlignCenter);
        costBtn = new QPushButton(expenseChoice);
        costBtn->setObjectName(QStringLiteral("costBtn"));
        costBtn->setGeometry(QRect(340, 230, 341, 71));
        costBtn->setFont(font1);
        busiBtn = new QPushButton(expenseChoice);
        busiBtn->setObjectName(QStringLiteral("busiBtn"));
        busiBtn->setGeometry(QRect(340, 120, 341, 71));
        busiBtn->setFont(font1);
        abroadBtn = new QPushButton(expenseChoice);
        abroadBtn->setObjectName(QStringLiteral("abroadBtn"));
        abroadBtn->setGeometry(QRect(340, 330, 341, 71));
        abroadBtn->setFont(font1);
        mainWidget->addWidget(expenseChoice);
        busiExpense = new QWidget();
        busiExpense->setObjectName(QStringLiteral("busiExpense"));
        label_7 = new QLabel(busiExpense);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(290, 70, 71, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_6 = new QLineEdit(busiExpense);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(370, 70, 481, 31));
        label_8 = new QLabel(busiExpense);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(300, 120, 61, 31));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_7 = new QLineEdit(busiExpense);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(370, 120, 261, 31));
        lineEdit_8 = new QLineEdit(busiExpense);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(160, 70, 121, 31));
        label_9 = new QLabel(busiExpense);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(60, 70, 91, 31));
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10 = new QLabel(busiExpense);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 120, 91, 31));
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_9 = new QLineEdit(busiExpense);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(160, 120, 121, 31));
        busiBodyTable = new QTableWidget(busiExpense);
        busiBodyTable->setObjectName(QStringLiteral("busiBodyTable"));
        busiBodyTable->setGeometry(QRect(30, 200, 951, 371));
        busiBodyAddBtn = new QPushButton(busiExpense);
        busiBodyAddBtn->setObjectName(QStringLiteral("busiBodyAddBtn"));
        busiBodyAddBtn->setGeometry(QRect(40, 160, 111, 31));
        busiBodyAddBtn->setFont(font1);
        busiBodyDelBtn = new QPushButton(busiExpense);
        busiBodyDelBtn->setObjectName(QStringLiteral("busiBodyDelBtn"));
        busiBodyDelBtn->setGeometry(QRect(170, 160, 111, 31));
        busiBodyDelBtn->setFont(font1);
        expenseChoiceLabel_2 = new QLabel(busiExpense);
        expenseChoiceLabel_2->setObjectName(QStringLiteral("expenseChoiceLabel_2"));
        expenseChoiceLabel_2->setGeometry(QRect(310, 0, 371, 61));
        expenseChoiceLabel_2->setFont(font);
        expenseChoiceLabel_2->setAlignment(Qt::AlignCenter);
        mainWidget->addWidget(busiExpense);
        costExpense = new QWidget();
        costExpense->setObjectName(QStringLiteral("costExpense"));
        label = new QLabel(costExpense);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 90, 91, 31));
        label->setFont(font2);
        lineEdit = new QLineEdit(costExpense);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 90, 121, 31));
        lineEdit_2 = new QLineEdit(costExpense);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(370, 90, 291, 31));
        label_2 = new QLabel(costExpense);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 90, 51, 31));
        label_2->setFont(font2);
        lineEdit_3 = new QLineEdit(costExpense);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(760, 90, 151, 31));
        label_3 = new QLabel(costExpense);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(690, 90, 91, 31));
        label_3->setFont(font2);
        label_4 = new QLabel(costExpense);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(76, 140, 81, 31));
        label_4->setFont(font2);
        comboBox = new QComboBox(costExpense);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(160, 140, 121, 31));
        lineEdit_4 = new QLineEdit(costExpense);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(370, 140, 291, 31));
        label_5 = new QLabel(costExpense);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 140, 71, 31));
        label_5->setFont(font2);
        label_6 = new QLabel(costExpense);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(690, 140, 91, 31));
        label_6->setFont(font2);
        lineEdit_5 = new QLineEdit(costExpense);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(760, 140, 151, 31));
        expenseChoiceLabel_3 = new QLabel(costExpense);
        expenseChoiceLabel_3->setObjectName(QStringLiteral("expenseChoiceLabel_3"));
        expenseChoiceLabel_3->setGeometry(QRect(310, 10, 371, 61));
        expenseChoiceLabel_3->setFont(font);
        expenseChoiceLabel_3->setAlignment(Qt::AlignCenter);
        mainWidget->addWidget(costExpense);
        abroadExpense = new QWidget();
        abroadExpense->setObjectName(QStringLiteral("abroadExpense"));
        expenseChoiceLabel_4 = new QLabel(abroadExpense);
        expenseChoiceLabel_4->setObjectName(QStringLiteral("expenseChoiceLabel_4"));
        expenseChoiceLabel_4->setGeometry(QRect(320, 10, 371, 61));
        expenseChoiceLabel_4->setFont(font);
        expenseChoiceLabel_4->setAlignment(Qt::AlignCenter);
        label_29 = new QLabel(abroadExpense);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(680, 130, 91, 31));
        label_29->setFont(font2);
        comboBox_3 = new QComboBox(abroadExpense);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(150, 130, 121, 31));
        label_30 = new QLabel(abroadExpense);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(310, 80, 51, 31));
        label_30->setFont(font2);
        lineEdit_27 = new QLineEdit(abroadExpense);
        lineEdit_27->setObjectName(QStringLiteral("lineEdit_27"));
        lineEdit_27->setGeometry(QRect(360, 80, 291, 31));
        label_31 = new QLabel(abroadExpense);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(680, 80, 91, 31));
        label_31->setFont(font2);
        label_32 = new QLabel(abroadExpense);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(280, 130, 71, 31));
        label_32->setFont(font2);
        lineEdit_28 = new QLineEdit(abroadExpense);
        lineEdit_28->setObjectName(QStringLiteral("lineEdit_28"));
        lineEdit_28->setGeometry(QRect(750, 80, 151, 31));
        lineEdit_29 = new QLineEdit(abroadExpense);
        lineEdit_29->setObjectName(QStringLiteral("lineEdit_29"));
        lineEdit_29->setGeometry(QRect(750, 130, 151, 31));
        lineEdit_30 = new QLineEdit(abroadExpense);
        lineEdit_30->setObjectName(QStringLiteral("lineEdit_30"));
        lineEdit_30->setGeometry(QRect(150, 80, 121, 31));
        label_33 = new QLabel(abroadExpense);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(66, 130, 81, 31));
        label_33->setFont(font2);
        label_34 = new QLabel(abroadExpense);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(50, 80, 91, 31));
        label_34->setFont(font2);
        lineEdit_31 = new QLineEdit(abroadExpense);
        lineEdit_31->setObjectName(QStringLiteral("lineEdit_31"));
        lineEdit_31->setGeometry(QRect(360, 130, 291, 31));
        mainWidget->addWidget(abroadExpense);
        payInfo = new QWidget();
        payInfo->setObjectName(QStringLiteral("payInfo"));
        label_11 = new QLabel(payInfo);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(320, 150, 91, 31));
        label_11->setFont(font2);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_12 = new QLabel(payInfo);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(300, 200, 111, 31));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_10 = new QLineEdit(payInfo);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(420, 300, 271, 31));
        lineEdit_11 = new QLineEdit(payInfo);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(420, 200, 271, 31));
        label_13 = new QLabel(payInfo);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(330, 250, 81, 31));
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_14 = new QLabel(payInfo);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(280, 300, 131, 31));
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_13 = new QLineEdit(payInfo);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(420, 250, 271, 31));
        expenseChoiceLabel_9 = new QLabel(payInfo);
        expenseChoiceLabel_9->setObjectName(QStringLiteral("expenseChoiceLabel_9"));
        expenseChoiceLabel_9->setGeometry(QRect(330, 20, 371, 61));
        expenseChoiceLabel_9->setFont(font);
        expenseChoiceLabel_9->setAlignment(Qt::AlignCenter);
        comboBox_4 = new QComboBox(payInfo);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(420, 150, 271, 31));
        lineEdit_12 = new QLineEdit(payInfo);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(420, 350, 271, 31));
        label_35 = new QLabel(payInfo);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(240, 350, 171, 31));
        label_35->setFont(font2);
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_32 = new QLineEdit(payInfo);
        lineEdit_32->setObjectName(QStringLiteral("lineEdit_32"));
        lineEdit_32->setGeometry(QRect(420, 400, 271, 31));
        label_36 = new QLabel(payInfo);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(280, 400, 131, 31));
        label_36->setFont(font2);
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_33 = new QLineEdit(payInfo);
        lineEdit_33->setObjectName(QStringLiteral("lineEdit_33"));
        lineEdit_33->setGeometry(QRect(420, 450, 271, 31));
        label_37 = new QLabel(payInfo);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(280, 450, 131, 31));
        label_37->setFont(font2);
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mainWidget->addWidget(payInfo);
        bill = new QWidget();
        bill->setObjectName(QStringLiteral("bill"));
        expenseChoiceLabel_10 = new QLabel(bill);
        expenseChoiceLabel_10->setObjectName(QStringLiteral("expenseChoiceLabel_10"));
        expenseChoiceLabel_10->setGeometry(QRect(330, 0, 371, 61));
        expenseChoiceLabel_10->setFont(font);
        expenseChoiceLabel_10->setAlignment(Qt::AlignCenter);
        fileChooseBtn = new QPushButton(bill);
        fileChooseBtn->setObjectName(QStringLiteral("fileChooseBtn"));
        fileChooseBtn->setGeometry(QRect(460, 60, 111, 31));
        fileChooseBtn->setFont(font1);
        billTable = new QTableWidget(bill);
        if (billTable->columnCount() < 8)
            billTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        billTable->setObjectName(QStringLiteral("billTable"));
        billTable->setGeometry(QRect(90, 140, 831, 311));
        mainWidget->addWidget(bill);
        confirm = new QWidget();
        confirm->setObjectName(QStringLiteral("confirm"));
        expenseChoiceLabel_11 = new QLabel(confirm);
        expenseChoiceLabel_11->setObjectName(QStringLiteral("expenseChoiceLabel_11"));
        expenseChoiceLabel_11->setGeometry(QRect(320, 0, 371, 61));
        expenseChoiceLabel_11->setFont(font);
        expenseChoiceLabel_11->setAlignment(Qt::AlignCenter);
        label_61 = new QLabel(confirm);
        label_61->setObjectName(QStringLiteral("label_61"));
        label_61->setGeometry(QRect(30, 60, 91, 31));
        label_61->setFont(font2);
        label_61->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_62 = new QLabel(confirm);
        label_62->setObjectName(QStringLiteral("label_62"));
        label_62->setGeometry(QRect(30, 110, 91, 31));
        label_62->setFont(font2);
        label_62->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_54 = new QLineEdit(confirm);
        lineEdit_54->setObjectName(QStringLiteral("lineEdit_54"));
        lineEdit_54->setGeometry(QRect(340, 110, 261, 31));
        lineEdit_55 = new QLineEdit(confirm);
        lineEdit_55->setObjectName(QStringLiteral("lineEdit_55"));
        lineEdit_55->setGeometry(QRect(130, 110, 121, 31));
        lineEdit_56 = new QLineEdit(confirm);
        lineEdit_56->setObjectName(QStringLiteral("lineEdit_56"));
        lineEdit_56->setGeometry(QRect(130, 60, 121, 31));
        label_63 = new QLabel(confirm);
        label_63->setObjectName(QStringLiteral("label_63"));
        label_63->setGeometry(QRect(260, 60, 71, 31));
        label_63->setFont(font2);
        label_63->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_64 = new QLabel(confirm);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setGeometry(QRect(270, 110, 61, 31));
        label_64->setFont(font2);
        label_64->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_57 = new QLineEdit(confirm);
        lineEdit_57->setObjectName(QStringLiteral("lineEdit_57"));
        lineEdit_57->setGeometry(QRect(340, 60, 481, 31));
        busiBodyTable_4 = new QTableWidget(confirm);
        busiBodyTable_4->setObjectName(QStringLiteral("busiBodyTable_4"));
        busiBodyTable_4->setGeometry(QRect(20, 150, 951, 371));
        confirmBtn = new QPushButton(confirm);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        confirmBtn->setGeometry(QRect(430, 540, 111, 31));
        confirmBtn->setFont(font1);
        mainWidget->addWidget(confirm);
        finish = new QWidget();
        finish->setObjectName(QStringLiteral("finish"));
        expenseChoiceLabel_19 = new QLabel(finish);
        expenseChoiceLabel_19->setObjectName(QStringLiteral("expenseChoiceLabel_19"));
        expenseChoiceLabel_19->setGeometry(QRect(300, 130, 371, 61));
        expenseChoiceLabel_19->setFont(font);
        expenseChoiceLabel_19->setAlignment(Qt::AlignCenter);
        continueExpenseBtn = new QPushButton(finish);
        continueExpenseBtn->setObjectName(QStringLiteral("continueExpenseBtn"));
        continueExpenseBtn->setGeometry(QRect(240, 360, 111, 31));
        continueExpenseBtn->setFont(font1);
        logoutBtn = new QPushButton(finish);
        logoutBtn->setObjectName(QStringLiteral("logoutBtn"));
        logoutBtn->setGeometry(QRect(600, 360, 111, 31));
        logoutBtn->setFont(font1);
        mainWidget->addWidget(finish);
        lastStepBtn = new QPushButton(MainWindow);
        lastStepBtn->setObjectName(QStringLiteral("lastStepBtn"));
        lastStepBtn->setGeometry(QRect(310, 690, 151, 71));
        lastStepBtn->setFont(font1);
        nextStepBtn = new QPushButton(MainWindow);
        nextStepBtn->setObjectName(QStringLiteral("nextStepBtn"));
        nextStepBtn->setGeometry(QRect(870, 690, 151, 71));
        nextStepBtn->setFont(font1);
        userInfo = new QLabel(MainWindow);
        userInfo->setObjectName(QStringLiteral("userInfo"));
        userInfo->setGeometry(QRect(150, 50, 371, 61));
        userInfo->setFont(font);
        userInfo->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(MainWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(860, 50, 231, 41));
        levelLayout = new QVBoxLayout(layoutWidget);
        levelLayout->setObjectName(QStringLiteral("levelLayout"));
        levelLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(MainWindow);

        mainWidget->setCurrentIndex(9);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Form", 0));
        welcomeLabel->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\212\245\351\224\200\346\234\272\345\231\250\344\272\272\357\274\214\350\257\267\351\200\211\346\213\251\351\252\214\350\257\201\346\226\271\345\274\217", 0));
        faceBtn->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\350\257\206\345\210\253", 0));
        idBtn->setText(QApplication::translate("MainWindow", "\350\272\253\344\273\275\350\257\201\351\252\214\350\257\201", 0));
        faceLabel->setText(QApplication::translate("MainWindow", "\346\255\243\345\234\250\350\277\233\350\241\214\344\272\272\350\204\270\350\257\206\345\210\253", 0));
        faceLabel_2->setText(QApplication::translate("MainWindow", "\346\255\243\345\234\250\350\277\233\350\241\214\350\272\253\344\273\275\350\257\201\350\257\206\345\210\253", 0));
        infoLabel->setText(QString());
        expenseChoiceLabel->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\346\212\245\351\224\200\347\261\273\345\210\253", 0));
        costBtn->setText(QApplication::translate("MainWindow", "\350\264\271\347\224\250\346\212\245\351\224\200\345\215\225", 0));
        busiBtn->setText(QApplication::translate("MainWindow", "\345\267\256\346\227\205\346\212\245\351\224\200\345\215\225", 0));
        abroadBtn->setText(QApplication::translate("MainWindow", "\345\207\272\345\233\275\346\212\245\351\224\200\345\215\225", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\207\272\345\267\256\344\272\213\347\224\261\357\274\232", 0));
        label_8->setText(QApplication::translate("MainWindow", "\345\200\237\346\254\276\345\215\225\357\274\232", 0));
        lineEdit_7->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "\347\273\217\345\212\236\344\272\272\351\203\250\351\227\250\357\274\232", 0));
        label_10->setText(QApplication::translate("MainWindow", "\346\224\257\345\207\272\351\241\271\347\233\256\357\274\232", 0));
        busiBodyAddBtn->setText(QApplication::translate("MainWindow", "\345\242\236\350\241\214", 0));
        busiBodyDelBtn->setText(QApplication::translate("MainWindow", "\345\210\240\350\241\214", 0));
        expenseChoiceLabel_2->setText(QApplication::translate("MainWindow", "\345\267\256\346\227\205\346\212\245\351\224\200\345\215\225", 0));
        label->setText(QApplication::translate("MainWindow", "\347\273\217\345\212\236\344\272\272\351\203\250\351\227\250\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\347\224\250\351\200\224\357\274\232", 0));
        lineEdit_3->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\345\200\237\346\254\276\345\215\225\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\350\264\271\347\224\250\347\261\273\345\236\213\357\274\232", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\231\256\351\200\232\350\264\271\347\224\250", 0)
         << QApplication::translate("MainWindow", "\345\276\200\346\235\245\346\254\276", 0)
         << QApplication::translate("MainWindow", "\346\215\220\350\265\240\346\224\257\345\207\272", 0)
         << QApplication::translate("MainWindow", "\346\225\231\345\255\246", 0)
         << QApplication::translate("MainWindow", "\350\264\242\346\224\277", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "\345\220\210\345\220\214\345\220\215\347\247\260\357\274\232", 0));
        label_6->setText(QApplication::translate("MainWindow", "\345\220\210\345\220\214\345\217\267\357\274\232", 0));
        lineEdit_5->setText(QString());
        expenseChoiceLabel_3->setText(QApplication::translate("MainWindow", "\350\264\271\347\224\250\346\212\245\351\224\200\345\215\225", 0));
        expenseChoiceLabel_4->setText(QApplication::translate("MainWindow", "\345\207\272\345\233\275\346\212\245\351\224\200\345\215\225", 0));
        label_29->setText(QApplication::translate("MainWindow", "\345\220\210\345\220\214\345\217\267\357\274\232", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\231\256\351\200\232\350\264\271\347\224\250", 0)
         << QApplication::translate("MainWindow", "\345\276\200\346\235\245\346\254\276", 0)
         << QApplication::translate("MainWindow", "\346\215\220\350\265\240\346\224\257\345\207\272", 0)
         << QApplication::translate("MainWindow", "\346\225\231\345\255\246", 0)
         << QApplication::translate("MainWindow", "\350\264\242\346\224\277", 0)
        );
        label_30->setText(QApplication::translate("MainWindow", "\347\224\250\351\200\224\357\274\232", 0));
        label_31->setText(QApplication::translate("MainWindow", "\345\200\237\346\254\276\345\215\225\357\274\232", 0));
        label_32->setText(QApplication::translate("MainWindow", "\345\220\210\345\220\214\345\220\215\347\247\260\357\274\232", 0));
        lineEdit_28->setText(QString());
        lineEdit_29->setText(QString());
        label_33->setText(QApplication::translate("MainWindow", "\350\264\271\347\224\250\347\261\273\345\236\213\357\274\232", 0));
        label_34->setText(QApplication::translate("MainWindow", "\347\273\217\345\212\236\344\272\272\351\203\250\351\227\250\357\274\232", 0));
        label_11->setText(QApplication::translate("MainWindow", "\346\224\257\344\273\230\346\226\271\345\274\217\357\274\232", 0));
        label_12->setText(QApplication::translate("MainWindow", "\346\224\266\346\254\276\344\272\272/\345\215\225\344\275\215\357\274\232", 0));
        lineEdit_10->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "\346\211\200\345\261\236\351\223\266\350\241\214\357\274\232", 0));
        label_14->setText(QApplication::translate("MainWindow", "\345\205\267\344\275\223\345\274\200\346\210\267\350\241\214\345\220\215\347\247\260\357\274\232", 0));
        expenseChoiceLabel_9->setText(QApplication::translate("MainWindow", "\346\224\257\344\273\230\344\277\241\346\201\257", 0));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\216\260\351\207\221\346\224\257\344\273\230", 0)
         << QApplication::translate("MainWindow", "\346\261\207\346\254\276", 0)
         << QApplication::translate("MainWindow", "\346\224\257\347\245\250\346\224\257\344\273\230", 0)
         << QApplication::translate("MainWindow", "\345\247\224\346\211\230\344\273\230\346\254\276", 0)
         << QApplication::translate("MainWindow", "\346\260\221\345\217\243\346\212\200\346\234\257\344\270\223\346\210\267", 0)
         << QApplication::translate("MainWindow", "\345\206\205\351\203\250\350\275\254\350\264\246", 0)
        );
        lineEdit_12->setText(QString());
        label_35->setText(QApplication::translate("MainWindow", "\346\224\266\346\254\276\344\272\272/\345\215\225\344\275\215\351\223\266\350\241\214\345\215\241\345\217\267\357\274\232", 0));
        lineEdit_32->setText(QString());
        label_36->setText(QApplication::translate("MainWindow", "\351\207\221\351\242\235\357\274\232", 0));
        lineEdit_33->setText(QString());
        label_37->setText(QApplication::translate("MainWindow", "\345\244\207\346\263\250\357\274\232", 0));
        expenseChoiceLabel_10->setText(QApplication::translate("MainWindow", "\347\245\250\346\215\256\345\275\225\345\205\245", 0));
        fileChooseBtn->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", 0));
        QTableWidgetItem *___qtablewidgetitem = billTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\347\245\250\346\215\256\347\261\273\345\210\253", 0));
        QTableWidgetItem *___qtablewidgetitem1 = billTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\347\245\250\346\215\256\345\220\215\347\233\256", 0));
        QTableWidgetItem *___qtablewidgetitem2 = billTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\347\245\250\346\215\256\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = billTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\347\245\250\346\215\256\344\275\277\347\224\250\344\272\272", 0));
        QTableWidgetItem *___qtablewidgetitem4 = billTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\347\245\250\346\215\256\351\207\221\351\242\235", 0));
        QTableWidgetItem *___qtablewidgetitem5 = billTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\345\247\213\345\217\221\347\253\231", 0));
        QTableWidgetItem *___qtablewidgetitem6 = billTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\347\273\210\347\202\271\347\253\231", 0));
        QTableWidgetItem *___qtablewidgetitem7 = billTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\345\205\266\344\273\226\344\277\241\346\201\257", 0));
        expenseChoiceLabel_11->setText(QApplication::translate("MainWindow", "\344\277\241\346\201\257\347\241\256\350\256\244", 0));
        label_61->setText(QApplication::translate("MainWindow", "\347\273\217\345\212\236\344\272\272\351\203\250\351\227\250\357\274\232", 0));
        label_62->setText(QApplication::translate("MainWindow", "\346\224\257\345\207\272\351\241\271\347\233\256\357\274\232", 0));
        lineEdit_54->setText(QString());
        label_63->setText(QApplication::translate("MainWindow", "\345\207\272\345\267\256\344\272\213\347\224\261\357\274\232", 0));
        label_64->setText(QApplication::translate("MainWindow", "\345\200\237\346\254\276\345\215\225\357\274\232", 0));
        confirmBtn->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244\345\271\266\346\217\220\344\272\244", 0));
        expenseChoiceLabel_19->setText(QApplication::translate("MainWindow", "\346\212\245\351\224\200\345\256\214\346\210\220\357\274\214\350\260\242\350\260\242\344\275\277\347\224\250\357\274\201", 0));
        continueExpenseBtn->setText(QApplication::translate("MainWindow", "\347\273\247\347\273\255\346\212\245\351\224\200", 0));
        logoutBtn->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        lastStepBtn->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\346\255\245", 0));
        nextStepBtn->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\346\255\245", 0));
        userInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
