#include "newton_rap.h"
#include "ui_newton_rap.h"
#include "math.h"
#include "QString"

Newton_Rap::Newton_Rap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Newton_Rap)
{
    ui->setupUi(this);
    connect(ui->start,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->exit,SIGNAL(clicked()),this,SLOT(close()));
}

Newton_Rap::~Newton_Rap()
{
    delete ui;
}
double Newton_Rap::funcion(double c)
{
   return (log(c)-(1/c));
}
double Newton_Rap::derivada(double c)
{
   return ((c+1)/(c*c));
}

void Newton_Rap::metodo()
{
    QString resultado,temp2,temp3,temp4;
   double x1=ui->inicial->value();
   double x2=0.0;
   double nt= ui->interacciones->value();
   double err= ui->error->value();
   double ea =100.0;
   double xr = 1;
   int rep=1;

   while(rep<=nt && ea>=err)
   {
      x2 = x1-(funcion(x1)/derivada(x1));
      ea=100*std::abs((x2-x1)/x2);
      x1=x2;
      xr=x2;
      rep++;

   }
   resultado.append("interacion: ").append(temp2.setNum(rep).append("                valor de X: ").append(temp3.setNum(xr)).append("                error(%): ").append(temp4.setNum(ea)));
   ui->raiz->setText(resultado);
}
void Newton_Rap::borrar()
{
   ui->inicial->setValue(0.0);
   ui->error->setValue(0.0);
   ui->interacciones->setValue(0.0);
   ui->raiz->clear();
}

