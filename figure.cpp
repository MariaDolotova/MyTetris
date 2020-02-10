#include "figure.h"
#include "glass.h"
#include<QDebug>


void figure::MakeRandomColors(){

    for (int i=0; i<3; i++){
        int index=qrand()%(sizeof (col_ar)/sizeof (col_ar[0]));
        ar[i]=col_ar[index];

    }

};


void figure::rotateColors(bool b){
     QColor tmp=ar[0];

    if(b){


        ar[0]=ar[1];
        ar[1]=ar[2];
        ar[2]=tmp;

    }
    else{
        ar[0]=ar[2];
        ar[2]=ar[1];
        ar[1]=tmp;

    }

};


void figure::paintFigure(QPainter&painter){
    uint x=m_i*m_W+1;
    uint y=m_j*m_W+1;
    for(int i=0; i<3; i++)
    { painter.fillRect(x, y,m_W-1,m_W-1,ar[i]);
        y+=m_W;
    }


};
