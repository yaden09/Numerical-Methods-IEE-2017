#ifndef SISTEMA_H
#define SISTEMA_H

#include <QMainWindow>
#include "elimguss.h"
#include "gaussseidel.h"
#include "euler.h"
#include "inte.h"
#include "newton_rap.h"
#include "punto_fijo.h"
#include "regresionlm.h"
#include "deriv.h"
#include "lagrange.h"
#include "lineal.h"
#include "runge.h"
#include "calculadora.h"

namespace Ui {
class Sistema;
}

class Sistema : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sistema(QWidget *parent = 0);
    ~Sistema();
    ElimGuss *Egauss;
    GaussSeidel *Gseidel;
    Euler *MEuler;
    Inte *Integracion;
    Newton_Rap *NRaphson;
    punto_fijo *Pfijo;
    RegresionLM *RLM;
    Deriv *Derivacion;
    LaGrange *Grange;
    lineal *reglin;
    Runge *run;
    Calculadora *Calcula;





private:
    Ui::Sistema *ui;
public slots:
    void salir();
    void Egaus();
    void Gseid();
    void mEuler();
    void Inumerica();
    void newrap();
    void puntof();
    void reglinealm();
    void deri();
    void gran();
    void regl();
    void rung();
    void calc();

};

#endif // SISTEMA_H
