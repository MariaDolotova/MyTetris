#include "glass.h"
#include <QDebug>
#include <QPainter>
#include<QKeyEvent>
#include<QMap>
#include<QMessageBox>


glass::glass(QWidget *parent) : QWidget(parent)
{

    timerInterval=0;
    gameOn=false;
    score=0;
    m_rows=0;
    m_columns=0;

    cur=new figure(W);
    next=new figure(W);
    qDebug()<<"next figure x: "<<next->getUpX();
    QObject::connect(this, SIGNAL(signalGlassInit()), SLOT(slotGlassInit()), Qt::QueuedConnection);

    emit signalGlassInit();
    qDebug()<<"Init glass";

}
//
// clear the glass
//
void glass::clearGlass(){

     for(int i=0; i<m_rows; i++){glassArray[i].fill(emptyCell, m_columns);}
  //  foreach(QVector<QColor> c, glassArray){c.fill(QColor(0,1,0), c.size());} // foreach не работает!!!!!!!!!!!!!!!!!!!!!!!!
}


//
// creating the glass
//
void glass::slotGlassInit(){
    glassArray.resize(m_rows);
    for(int i=0; i<m_rows; i++){glassArray[i].resize(m_columns);}
    clearGlass();
    QSize s(W*m_columns, W*m_rows);
    setFixedSize(s);
    timerInterval=500;
    repaint();

 }

void glass::paintEvent(QPaintEvent*event){

    uint x=1, y=1;
    QPainter painter(this);

    foreach(QVector<QColor> c, glassArray){

        foreach(QColor col, c){

            painter.fillRect(x,y, W-1,W-1,col);
            x+=W;

        }
        x=1;
        y+=W;
    }

        if(gameOn) // moving the figure down
        {
       cur->paintFigure(painter);
        }


};


//
// start new game
//
void glass::slotNewGame(){
gameOn=true;
clearGlass();
cur->setUpIndex(m_columns/2, 0);
cur->MakeRandomColors();
next->MakeRandomColors();
emit(signalNextNewFigure(next));
idTimer=startTimer(timerInterval);
setFocus();
repaint();
}


//
// recording of new colors into array
//
void glass::acceptColors(int i, int j){


    glassArray[j-2][i]=cur->getColor()[0];
    glassArray[j-1][i]=cur->getColor()[1];
    glassArray[j][i]=cur->getColor()[2];

};



//
// adding of new figure, analysing and dropping the sets
//
void glass::currentStepComplete(int x, int y){

    acceptColors(x,y);
    check=true;
    figure*tmp=cur;
    cur=next;
    next=tmp;
    cur->setUpIndex(m_columns/2, 0);
    next->setUpIndex(0, 0);
    next->MakeRandomColors();
    emit(signalNextNewFigure(next));


};


void glass::timerEvent(QTimerEvent*event){
    if(check){CheckGlass();}

else{
    if(glassArray[2][m_columns/2]!=emptyCell){    // stop the game if there is no space left for fugure to fall
        killTimer(idTimer);
        QMessageBox::information(this,"Information","Game over");
        return;
    }

    int x=cur->getUpX();
    int y=cur->getDownY();

    if(y==m_rows-1||glassArray[y+1][x]!=emptyCell){// glassArray[y+1] - не будет выхода за границы, т.к. при достижении низа - первое условие будет true и второе не будет вычисляться
    currentStepComplete(x, y);}
    else{

    cur->goDown();

        }
}

repaint();

};



//
//check the glass and drop the sets
//

