#ifndef MYTEXTEDITCLASS_H
#define MYTEXTEDITCLASS_H

#pragma once
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtWidgets>
#include <QMouseEvent>
#include <QTextEdit>


class MyTextEdit:public QTextEdit{
    Q_OBJECT
public:
    MyTextEdit(const QString &text, QWidget *parent =0):QTextEdit(text,parent),columns{0}{
        ;}


public slots:
    void Column_1(int z){
       columns[0] = z;
       setText(QString::number(columns[0]+(columns[1]<<7)+(columns[2]<<14)+(columns[3]<<21)));
    }
    void Column_2(int z){
       columns[1] = z;
       setText(QString::number(columns[0]+(columns[1]<<7)+(columns[2]<<14)+(columns[3]<<21)));
    }
    void Column_3(int z){
       columns[2] = z;
       setText(QString::number(columns[0]+(columns[1]<<7)+(columns[2]<<14)+(columns[3]<<21)));
    }
    void Column_4(int z){
       columns[3] = z;
       setText(QString::number(columns[0]+(columns[1]<<7)+(columns[2]<<14)+(columns[3]<<21)));
    }


private:
    int columns[4];

};

#endif // MYTEXTEDITCLASS_H
