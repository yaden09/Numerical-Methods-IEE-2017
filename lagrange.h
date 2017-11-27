#ifndef LAGRANGE_H
#define LAGRANGE_H

#include <QMainWindow>

namespace Ui {
class LaGrange;
}

class LaGrange : public QMainWindow
{
    Q_OBJECT

public:
    explicit LaGrange(QWidget *parent = 0);
    ~LaGrange();
    double funcion(double c);//declaration of variable
        double A[4];
        double B[4];

        double X0;
        double X1;
        double X2;
        double X3;
        double F0;
        double F1;
        double F2;
        double F3;
        double X;

        double F, M;
        int i=0, j=0, n;

        double polinomio[4];//array needed for method

private:
    Ui::LaGrange *ui;
public slots:
    void metodo();
    void limpiar();
};

#endif // LAGRANGE_H
