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
    int indexMax;
    int indexMin;
    int modelIndexStart;
    int modelIndexEnd;
    int modelMax;
    int modelMin;
public slots:
    void touchPressEvent(QMouseEvent *e);
    void touchMoveEvent(QMouseEvent *e);
    void touchReleaseEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
