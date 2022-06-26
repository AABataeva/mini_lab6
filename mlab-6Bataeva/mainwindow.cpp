#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->modifiers()&Qt::ControlModifier) {
         cnt++;
            if(cnt%2 == 1){
                tempX1 = event->x();
                tempY1 = event->y();
            }
            else if(cnt%2 == 0){
                tempX2 = event->x();
                tempY2 = event->y();
                Rect *r;
                r= new Rect(tempX1, tempY1,  event->x(), event->y());
                rect[0].append(*r);
                tempX1 = r->getX1(); tempX2 = r->getX2();
                tempY1 = r->getY1(); tempY2 = r->getY2();
            }
            else {
                Rect *r;
                r = new Rect(tempX1, tempY1,  event->x(), event->y());
                rect[0].append(*r);
            }
            repaint();
        }

    if(!(event->modifiers()&Qt::ControlModifier)) {
        QVector<Rect> counter;                                                                         //счетчик пересечения
        for(Rect r: rect[0])
            if(r.containts(event->x(), event->y()))
                counter.append(r);
       if(counter.size()> 1) {
           Rect rx = counter[0];
           for(int i = 1; i< counter.size(); i++)
               rx = rx.intersection(counter[i]);
          int n = counter.size();
           rect[n-1].append(rx);
       }
    }
     repaint();
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for(int i = 0; i < 6; i++)
        for(Rect r: rect[i])
            r.draw(&painter, i);
}
