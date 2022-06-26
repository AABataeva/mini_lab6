#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <rect.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QVector<Rect> rect[6];
    int cnt = 0;
    int tempX1, tempY1, tempX2, tempY2;
};
#endif // MAINWINDOW_H
