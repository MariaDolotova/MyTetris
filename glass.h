#ifndef GLASS_H
#define GLASS_H
#include <QWidget>
#define emptyCell QColor(150,150,150)
#include "figure.h"  // ПРАВИЛЬНОЕ ВКЛЮЧЕНИЕ ХЕДЕРОВ????????????????? Если в хедер glass включить figure.h и одновременно в хедер figure включить glass.h - ОШИБКА!!!!!!!!!!!
static int score=0;
class glass : public QWidget
{
    Q_OBJECT
    static const uint W=25;
    uint timerInterval;
    bool gameOn;
    uint score;
    QVector<QVector<QColor>>glassArray;




    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(uint columns READ columns WRITE setColumns)

    uint m_rows;
    uint m_columns;

figure* cur;
figure* next;
int idTimer;
//int Timer;
bool check;


public:
    explicit glass(QWidget *parent = nullptr);
~glass(){delete cur; delete next;}
uint rows() const
{
    return m_rows;
}

uint columns() const
{
    return m_columns;
}

void clearGlass();

void paintEvent(QPaintEvent*event);
static QColor getEmptyCell(){return emptyCell;}
void acceptColors(int i, int j);
void CheckGlass();
void currentStepComplete(int x, int y);

void keyPressEvent(QKeyEvent*event);
void timerEvent(QTimerEvent*event);

signals:
void signalGlassInit();
void signalNextNewFigure(figure*next);
void signalSetLCD(int);

public slots:
void setRows(uint rows)
{
    m_rows = rows;
}
void setColumns(uint columns)
{
    m_columns = columns;
}

void slotGlassInit();

void slotNewGame();



};



#endif // GLASS_H
