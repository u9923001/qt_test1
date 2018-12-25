#ifndef UIWIDGET_H
#define UIWIDGET_H

#include <QWidget>

class UiWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UiWidget(QWidget *parent = 0);
private:
    QWidget *_widget;
signals:

public slots:
};

#endif // UIWIDGET_H
