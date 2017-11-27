#include "elimguss.h"
#include "ui_elimguss.h"
#include <QString>
#include <cmath>

ElimGuss::ElimGuss(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ElimGuss)
{
    ui->setupUi(this);
    connect(ui->procesar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

ElimGuss::~ElimGuss()
{
    delete ui;
}
void ElimGuss::metodo()
{
    QString temp,temp2,temp3,temp4,temp5;
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
    X1=0;
    X2=0;
    X3=0;
    X4=0;


    //a1 b1 c1 d1= A
    //a2 b2 c2 d2= B
    //a3 b3 c3 d3= C
    //a4 b4 c4 d4= D

    //Paso 1. igualar a 1
    {
    b1=b1/a1;
    c1=c1/a1;
    d1=d1/a1;
    A=A/a1;
    a1= 1;

    b2=b2/a2;
    c2=c2/a2;
    d2=d2/a2;
    B=B/a2;
    a2= 1;

    b3=b3/a3;
    c3=c3/a3;
    d3=d3/a3;
    C=C/a3;
    a3= 1;

    b4=b4/a4;
    c4=c4/a4;
    d4=d4/a4;
    D=D/a4;
    a4= 1;
    }

    //Paso 2. Igualar a 0 (0)
    if ((a2>0 && a1>0)||(a2<0 && a1<0) )
    {
        a2=a2-a1;
        b2=b2-b1;
        c2=c2-c1;
        d2=d2-d1;
        B=B-A;
    }
    else if((a2<0 && a1>0)||(a2>0 && a1<0))
    {
        a2=a2+a1;
        b2=b2+b1;
        c2=c2+c1;
        d2=d2+d1;
        B=B+A;
    }

        if ((a3>0 && a1>0)||(a3<0 && a1<0) )
        {
            a3=a3-a1;
            b3=b3-b1;
            c3=c3-c1;
            d3=d3-d1;
            C=C-A;
        }
        else if((a3<0 && a1>0)||(a3>0 && a1<0))
        {
            a3=a3+a1;
            b3=b3+b1;
            c3=c3+c1;
            d3=d3+d1;
            C=C+A;
        }

            if ((a4>0 && a1>0)||(a4<0 && a1<0) )
            {
                a4=a4-a1;
                b4=b4-b1;
                c4=c4-c1;
                d4=d4-d1;
                D=D-A;
            }
            else if((a4<0 && a1>0)||(a4>0 && a1<0))
            {
                a4=a4+a1;
                b4=b4+b1;
                c4=c4+c1;
                d4=d4+d1;
                D=D+A;
            }

    //Paso 3. Segunda igualación a 1
    {
    c2=c2/b2;
    d2=d2/b2;
    B=B/b2;
    b2=1;

    c3=c3/b3;
    d3=d3/b3;
    C=C/b3;
    b3=1;

    c4=c4/b4;
    d4=d4/b4;
    D=D/b4;
    b4=1;
    }
    //Paso 4. Segunda igualación a 0(00)
    if ((b2>0 && b3>0)||(b2<0 && b3<0) )
    {
    b3=b3-b2;
    c3=c3-c2;
    d3=d3-d2;
    C=C-B;
    }
    else if((b2<0 && b3>0)||(b2>0 && b3<0))
    {
    b3=b3+b2;
    c3=c3+c2;
    d3=d3+d2;
    C=C+B;
    }
    if ((b2>0 && b4>0)||(b2<0 && b4<0) )
    {
    b4=b4-b2;
    c4=c4-c2;
    d4=d4-d2;
    D=D-B;
    }
    else if((b2<0 && b4>0)||(b2>0 && b4<0))
    {

    b4=b4+b2;
    c4=c4+c2;
    d4=d4+d2;
    D=D+B;
    }
    //Paso 5. Tercera igualacion a 1
    {
    d3=d3/c3;
    C=C/c3;
    c3=1;

    d4=d4/c4;
    D=D/c4;
    c4=1;
    }
    //Paso 6. Tercera igualcion a 0(000)
    if((c3>0 && c4>0)||(c3<0 && c4<0) )
    {
    c4=c4-c3;
    d4=d4-d3;
    D=D-C;
    }
    else if((c3<0 && c4>0)||(c3>0 && c4<0))
    {
    c4=c4+c3;
    d4=d4+d3;
    D=D+C;
    }
    //Paso 7. Calculo de las X:
        X4= D/d4;
        X3= (C-(d3*X4))/c3;
        X2= (B-((d2*X4)+(c2*X3)))/b2;
        X1= (A-((d1*X4)+(c1*X3)+(b1*X2)))/a1;

        temp.append("X1=").append(temp5.setNum(X1)).append("     X2=").append(temp4.setNum(X2)).append("     X3=").append(temp3.setNum(X3)).append("     X4=").append(temp2.setNum(X4));
        ui->Texto->setText(temp);
}

void ElimGuss::borrar(){
    ui->a1->setValue(0.0);
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
    ui->Texto->clear();     //Se borra el texto
}
