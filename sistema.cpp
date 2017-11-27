#include "sistema.h"
#include "ui_sistema.h"


Sistema::Sistema(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sistema)
{
    ui->setupUi(this);
    Egauss = new ElimGuss();
    Gseidel = new GaussSeidel();
    MEuler = new Euler();
    Integracion = new Inte();
    NRaphson = new Newton_Rap();
    Pfijo = new punto_fijo();
    RLM = new RegresionLM();
    Derivacion = new Deriv();
    Grange = new LaGrange();
    reglin = new lineal();
    run = new Runge();
    Calcula = new Calculadora();


    connect(ui->bot_regr,SIGNAL(clicked()),this,SLOT(reglinealm()));
    connect(ui->bot_pfij,SIGNAL(clicked()),this,SLOT(puntof()));
    connect(ui->bot_raph,SIGNAL(clicked()),this,SLOT(newrap()));
    connect(ui->bot_inte,SIGNAL(clicked()),this,SLOT(Inumerica()));
    connect(ui->bot_euler,SIGNAL(clicked()),this,SLOT(mEuler()));
    connect(ui->bot_elim,SIGNAL(clicked()),this,SLOT(Egaus()));
    connect(ui->bot_Gaussei,SIGNAL(clicked()),this,SLOT(Gseid()));
    connect(ui->bot_salir,SIGNAL(clicked()),this,SLOT(salir()));
    connect(ui->bot_grange,SIGNAL(clicked()), this,SLOT(gran()));
    connect(ui->bot_derivacion,SIGNAL(clicked()), this, SLOT(deri()));
    connect(ui->bot_reglin,SIGNAL(clicked()), this, SLOT(regl()));
    connect(ui->bot_runge,SIGNAL(clicked()), this, SLOT(rung()));
    connect(ui->bot_calculadora,SIGNAL(clicked()), this, SLOT(calc()));

}

Sistema::~Sistema()
{
    delete ui;
}

void Sistema::reglinealm(){
    RLM->show();
}

void Sistema::puntof(){
    Pfijo->show();
}

void Sistema::newrap(){
    NRaphson->show();
}

void Sistema::Inumerica(){
    Integracion->show();
}

void Sistema::mEuler(){
    MEuler->show();
}

void Sistema::Egaus(){
    Egauss->show();
}

void Sistema::Gseid(){
    Gseidel->show();
}
void Sistema::deri(){
    Derivacion->show();
}
void Sistema::gran(){
    Grange->show();
}
void Sistema::regl(){
    reglin->show();
}
void Sistema::rung(){
    run->show();
}
void Sistema::calc(){
    Calcula->show();
}



void Sistema::salir(){
    delete Gseidel;
    delete Egauss;   close();
}
