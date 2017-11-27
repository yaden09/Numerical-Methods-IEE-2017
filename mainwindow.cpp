#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>  //Library for the use of text strings
#include <cmath>    //Library for the use of mathematical functions

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{                           //Connections of the slots
    ui->setupUi(this);
    connect(ui->Process,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
double MainWindow::funcion(double c){           //The function is called
    return(exp(-c)-c);   //You write the function to use and returns the function
}
double MainWindow::dfuncion(double c)         //use of the first derivative
{
    return(-exp(-c)-1);
}

void MainWindow::metodo(){
    QString temp,temp2,temp3,temp4,temp5;  //Temporary use text strings
    double x1=ui->X1->value();        //Retrieves the value of X 1 of the spinbox
    double err=ui->Err->value();      //Retrieves the value of the error of the spinbox
    double nit=ui->NI->value();     //Retrieves the value of the iteractions of the spinbox
    double xi=00;                 //start the number of xi at zero
    double ea=100.0;             //set the maximum error value that can be entered
    double ni=0;                   // Start the number of interactions at zero

        while((ea>err)&&(ni<nit))
       {
       xi=(x1-(funcion(x1))/(dfuncion(x1))); //Evaluación de las funciones en busca de la raíz.
       ea=100*std::abs((xi-x1)/xi);          //The error is calculated
       x1=xi;                                 //Equal variables
       ni++;                             //Increases the counter depending on the number of necessary interactions
       }

        temp.append("Raiz=").append(temp2.setNum(xi)).append("\nError=").append(temp3.setNum(ea)).append("\nIteraciones=").append(temp4.setNum(ni));
        ui->Texto->setText(temp); //The text is presented
}

void MainWindow::borrar(){
    ui->X1->setValue(0.0);    //The spinbox is deleted
    ui->Err->setValue(0.0);
    ui->Texto->clear();       //Clears the text

}

