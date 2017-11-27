#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class Calculadora;
}

class Calculadora : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculadora(QWidget *parent = 0);
    ~Calculadora();
    double operando;
    double operando2;
    QString *texto;
    double operacion();
    void despliega();
    char oper;

private:
    Ui::Calculadora *ui;

public slots:
    void agregaCero();
    void agregaUno();
    void agregaDos();
    void agregaTres();
    void agregaCuatro();
    void agregaCinco();
    void agregaSeis();
    void agregaSiete();
    void agregaOcho();
    void agregaNueve();
    void Suma();
    void Resta();
    void Multiplica();
    void Divide();
    void Borra();
    void Retroceso();
    void Igual();

};

#endif // Calculadora_H
