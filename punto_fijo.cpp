#include "punto_fijo.h"
#include "ui_punto_fijo.h"
#include <QString>
#include <math.h>
#include "QDoubleSpinBox"
#include "QSpinBox"


punto_fijo::punto_fijo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::punto_fijo)
{
    ui->setupUi(this);
    //Connections between buttons and slots.
    connect(ui->iniciar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->exit,SIGNAL(clicked()),this,SLOT(close()));

}

punto_fijo::~punto_fijo()
{
    delete ui;
}
double punto_fijo::funcion(double c){ //Enter the function that will be evaluate.
    return (667.38*(1-exp(-0.146843*c)))/40;
}

void punto_fijo::metodo(){ //match operations for the program.
    QString resultado,temp2,temp3,temp4; //String variables are created.

    //In this comands the user data is reading, and the variables are started.
    double dato=ui->X1->value();
    double err=ui->Error->value();
    double ea=100.0;
    double xr=0.0;
    int repit=1;

    //The bucle is created and that will solution the metod.
    while (ea>err)
    {
      xr=funcion(dato);
      ea=100*std::abs((xr-dato)/xr); //The error is calculeted.
      dato=xr; //Change the variable "dato" with xr.
      repit=repit+1; //The interaction is incresed.
    }
    //used the String for prepare the result.
    resultado.append("interacion #").append(temp2.setNum(repit).append("/valor de X: ").append(temp3.setNum(xr)).append("/error(%): ").append(temp4.setNum(ea)));
    ui->Texto->setText(resultado); //The result is displayed on the interface.
    }



void punto_fijo::borrar(){ //The variables are clear.
    ui->X1->setValue(0.0); //X1 is clear.
    ui->Error->setValue(0.0); // Error is clear.
    ui->Texto->clear(); //spinbox is clear.
}


