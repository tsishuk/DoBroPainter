#include <QtWidgets>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mywidgetclass.h"
#include "mytexteditclass.h"
#include <QObject>
#include <QLabel>
#include <QFont>





int main(int argc, char** argv)
{

    QApplication app(argc, argv);

    QBoxLayout* vbxLayout1 = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout* hboxLayout1 = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout* hboxLayout2 = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout* hboxLayout3 = new QBoxLayout(QBoxLayout::LeftToRight);
    vbxLayout1->setMargin(0);
    vbxLayout1->setSpacing(15);

    MyWidget* wgt1 = new MyWidget;
    wgt1->setMinimumSize(158,220);
    wgt1->setMaximumSize(158,220);
    wgt1->resize(158,220);

    MyWidget* wgt2 = new MyWidget;
    wgt2->setMinimumSize(158,220);
    wgt2->setMaximumSize(158,220);
    wgt2->resize(158,220);

    MyWidget* wgt3 = new MyWidget;
    wgt3->setMinimumSize(158,220);
    wgt3->setMaximumSize(158,220);
    wgt3->resize(158,220);

    MyWidget* wgt4 = new MyWidget;
    wgt4->setMinimumSize(158,220);
    wgt4->setMaximumSize(158,220);
    wgt4->resize(158,220);




    MyTextEdit* TextEdit1 = new MyTextEdit("0") ;
    TextEdit1->setAlignment(Qt::AlignHCenter);
    TextEdit1->setFontPointSize(12.0);
    TextEdit1->setMaximumSize(120,30);
    TextEdit1->setMinimumSize(120,30);
    TextEdit1->setCursorWidth(0);
    TextEdit1->setText("0");

    MyTextEdit* TextEdit2 = new MyTextEdit("0") ;
    TextEdit2->setAlignment(Qt::AlignHCenter);
    TextEdit2->setFontPointSize(12.0);
    TextEdit2->setMaximumSize(120,30);
    TextEdit2->setMinimumSize(120,30);
    TextEdit2->setCursorWidth(0);
    TextEdit2->setText("0");

    MyTextEdit* TextEdit3 = new MyTextEdit("0") ;
    TextEdit3->setAlignment(Qt::AlignHCenter);
    TextEdit3->setFontPointSize(12.0);
    TextEdit3->setMaximumSize(120,30);
    TextEdit3->setMinimumSize(120,30);
    TextEdit3->setCursorWidth(0);
    TextEdit3->setText("0");

    MyTextEdit* TextEdit4 = new MyTextEdit("0") ;
    TextEdit4->setAlignment(Qt::AlignHCenter);
    TextEdit4->setFontPointSize(12.0);
    TextEdit4->setMaximumSize(120,30);
    TextEdit4->setMinimumSize(120,30);
    TextEdit4->setCursorWidth(0);
    TextEdit4->setText("0");

    MyTextEdit* TextEdit5 = new MyTextEdit("0") ;
    TextEdit5->setAlignment(Qt::AlignHCenter);
    TextEdit5->setFontPointSize(12.0);
    TextEdit5->setMaximumSize(120,30);
    TextEdit5->setMinimumSize(120,30);
    TextEdit5->setCursorWidth(0);
    TextEdit5->setText("0");



    QLabel* column1Label = new QLabel("           1");
    column1Label->setMaximumSize(120,25);
    column1Label->setMinimumSize(120,25);
    QFont font = column1Label->font();
    font.setPointSize(12);
    column1Label->setFont(font);


    QLabel* column2Label = new QLabel("           2");
    column2Label->setMaximumSize(120,25);
    column2Label->setMinimumSize(120,25);
    font = column2Label->font();
    font.setPointSize(12);
    column2Label->setFont(font);

    QLabel* column3Label = new QLabel("           3");
    column3Label->setMaximumSize(120,25);
    column3Label->setMinimumSize(120,25);
    font = column3Label->font();
    font.setPointSize(12);
    column3Label->setFont(font);

    QLabel* column4Label = new QLabel("           4");
    column4Label->setMaximumSize(120,25);
    column4Label->setMinimumSize(120,25);
    font = column4Label->font();
    font.setPointSize(12);
    column4Label->setFont(font);

    QLabel* column5Label = new QLabel("           5");
    column5Label->setMaximumSize(120,25);
    column5Label->setMinimumSize(120,25);
    font = column5Label->font();
    font.setPointSize(12);
    column5Label->setFont(font);



    hboxLayout1->addStretch(40);
    hboxLayout1->addWidget(wgt1);
    hboxLayout1->addWidget(wgt2);
    hboxLayout1->addWidget(wgt3);
    hboxLayout1->addWidget(wgt4);
    hboxLayout1->addStretch(40);

    hboxLayout2->addStretch(40);
    hboxLayout2->addWidget(column1Label);
    hboxLayout2->addWidget(column2Label);
    hboxLayout2->addWidget(column3Label);
    hboxLayout2->addWidget(column4Label);
    hboxLayout2->addWidget(column5Label);
    hboxLayout2->addStretch(40);


    hboxLayout3->addStretch(40);
    hboxLayout3->addWidget(TextEdit1);
    hboxLayout3->addWidget(TextEdit2);
    hboxLayout3->addWidget(TextEdit3);
    hboxLayout3->addWidget(TextEdit4);
    hboxLayout3->addWidget(TextEdit5);
    hboxLayout3->addStretch(40);


    vbxLayout1->addLayout(hboxLayout1,40);
    vbxLayout1->addLayout(hboxLayout2);
    vbxLayout1->addLayout(hboxLayout3);
    vbxLayout1->addStretch(1);



    QObject::connect(wgt1, SIGNAL(CellChanged1(int)),TextEdit1, SLOT(Column_1(int)));
    QObject::connect(wgt2, SIGNAL(CellChanged1(int)),TextEdit1, SLOT(Column_2(int)));
    QObject::connect(wgt3, SIGNAL(CellChanged1(int)),TextEdit1, SLOT(Column_3(int)));
    QObject::connect(wgt4, SIGNAL(CellChanged1(int)),TextEdit1, SLOT(Column_4(int)));

    QObject::connect(wgt1, SIGNAL(CellChanged2(int)),TextEdit2, SLOT(Column_1(int)));
    QObject::connect(wgt2, SIGNAL(CellChanged2(int)),TextEdit2, SLOT(Column_2(int)));
    QObject::connect(wgt3, SIGNAL(CellChanged2(int)),TextEdit2, SLOT(Column_3(int)));
    QObject::connect(wgt4, SIGNAL(CellChanged2(int)),TextEdit2, SLOT(Column_4(int)));

    QObject::connect(wgt1, SIGNAL(CellChanged3(int)),TextEdit3, SLOT(Column_1(int)));
    QObject::connect(wgt2, SIGNAL(CellChanged3(int)),TextEdit3, SLOT(Column_2(int)));
    QObject::connect(wgt3, SIGNAL(CellChanged3(int)),TextEdit3, SLOT(Column_3(int)));
    QObject::connect(wgt4, SIGNAL(CellChanged3(int)),TextEdit3, SLOT(Column_4(int)));

    QObject::connect(wgt1, SIGNAL(CellChanged4(int)),TextEdit4, SLOT(Column_1(int)));
    QObject::connect(wgt2, SIGNAL(CellChanged4(int)),TextEdit4, SLOT(Column_2(int)));
    QObject::connect(wgt3, SIGNAL(CellChanged4(int)),TextEdit4, SLOT(Column_3(int)));
    QObject::connect(wgt4, SIGNAL(CellChanged4(int)),TextEdit4, SLOT(Column_4(int)));

    QObject::connect(wgt1, SIGNAL(CellChanged5(int)),TextEdit5, SLOT(Column_1(int)));
    QObject::connect(wgt2, SIGNAL(CellChanged5(int)),TextEdit5, SLOT(Column_2(int)));
    QObject::connect(wgt3, SIGNAL(CellChanged5(int)),TextEdit5, SLOT(Column_3(int)));
    QObject::connect(wgt4, SIGNAL(CellChanged5(int)),TextEdit5, SLOT(Column_4(int)));




    QWidget container;
    container.resize(680,320);
    container.setLayout(vbxLayout1);
    container.show();
    container.setWindowTitle("DoBro Painter");

    return app.exec();
}
