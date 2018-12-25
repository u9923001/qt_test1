#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "UiButton.h"
#include <QVBoxLayout>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QStackedWidget>
#include "MouseEvent.h"

typedef struct modelIndex{
    int min;
    int max;
    int size;
}modelIndex;

class MainWindow  : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QList<QStandardItem*> addItem(int row);
    QWidget *_ui;
    QTableView *view;
    QStandardItemModel *itemModel;
    QStandardItemModel *viewModel;
    uint8_t mouseStatus;
    int pastY;
    int nowY;
    int indexNow;
    modelIndex itemIndex;
    modelIndex viewIndex;
public slots:
    void touchPressEvent(QMouseEvent *e);
    void touchMoveEvent(QMouseEvent *e);
    void touchReleaseEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
