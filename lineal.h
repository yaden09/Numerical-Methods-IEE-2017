#ifndef LINEAL_H
#define LINEAL_H

#include <QMainWindow>

namespace Ui {
class lineal;
}

class lineal : public QMainWindow
{
    Q_OBJECT

public:
    explicit lineal(QWidget *parent = 0);
    ~lineal();
    double funcion(double c);
    double m;//setting variables for capture of data
    double b;
    double sumx;
    double sumy;
    double sumxy;
    double sumx2;
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;

    int n;
    int i;


private:
    Ui::lineal *ui;

public slots://setting methods
    void metodo ();//method of regretion
    void limpiar ();//method for clean all interface
};


#endif // LINEAL_H
