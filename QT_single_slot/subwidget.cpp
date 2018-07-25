#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("小弟");
    b.setParent(this);
    b.setText("切换到主窗口");
    connect(&b, &QPushButton::clicked, this, &SubWidget::sendSlot);
    resize(400,300);
}
void SubWidget::sendSlot()
{
    emit mySignal();
    emit mySignal(250,"我是子窗口！");
}
