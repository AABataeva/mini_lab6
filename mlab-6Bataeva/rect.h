#ifndef RECT_H
#define RECT_H
class QPainter;

class Rect
{
public:
    Rect();
    Rect (int x1, int y1, int x2, int y2);
    void draw(QPainter *painter, int n = 0);
    bool containts(int x, int y);
    Rect intersection(const Rect & r);
    int getX1() const;
    int getX2() const;
    int getY1() const;
    int getY2() const;
private:
    int x1, y1, x2, y2;
};



#endif // RECT_H
