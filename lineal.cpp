#include "lineal.h"
#include "ui_lineal.h"

lineal::lineal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lineal)
{
    ui->setupUi(this);
    connect(ui->start,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(limpiar()));
}

lineal::~lineal()
{
    delete ui;
}
void lineal::metodo ()
{
    QString resultado,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9;
    double x1=ui->bx1->value();//capturing values from spinbox
    double y1=ui->by1->value();
    double x2=ui->bx2->value();
    double y2=ui->by2->value();
    double x3=ui->bx3->value();
    double y3=ui->by3->value();

    //sum of the products
    sumx=sumy=sumxy=sumx2=0;//set values to 0
        sumxy+=x1*x2*x3*y1*y2*y3;//every product
        sumx2+=(x1+x2+x3)*(x1+x2+x3);//sum value of x^2
        sumx+=x1+x2+x3;//sum value of X
        sumy+=y1*y2*y3;//sum value of Y

        m=(3*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);//calculating the pendient
        b=(sumy-m*sumx)/n;//intersection

        resultado.append("Pendiente").append(temp2.setNum(m).append("/Intersección: ").append(temp3.setNum(b)).append("/n Valor de la variable dependiente es Y= ").append(temp4.setNum(m)).append("x+").append(temp5.setNum(b)));
        ui->Texto->setText(resultado); //The result is displayed on the interface.
}
void lineal::limpiar ()
{
         ui->bx1->setValue(0.0);
         ui->bx2->setValue(0.0);
         ui->bx3->setValue(0.0);
         ui->by1->setValue(0.0);
         ui->by2->setValue(0.0);
         ui->by3->setValue(0.0);
         ui->Texto->clear();
}
