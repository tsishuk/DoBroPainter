#ifndef MYCONNECTERCLASS_H
#define MYCONNECTERCLASS_H
#pragma once
#include <QObject>
#include <QString>
#include <QDebug>


class MyConnecter : public QObject{
    Q_OBJECT
public:
    MyConnecter():QObject(){}

public slots:
    connecterSlot(int z){
        qDebug()<<"Cell Changed, " + QString::number(z);
    }

signals:
    void connecterSignal();
};

#endif // CONNECTERCLASS_H
