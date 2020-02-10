#include "nextfigure.h"
#include <QPainter>
#include <QColor>

NextFigure::NextFigure(QWidget *parent) : QWidget(parent)
{
next=nullptr;
}

void NextFigure::paintEvent(QPaintEvent*event){
if (next){
 QPainter painter(this);
 painter.translate((rect().width()/2)-next->getElementSize(), rect().topLeft().y());
   next->paintFigure(painter);


}
qDebug()<<"Next Figure Paint event";
};