void glass::CheckGlass()  {

bool b=false;
QMap<int, QList<int>> m;
QMap<int, QList<int>> m1;


{qDebug()<<"VERTICAL";
    for(int k=0; k<=m_columns-1; k++){
int start=0;
int end=1;

while(end<m_rows)  {

    if(glassArray[start][k]==emptyCell){
        if(end==m_rows-1&&glassArray[end][k]!=emptyCell)
        {m[k].append(m_rows-1);
      }
        start++; end++;
    }
else{


        if (glassArray[start][k]==glassArray[end][k]&&end<m_rows-1){end++;}
           else{

               int delta=end-start;
        if(end==m_rows-1&&glassArray[start][k]==glassArray[end][k]){delta++; end++;}
        if(end==m_rows-1&&glassArray[start][k]!=glassArray[end][k])
        {
            m[k].append(m_rows-1);}
        if(delta<=2)
        {  for(int i=start; i<end; i++){

                m[k].append(i);

                }}
        else{b=true; score+=delta; }

        start=end;
        end=start+1;

     }
}
};

    }

}


{ qDebug()<<"HORIZONTAL";

for(int k=m_rows-1; k>=0; k--){
int start=0;
int end=1;

while(end<m_columns)  {

if(glassArray[k][start]==emptyCell){
    if(end==m_columns-1&&glassArray[k][end]!=emptyCell)
    {

        if (m.contains(m_columns-1)){

           if( m[m_columns-1].contains(k))
            {
                m1[m_columns-1].append(k);

            }
        }

}
    start++; end++;}
else{
    if (glassArray[k][start]==glassArray[k][end]&&end<m_columns-1){


       end++;}
    else{

        int delta=end-start;

 if(end==m_columns-1&&glassArray[k][start]==glassArray[k][end]){delta++; end++;}
 if(end==m_columns-1&&glassArray[k][start]!=glassArray[k][end]){

     if (m.contains(m_columns-1)){

        if( m[m_columns-1].contains(k))
         {
             m1[m_columns-1].append(k);

         }
     }

 }
        if(delta<=2)
        {
            for(int i=start; i<end; i++){

                if (m.contains(i)){

                   if( m[i].contains(k))
                    {
                        m1[i].append(k);

                    }
                }


            }
        }
        else{b=true; score+=delta; }

        start=end;
        end=start+1;

     }

};

  }

}
}



    if(b){

        for (int i=0; i<m_columns;i++){

            if (!m1.contains(i)){

                for(int j=0; j<m_rows; j++)
                {
                    glassArray[j][i]=emptyCell;

                }

            }

        }

        auto it1=m1.begin(), it2=m1.end();
       int i=0;
        while(it1!=it2)
        {
            std::sort(std::begin(it1.value()), std::end(it1.value()));
            auto it1_set=it1.value().rbegin(), it2_set=it1.value().rend();
            i=0;
            while(it1_set!=it2_set)
            {
                glassArray[m_rows-1-i][it1.key()]=glassArray[*it1_set][it1.key()];

                it1_set++;
                i++;

            }
            int empty=m_rows-it1.value().size();
            for(int j=0; j<empty; j++){
                glassArray[j][it1.key()] =emptyCell;


            }
            it1++;
        }

        emit (signalSetLCD(score));


    }
    else {

        if(glassArray[0][m_columns/2]!=emptyCell){   // stop the game if there is no space left for fugure to fall
            killTimer(idTimer);
            QMessageBox::information(this,"Information","Game over");
            return;
        }

        else{check=false;}
    }


};



void glass::keyPressEvent(QKeyEvent*event){

    if(gameOn)
    {
    // if game is on

    switch(event->key()) {//code of the key pressed

    case Qt::Key_Left:
        if(cur->getUpX()>0&&glassArray[cur->getDownY()][cur->getUpX()-1]==emptyCell)
   { cur->toLeft();
    repaint(); qDebug()<<"Repaint in keyPressEvent";}
    break;


    case Qt::Key_Right:
         if(cur->getUpX()<m_columns-1&&glassArray[cur->getDownY()][cur->getUpX()+1]==emptyCell)
        {
             cur->toRight();
       }
        break;

    case Qt::Key_Down:
    cur->rotateColors(false);
    break;

    case Qt::Key_Up:
        cur->rotateColors(true);
          repaint(); qDebug()<<"Repaint in keyPressEvent";
    break;
    case Qt::Key_Space:

{
        int i=m_rows-1, j=cur->getUpX();
while(glassArray[i][j]!=emptyCell){

    i--;

}
cur->setUpIndex(j,i-2);
check=true;
    }
    break;

    default:
    QWidget::keyPressEvent(event);
    }
    }
    else{
    QWidget::keyPressEvent(event);

    }



}
