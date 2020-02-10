#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include "figure.h"
#include <QDebug>

class NextFigure : public QWidget
{
    Q_OBJECT
    figure* next;
public:
    explicit NextFigure(QWidget *parent = nullptr);
    ~NextFigure(){};
void paintEvent(QPaintEvent*event);
signals:

public slots:
    void slotNextNewFigure(figure* _next){qDebug()<<"next new figure slot"; next=_next; repaint();}

};

#endif // NEXTFIGURE_H
