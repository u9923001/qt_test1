#include "mainwindow.h"


#define BgColor(var) "background-color:"#var";"

MainWindow::MainWindow(QWidget *parent)
{
    _ui = new QWidget();
    _ui->setFixedSize(800,480);

    itemModel = new QStandardItemModel();
    itemIndex.min = 0;
    itemIndex.size = 20;
    for(int row=0;row<itemIndex.size;row++){
        QList<QStandardItem*> itemList;
        for(int column=0;column<5;column++){
            QStandardItem *item = new QStandardItem();
            item->setText(QString("(%0,%1)").arg(row).arg(column));
            item->setFlags(item->flags() &~Qt::ItemIsEnabled);
            itemList.append(item);
        }
        itemModel->appendRow(itemList);
        itemIndex.max = row;
    }

    view = new QTableView;
    viewModel = new QStandardItemModel();
    view->verticalHeader()->hide();
    view->horizontalHeader()->hide();
    view->setModel(viewModel);
    view->show();

    viewIndex.min = 0;
    viewIndex.size = 6;
    for(int row=0;row<viewIndex.size;row++){
        QList<QStandardItem*> itemList;
        for(int column=0;column<5;column++){
            QStandardItem *item = itemModel->item(row,column)->clone();
            itemList.append(item);
        }
        viewModel->appendRow(itemList);
        view->setRowHeight(row, 80);
        viewIndex.max = row;
    }

    indexNow = 0;

    QWidget *widget2 = new QWidget();
    widget2->setFixedSize(this->size());
    widget2->setStyleSheet(BgColor(rgba(225,125,255,0.7)));

    MouseEvent *me = new MouseEvent(widget2);
    me->setFixedSize(this->size());
    me->setStyleSheet(BgColor(rgba(225,125,255,0.7)));
    connect(me,SIGNAL(touchPressEvent(QMouseEvent *)),this,SLOT(touchPressEvent(QMouseEvent *)));
    connect(me,SIGNAL(touchMoveEvent(QMouseEvent *)),this,SLOT(touchMoveEvent(QMouseEvent *)));
    connect(me,SIGNAL(touchReleaseEvent(QMouseEvent *)),this,SLOT(touchReleaseEvent(QMouseEvent *)));

    QStackedWidget *stackWidget = new QStackedWidget();
    stackWidget->addWidget(view);
    stackWidget->addWidget(me);
    me->show();
    me->raise();

    QVBoxLayout *mainLayout = new QVBoxLayout(_ui);
    mainLayout->addWidget(stackWidget);
    _ui->show();
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::touchPressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton){
        qDebug()<<"left click";
        mouseStatus = 1;
    }
    if(e->button()==Qt::RightButton){
        qDebug()<<"right click ";
    }

    qDebug()<<"mousePress"<<e->x()<<" "<<e->y();
}

QList<QStandardItem*> MainWindow::addItem(int row){
    QList<QStandardItem*> itemList;
    for(int column=0;column<5;column++){
        QStandardItem *item = itemModel->item(row,column)->clone();
        itemList.append(item);
    }
    return itemList;
}

void MainWindow::touchMoveEvent(QMouseEvent *e)
{
    if(mouseStatus){
        nowY = e->y();
        int y = nowY -pastY;
        pastY = nowY;
        if(y>0){
            if(++indexNow>=viewIndex.size-1){
                if(viewIndex.max+1 <= itemIndex.max){
                    viewIndex.min++;
                    viewIndex.max++;

                    viewModel->removeRow(0);
                    viewModel->appendRow(addItem(viewIndex.max));
                    view->setRowHeight(viewIndex.size-1, 80);
                }else{
                    indexNow--;
                }
            }
            qDebug()<<"down"<<indexNow;
            view->scrollTo(view->model()->index(indexNow,0));
        }else{
            if(--indexNow>=viewIndex.min){
                if(viewIndex.min-1 >= itemIndex.min){
                    viewIndex.min--;
                    viewIndex.max--;

                    viewModel->removeRow(viewIndex.size-1);
                    viewModel->insertRow(0,addItem(viewIndex.min));
                    view->setRowHeight(0, 80);
                }
            }else{
                indexNow++;
            }
            qDebug()<<"up"<<indexNow;
            view->scrollTo(view->model()->index(indexNow,0));
        }

        //qDebug()<<"mouseMove"<<e->x()<<" "<<e->y()<<" "<<y;
    }
}

void MainWindow::touchReleaseEvent(QMouseEvent *e)
{
    mouseStatus = 0;
    qDebug()<<"mouseRelease"<<e->x()<<" "<<e->y();
}
