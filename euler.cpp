#include "euler.h"
#include "ui_euler.h"

Euler::Euler(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Euler)
{
    ui->setupUi(this);
    connect(ui->operar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->limpiar,SIGNAL(clicked()),this,SLOT(limpiar()));
}

Euler::~Euler()
{
    delete ui;
}
double Euler::operacion(double a)
{
   return ((-2*(a*a*a))+(12*(a*a))-(20*(a))+8.5);
}
double Euler::operacion2(double b)
{
   return ((-0.5*(b*b*b*b))+(4*(b*b*b))-(10*(b*b))+(8.5*b)+1);
}

void Euler::metodo()
{
    QString temp,temp1,temp2,temp3,temp4;
    double Xin = ui->xin-> value();
    double Xfin = ui->xfin->value();
    double h = ui->h->value();
    double xi0 = 0, error = 0, yi = 0, yi1 = 0;
    double it= 0;
    int i;

    it= (Xfin-Xin) / h;

    for(i=0;i<it;i++)
    {
        yi1=operacion2(xi0)+(operacion(xi0)*h);  // formula of the method
        xi0=(xi0+h);
        yi=operacion2(xi0);//We get the real value of the function
        error=100*std::abs(yi1-yi)/yi1;  //We obtain error

        temp.append("\n\ny(").append(temp1.setNum(xi0)).append(")=").append(temp2.setNum(yi1)).append("\t\tYreal=").append(temp3.setNum(yi)).append("\nError=").append(temp4.setNum(error)).append("%");

    }
    ui-> texto-> setText (temp);
}
void Euler:: limpiar ()
{
    ui-> xin-> setValue ( 0.0 );
    ui-> xfin-> setValue ( 0.0 );
    ui-> h-> setValue ( 0.0 );
    ui-> texto-> clear();

 }
