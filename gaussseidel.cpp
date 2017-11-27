#include "gaussseidel.h"
#include "ui_gaussseidel.h"
#include <QString>
#include <cmath>
#include <QDebug>

GaussSeidel::GaussSeidel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GaussSeidel)
{
    ui->setupUi(this);//link buttons with their respective signals
    connect(ui->procesar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

GaussSeidel::~GaussSeidel()
{
    delete ui;
}
void GaussSeidel::metodo()//application of the method
{
    QString temp,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10;

//assignment of values ​​to variables
    a1= ui->a1->value();
    a2= ui->a2->value();
    a3= ui->a3->value();
    a4= ui->a4->value();
    b1= ui->b1->value();
    b2= ui->b2->value();
    b3= ui->b3->value();
    b4= ui->b4->value();
    c1= ui->c1->value();
    c2= ui->c2->value();
    c3= ui->c3->value();
    c4= ui->c4->value();
    d1= ui->d1->value();
    d2= ui->d2->value();
    d3= ui->d3->value();
    d4= ui->d4->value();
    A= ui->A->value();
    B= ui->B->value();
    C= ui->C->value();
    D= ui->D->value();
    err= ui->Err->value();
    errx1=100;
    errx2=100;
    errx3=100;
    errx4=100;
    it=0;
    X1=0;
    X2=0;
    X3=0;
    X4=0;
    X1a=1;
    X2a=1;
    X3a=1;
    X4a=1;

    //a1 b1 c1 d1= A
    //a2 b2 c2 d2= B
    //a3 b3 c3 d3= C
    //a4 b4 c4 d4= D
if(err>0){//action condition when the error is 0
    while((errx1>err)||(errx2>err)||(errx3>err)||(errx4>err)&&(it<1000))
    {   //iterations cycle

        X1= (A-(b1*X2)-(c1*X3)-(d1*X4))/a1;
        X2= (B-(a2*X1)-(c2*X3)-(d2*X4))/b2;
        X3= (C-(a3*X1)-(b3*X2)-(d3*X4))/c3;
        X4= (D-(a4*X1)-(b4*X2)-(c4*X3))/d4;

        errx1= abs(((X1-X1a)/X1)*100);
        errx2= abs(((X2-X2a)/X2)*100);
        errx3= abs(((X3-X3a)/X3)*100);
        errx4= abs(((X4-X4a)/X4)*100);

        X1a=X1;
        X2a=X2;
        X3a=X3;
        X4a=X4;

        it++;

        qDebug()<<"X1="<<X1<<" X2="<<X2<<" X3="<<X3<<" X4="<<X4<<"iter="<<it<<"er1="<<errx1<<"er2="<<errx2<<"er3="<<errx3<<"er4="<<errx4;
    }}

else{//condition for any error other than 0
    while((X1!=X1a)||(X2!=X2a)||(X3!=X3a)||(X4!=X4a))
    {//iterations cycle
        X1a=X1;
        X2a=X2;
        X3a=X3;
        X4a=X4;

        X1= (A-(b1*X2)-(c1*X3)-(d1*X4))/a1;
        X2= (B-(a2*X1)-(c2*X3)-(d2*X4))/b2;
        X3= (C-(a3*X1)-(b3*X2)-(d3*X4))/c3;
        X4= (D-(a4*X1)-(b4*X2)-(c4*X3))/d4;

        errx1= abs(((X1-X1a)/X1)*100);
        errx2= abs(((X2-X2a)/X2)*100);
        errx3= abs(((X3-X3a)/X3)*100);
        errx4= abs(((X4-X4a)/X4)*100);



        it++;

        qDebug()<<"X1="<<X1<<" X2="<<X2<<" X3="<<X3<<" X4="<<X4<<"iter="<<it<<"er1="<<errx1<<"er2="<<errx2<<"er3="<<errx3<<"er4="<<errx4;
    }}
        temp.append("X1=").append(temp5.setNum(X1)).append("     X2=").append(temp4.setNum(X2)).append("     X3=").append(temp3.setNum(X3)).append("     X4=").append(temp2.setNum(X4)).append("\nError En X1: ").append(temp6.setNum(errx1)).append("%   Error En X2: ").append(temp7.setNum(errx2)).append("%   Error En X3: ").append(temp8.setNum(errx3)).append("%   Error En X4:").append(temp9.setNum(errx4)).append("%\nIteraciones Realizadas:  ").append(temp10.setNum(it));
        ui->Texto->setText(temp);
        //
}

void GaussSeidel::borrar(){//application of the action erase
    ui->a1->setValue(0.0);//cleaning of variables
    ui->a2->setValue(0.0);
    ui->a3->setValue(0.0);
    ui->a4->setValue(0.0);
    ui->b1->setValue(0.0);
    ui->b2->setValue(0.0);
    ui->b3->setValue(0.0);
    ui->b4->setValue(0.0);
    ui->c1->setValue(0.0);
    ui->c2->setValue(0.0);
    ui->c3->setValue(0.0);
    ui->c4->setValue(0.0);
    ui->d1->setValue(0.0);
    ui->d2->setValue(0.0);
    ui->d3->setValue(0.0);
    ui->d4->setValue(0.0);
    ui->A->setValue(0.0);
    ui->B->setValue(0.0);
    ui->C->setValue(0.0);
    ui->D->setValue(0.0);
    ui->Texto->clear();
}
