#ifndef EULER_H
#define EULER_H

#include <QMainWindow>

namespace Ui {
class Euler;
}

class Euler : public QMainWindow
{
    Q_OBJECT

public:
    explicit Euler(QWidget *parent = 0);
    ~Euler();

    double operacion(double a);
    double operacion2(double b);

private:
    Ui::Euler *ui;

public slots:
   void metodo();
   void limpiar();
};

#endif // EULER_H
