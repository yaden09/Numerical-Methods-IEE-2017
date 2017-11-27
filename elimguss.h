#ifndef ELIMGUSS_H
#define ELIMGUSS_H

#include <QMainWindow>

namespace Ui {
class ElimGuss;
}

class ElimGuss : public QMainWindow
{
    Q_OBJECT

public:
    explicit ElimGuss(QWidget *parent = 0);
    ~ElimGuss();

    double a1;
    double a2;
    double a3;
    double a4;
    double b1;
    double b2;
    double b3;
    double b4;
    double c1;
    double c2;
    double c3;
    double c4;
    double d1;
    double d2;
    double d3;
    double d4;
    double A;
    double B;
    double C;
    double D;
    double X1;
    double X2;
    double X3;
    double X4;
    double X1a;
    double X2a;
    double X3a;
    double X4a;

private:
    Ui::ElimGuss *ui;

public slots:
    void metodo();
    void borrar();
};

#endif // ELIMGUSS_H
