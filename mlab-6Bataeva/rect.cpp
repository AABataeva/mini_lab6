#include "rect.h"
#include <QPainter>
Rect::Rect()
    : Rect(0, 0, 0, 0)
{

}

Rect::Rect(int x1, int y1, int x2, int y2)
{
    this->x1 =(x1<x2 ? x1 : x2);
    this->y1 =(y1<y2 ? y1 : y2);
    this->x2 =(x1>x2 ? x1 : x2);
    this->y2 =(y1>y2 ? y1 : y2);
}

void Rect::draw(QPainter *painter, int n)
{
    QColor color[] ={Qt::red, Qt::yellow, Qt::green, Qt::blue, Qt::black};
    painter->setBrush(n == 0 ? QBrush() : QBrush(color[n-1]));
    painter->drawRect(x1, y1, x2-x1, y2-y1);
}

bool Rect::containts(int x, int y)
{
    return (x>=x1 && x<= x2 && y>=y1 && y<=y2 );
}

Rect Rect::intersection(const Rect &r)
{
    int xl =(x1>r.x1 ? x1 : r.x1), xr = (x2<r.x2 ? x2 : r.x2);
    int yl =(y1>r.y1 ? y1 : r.y1), yr = (y2<r.y2 ? y2 : r.y2);
    bool valid  = (xr >= xl) && (yr >= yl);
    return valid ? Rect(xl, yl, xr, yr) : Rect();
}
int Rect::getX1() const
{
    return x1;
}

int Rect::getX2() const
{
    return x2;
}

int Rect::getY1() const
{
    return y1;
}

int Rect::getY2() const
{
    return y2;
}

