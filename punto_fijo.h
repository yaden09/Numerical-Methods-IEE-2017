#ifndef PUNTO_FIJO_H
#define PUNTO_FIJO_H

#include <QMainWindow>

namespace Ui {
class punto_fijo;
}

class punto_fijo : public QMainWindow
{
    Q_OBJECT

public:
    explicit punto_fijo(QWidget *parent = 0);
    ~punto_fijo();
    double funcion(double c); //Here it declares the drag function.

private:
    Ui::punto_fijo *ui;

public slots:

   void metodo(); //It declares the function where put the match operation.
   void borrar(); //Here going to put the comands for clear the variables when the botton is clicked.
};



#endif // PUNTO_FIJO_H
