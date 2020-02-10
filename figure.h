#ifndef FIGURE_H
#define FIGURE_H
#include<QColor>
#include <QPainter>

static QColor col_ar[5]={Qt::green, Qt::red, Qt::blue, Qt::yellow, Qt::cyan};
class figure
{
    QColor ar[3];
  uint m_i, m_j;
    uint m_W;


public:
    figure(int W): m_W(W), m_i(0), m_j(0){}
    void MakeRandomColors();
    void toRight(){m_i++;}
    void toLeft(){m_i--;}
    void setUpIndex(uint i, uint j){m_i=i; m_j=j;}
    void goDown(){m_j++;}
    int getUpX(){ return m_i; }
    int getDownY(){ return m_j+2;}
    int getElementSize(){ return m_W;}
    QColor* getColor(){return ar;}
    void rotateColors(bool b);
    void paintFigure(QPainter&painter);
};

#endif // FIGURE_H
