#include "regresionlm.h"
#include "ui_regresionlm.h"

RegresionLM::RegresionLM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegresionLM)
{
    ui->setupUi(this);
    connect(ui->Metodo,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Limpiar,SIGNAL(clicked()),this,SLOT(limpiar()));
}

RegresionLM::~RegresionLM()
{
    delete ui;
}
void RegresionLM :: metodo()
{
    QString temp, temp2, temp3,temp4;//Declaracion de bariables y valores
               double y1=ui->Y1->value();
               double y2=ui->Y2->value();
               double y3=ui->Y3->value();
               double y4=ui->Y4->value();
               double y5=ui->Y5->value();
               double y6=ui->Y6->value();
               double x1=ui->X11->value();
               double x2=ui->X12->value();
               double x3=ui->X13->value();
               double x4=ui->X14->value();
               double x5=ui->X15->value();
               double x6=ui->X16->value();
               double z1=ui->X21->value();
               double z2=ui->X22->value();
               double z3=ui->X23->value();
               double z4=ui->X24->value();
               double z5=ui->X25->value();
               double z6=ui->X26->value();
               double SumY=0,SumZ=0,SumX=0;
               double XY=0,XX=0,XZ=0,YZ=0,ZZ=0;
               double n=6;

                //Operaciones de para las sumatorias
               SumX=x1+x2+x3+x4+x5+x6;
               SumZ=z1+z2+z3+z4+z5+z6;
               SumY=y1+y2+y3+y4+y5+y6;
               XY=(x1*y1)+(x2*y2)+(x3*y3)+(x4*y4)+(x5*y5)+(x6*y6);
               XZ=(x1*z1)+(x2*z2)+(x3*z3)+(x4*z4)+(x5*z5)+(x6*z6);
               YZ=(z1*y1)+(z2*y2)+(z3*y3)+(z4*y4)+(z5*y5)+(z6*y6);
               ZZ=(z1*z1)+(z2*z2)+(z3*z3)+(z4*z4)+(z5*z5)+(z6*z6);
               XX=(x1*x1)+(x2*x2)+(x3*x3)+(x4*x4)+(x5*x5)+(x6*x6);
                //aSumX+bSumZ+cn=SumY
                //aXX+bXZ+cSumX=XY
                //aXZ+bZZ+cSumZ=YZ

               //a1 b1 c1 = A
               //a2 b2 c2 = B
               //a3 b3 c3 = C

                //Declaracion de bariables para la eliminacion gaussiana
               double a1= SumX;
               double a2= XX;
               double a3= XZ;
               double b1=SumZ;
               double b2=XZ;
               double b3=ZZ;
               double c1= n;
               double c2= SumX;
               double c3= SumZ;
               double A= SumY;
               double B= XY;
               double C= YZ;
               double X1=0;
               double X2=0;
               double X3=0;
                //Eliminacion gaussiana
               //Paso 1. igualar a 1
               b1=b1/a1;
               c1=c1/a1;
               A=A/a1;
               a1= 1;

               b2=b2/a2;
               c2=c2/a2;
               B=B/a2;
               a2= 1;

               b3=b3/a3;
               c3=c3/a3;
               C=C/a3;
               a3= 1;

               //Paso 2. Igualar a 0 (0)
               a2=a2-a1;
               b2=b2-b1;
               c2=c2-c1;
               B=B-A;

               a3=a3-a1;
               b3=b3-b1;
               c3=c3-c1;
               C=C-A;

               //Paso 3. Segunda igualación a 1
               c2=c2/b2;
               B=B/b2;
               b2=1;

               c3=c3/b3;
               C=C/b3;
               b3=1;

               //Paso 4. Segunda igualación a 0(00)
               b3=b3-b2;
               c3=c3-c2;
               C=C-B;

               //Paso 5. Tercera igualacion a 1
               C=C/c3;
               c3=1;

               //Paso 7. Calculo de las X:
                   X3= C/c3;
                   X2= (B-(c2*X3))/b2;
                   X1= (A-((c1*X3)+(b1*X2)))/a1;

            temp.append("LA ECUCION ES:").append("    Y=").append(temp2.setNum(X1)).append("X").append("+").append(temp3.setNum(X2)).append("Z").append("+").append(temp4.setNum(X3));
                  ui->textBrowser->setText(temp);
}

void RegresionLM:: limpiar()
{
    ui->Y1->setValue(0.0);
    ui->Y2->setValue(0.0);
    ui->Y3->setValue(0.0);
    ui->Y4->setValue(0.0);
    ui->Y5->setValue(0.0);
    ui->Y6->setValue(0.0);
    ui->X11->setValue(0.0);
    ui->X12->setValue(0.0);
    ui->X13->setValue(0.0);
    ui->X14->setValue(0.0);
    ui->X15->setValue(0.0);
    ui->X16->setValue(0.0);
    ui->X21->setValue(0.0);
    ui->X22->setValue(0.0);
    ui->X23->setValue(0.0);
    ui->X24->setValue(0.0);
    ui->X25->setValue(0.0);
    ui->X26->setValue(0.0);
    ui->textBrowser->clear();
}

