#ifndef MYWIDGETCLASS_H
#define MYWIDGETCLASS_H
#pragma once
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtWidgets>
#include <QMouseEvent>


class MyWidget:public QWidget{
    Q_OBJECT
public:
    MyWidget(QWidget* parent=0):QWidget(parent),cell_states{0}{
    }

    virtual void paintEvent(QPaintEvent* pe){
        int i,j;
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(QPen(Qt::black, 1));
        for (i=0;i<5;i++)
            for (j=0;j<7;j++){
                if (cell_states[i][j]==0)
                   painter.setBrush(QBrush(Qt::black));
                else
                    painter.setBrush(QBrush(Qt::green));

                painter.drawRect(QRect(5+i*30,5+j*30,27,27));
            }

        QPointF a[5];
        a[0] = QPointF(1,1);
        a[1] = QPointF(157,1);
        a[2] = QPointF(157,217);
        a[3] = QPointF(1,217);
        a[4] = QPointF(1,1);
        painter.drawPolyline(a,5);
    }

    virtual void mouseMoveEvent(QMouseEvent* pe){
        int posx = (pe->x()-5)/30;
        int posy = (pe->y()-5)/30;
        if (pe->x()>0 && pe->y()>0 && posx<5 && posy<7){

            if (pe->buttons()==Qt::LeftButton)
                if (cell_states[posx][posy]==0){
                    cell_states[posx][posy]=1;
                    switch(posx){
                    case 0:
                      emit(CellChanged1(getColumnCode(0)));
                      break;
                    case 1:
                      emit(CellChanged2(getColumnCode(1)));
                      break;
                    case 2:
                      emit(CellChanged3(getColumnCode(2)));
                      break;
                    case 3:
                      emit(CellChanged4(getColumnCode(3)));
                      break;
                    case 4:
                      emit(CellChanged5(getColumnCode(4)));
                      break;
                    }
                }

             if (pe->buttons()==Qt::RightButton)
                 if (cell_states[posx][posy]==1){
                    cell_states[posx][posy]=0;
                    switch(posx){
                    case 0:
                      emit(CellChanged1(getColumnCode(0)));
                      break;
                    case 1:
                      emit(CellChanged2(getColumnCode(1)));
                      break;
                    case 2:
                      emit(CellChanged3(getColumnCode(2)));
                      break;
                    case 3:
                      emit(CellChanged4(getColumnCode(3)));
                      break;
                    case 4:
                      emit(CellChanged5(getColumnCode(4)));
                      break;
                    }
                 }

             this->update(3+posx*30, 3+posy*30, 30,30);
        }
    }

    virtual void mousePressEvent(QMouseEvent* pe){
        int posx = (pe->x()-5)/30;
        int posy = (pe->y()-5)/30;
        int i,j;

        if (pe->buttons() == Qt::MiddleButton){
            for (i=0;i<5;i++)
                for (j=0;j<7;j++)
                    cell_states[i][j]=0;
            this->update();
            emit(CellChanged1(getColumnCode(0)));
            emit(CellChanged2(getColumnCode(1)));
            emit(CellChanged3(getColumnCode(2)));
            emit(CellChanged4(getColumnCode(3)));
            emit(CellChanged5(getColumnCode(4)));
        }

        else if (pe->x()>0 && pe->y()>0 && posx<5 && posy<7){
            if (cell_states[posx][posy]==1){
                cell_states[posx][posy]=0;
                switch(posx){
                case 0:
                  emit(CellChanged1(getColumnCode(0)));
                  break;
                case 1:
                  emit(CellChanged2(getColumnCode(1)));
                  break;
                case 2:
                  emit(CellChanged3(getColumnCode(2)));
                  break;
                case 3:
                  emit(CellChanged4(getColumnCode(3)));
                  break;
                case 4:
                  emit(CellChanged5(getColumnCode(4)));
                  break;
                }
            }
            else if (cell_states[posx][posy]==0){
                cell_states[posx][posy]=1;
                switch(posx){
                case 0:
                  emit(CellChanged1(getColumnCode(0)));
                  break;
                case 1:
                  emit(CellChanged2(getColumnCode(1)));
                  break;
                case 2:
                  emit(CellChanged3(getColumnCode(2)));
                  break;
                case 3:
                  emit(CellChanged4(getColumnCode(3)));
                  break;
                case 4:
                  emit(CellChanged5(getColumnCode(4)));
                  break;
                }
            }
            this->update(3+posx*30, 3+posy*30, 30,30);
        }
    }



    int getColumnCode(int i){
        int result = 0;
        for (int j=0;j<7;j++)
            if (cell_states[i][j]==1)
                result |= (1<<j);
        return result;
    }



signals:
    void CellChanged1(int x);
    void CellChanged2(int x);
    void CellChanged3(int x);
    void CellChanged4(int x);
    void CellChanged5(int x);



private:
    int cell_states[5][7];
};

#endif // MYWIDGETCLASS_H
