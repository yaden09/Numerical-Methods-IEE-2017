#include "calculadora.h"
#include "ui_calculadora.h"

Calculadora::Calculadora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculadora)
{
    ui->setupUi(this);
    texto = new QString();
    texto->clear();
    connect(ui->cero,SIGNAL(clicked()),this,SLOT(agregaCero()));
    connect(ui->uno,SIGNAL(clicked()),this,SLOT(agregaUno()));
    connect(ui->dos,SIGNAL(clicked()),this,SLOT(agregaDos()));
    connect(ui->tres,SIGNAL(clicked()),this,SLOT(agregaTres()));
    connect(ui->cuatro,SIGNAL(clicked()),this,SLOT(agregaCuatro()));
    connect(ui->cinco,SIGNAL(clicked()),this,SLOT(agregaCinco()));
    connect(ui->seis,SIGNAL(clicked()),this,SLOT(agregaSeis()));
    connect(ui->siete,SIGNAL(clicked()),this,SLOT(agregaSiete()));
    connect(ui->ocho,SIGNAL(clicked()),this,SLOT(agregaOcho()));
    connect(ui->nueve,SIGNAL(clicked()),this,SLOT(agregaNueve()));
    connect(ui->suma,SIGNAL(clicked()),this,SLOT(Suma()));
    connect(ui->resta,SIGNAL(clicked()),this,SLOT(Resta()));
    connect(ui->multiplica,SIGNAL(clicked()),this,SLOT(Multiplica()));
    connect(ui->divide,SIGNAL(clicked()),this,SLOT(Divide()));
    connect(ui->borra,SIGNAL(clicked()),this,SLOT(Borra()));
    connect(ui->retro,SIGNAL(clicked()),this,SLOT(Retroceso()));
    connect(ui->igual,SIGNAL(clicked()),this,SLOT(Igual()));
    oper = 0;
}

Calculadora::~Calculadora()
{
    delete ui;
}

void Calculadora::agregaCero(){
    texto->append(ui->cero->text());
    despliega();
}

void Calculadora::agregaUno(){
    texto->append(ui->uno->text());
    despliega();
}

void Calculadora::agregaDos(){
    texto->append(ui->dos->text());
    despliega();
}

void Calculadora::agregaTres(){
    texto->append(ui->tres->text());
    despliega();
}

void Calculadora::agregaCuatro(){
    texto->append(ui->cuatro->text());
    despliega();
}

void Calculadora::agregaCinco(){
    texto->append(ui->cinco->text());
    despliega();
}

void Calculadora::agregaSeis(){
    texto->append(ui->seis->text());
    despliega();
}

void Calculadora::agregaSiete(){
    texto->append(ui->siete->text());
    despliega();
}

void Calculadora::agregaOcho(){
    texto->append(ui->ocho->text());
    despliega();
}

void Calculadora::agregaNueve(){
    texto->append(ui->nueve->text());
    despliega();
}

void Calculadora::despliega(){
    operando=texto->toDouble();
    ui->lcd->display(operando);
}


void Calculadora::Suma(){
    operando2=operando;
    texto->clear();
    oper=1;
    despliega();
}

void Calculadora::Resta(){
    operando2=operando;
    texto->clear();
    oper=2;
    despliega();
}

void Calculadora::Multiplica(){
    operando2=operando;
    texto->clear();
    oper=3;
    despliega();
}

void Calculadora::Divide(){
    operando2=operando;
    texto->clear();
    oper=4;
    despliega();
}

void Calculadora::Borra(){
    texto->clear();
    despliega();
}

void Calculadora::Retroceso(){
    QString temp;
    temp=texto->left(texto->length()-1);
    texto->clear();
    texto->append(temp);
    despliega();
}

void Calculadora::Igual(){
    double temp;
    switch (oper) {
    case 1:
        temp=operando+operando2;
        break;
    case 2:
        temp=operando2-operando;
        break;
    case 3:
        temp=operando*operando2;
        break;
    case 4:
        temp=operando2/operando;
        break;
    }
    texto->clear();
    texto->setNum(temp);
    despliega();
    texto->clear();
}
