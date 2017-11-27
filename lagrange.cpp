#include "lagrange.h"
#include "ui_lagrange.h"
#include <QString>
#include <cmath>

LaGrange::LaGrange(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LaGrange)
{
    ui->setupUi(this);
        connect(ui->start,SIGNAL(clicked()),this,SLOT(metodo()));//connection of slot to button of method
        connect(ui->clear,SIGNAL(clicked()),this,SLOT(limpiar()));//connection of slot to button clear
        connect(ui->exit,SIGNAL(clicked()),this,SLOT(close()));//connection of slot to button close
}

LaGrange::~LaGrange()
{
    delete ui;
}
void LaGrange::metodo ()
{
    QString resultado, polinomio1, polinomio2, polinomio3;
    double X0=ui->X0->value();//captured value of boxes
    double X1=ui->X1->value();
    double X2=ui->X2->value();
    double X3=ui->X3->value();
    double F0=ui->FX0->value();
    double F1=ui->FX1->value();
    double F2=ui->FX2->value();
    double F3=ui->FX3->value();
    double X=ui->XX->value();
    double F, M;
    int i=0, j=0, n;//set value of variables to 0

    A[0]=X0;A[1]=X1;A[2]=X2;A[3]=X3;//declaration of the method for A using previous array
    B[0]=F0;B[1]=F1;B[2]=F2;B[3]=F3;//declaration of the method for B
    for(n=1;n<4;n++)//evaluation
    {
        M=0;

        for(i=0;i<=n;i++)
        {
            F=1.00;

            for(j=0;j<=n;j++)

            {

                if(i!=j)

                {
                  F=F*((X-A[j])/(A[i]-A[j]));
                }
            }
            F=F*B[i];
            M=M+F;

        }
        polinomio[n]=M;//result

    }
   resultado.append("\nPrimera funcion= ").append(polinomio1.setNum(polinomio[1])).append("\nSegunda funcion= ").append(polinomio2.setNum(polinomio[2])).append("\nTercera funcion= ").append(polinomio3.setNum(polinomio[3]));
    ui->textEdit->setText(resultado);//shows result of method
}

    void LaGrange::limpiar ()//clear al boxes
    {
             ui->X0->setValue(0.0);
             ui->X1->setValue(0.0);
             ui->X2->setValue(0.0);
             ui->X3->setValue(0.0);
             ui->FX0->setValue(0.0);
             ui->FX1->setValue(0.0);
             ui->FX2->setValue(0.0);
             ui->FX3->setValue(0.0);
             ui->XX->setValue(0.0);
             ui->textEdit->clear();
    }

