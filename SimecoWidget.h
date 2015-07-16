#ifndef SIMECOWIDGET_H
#define SIMECOWIDGET_H

#include <QWidget>

#include "ui_SimecoWidget.h"

class SimecoWidget : public QWidget, private Ui::SimecoWidget
{
    Q_OBJECT
public:
    explicit SimecoWidget(QWidget *parent = 0);
    ~SimecoWidget();
};

#endif // SIMECOWIDGET_H
