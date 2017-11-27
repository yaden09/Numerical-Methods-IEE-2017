#include "inte.h"
#include "ui_inte.h"

Inte::Inte(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inte)
{
    ui->setupUi(this);
    connect(ui->metodo,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->limpiar,SIGNAL(clicked()),this,SLOT(limpiar()));
    connect(ui->exit,SIGNAL(clicked()),this,SLOT(close()));
}

Inte::~Inte()
{
    delete ui;
}
void Inte::metodo ()
{
    QString resultado,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9;//capturing values from spinbox
    double x1=ui->x1->value();
    double x2=ui->x2->value();
    double x3=ui->x3->value();
    double ht=ui->h->value();
    nt=ns;
    ht=hs;
    fs=0;
    sums=0;

    sumt=sumt+(ht+2)*((x1-1)+(2*x1)+(x1+1));
    sumt=sumt+(ht+2)*((x2-1)+(2*x2)+(x2+1));
    sumt=sumt+(ht+2)*((x3-1)+(2*x3)+(x3+1));

    sums=sums+(hs/3)*((x1-1)+(4*x1)+(x1+1));
    sums=sums+(hs/3)*((x2-1)+(4*x2)+(x2+1));
    sums=sums+(hs/3)*((x3-1)+(4*x3)+(x3+1));

    resultado.append("Area por metodo Simpson: ").append(temp2.setNum(sums)).append("/n Area por metodo Trapecio: ").append(temp3.setNum(sumt));
    ui->textEdit->setText(resultado); //The result is displayed on the interface.
}
void Inte::limpiar ()
{
         ui->x1->setValue(0.0);
         ui->x2->setValue(0.0);
         ui->x3->setValue(0.0);
         ui->h->setValue(0.0);
         ui->textEdit->clear();
}



