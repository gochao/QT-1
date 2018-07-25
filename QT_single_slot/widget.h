#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void mySlot();
    void changeWin();
    void dealSub ();
    void dealSlot (int, QString);


private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    SubWidget w;

};




#endif // WIDGET_H
