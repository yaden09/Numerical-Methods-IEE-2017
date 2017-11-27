#include "runge.h"
#include "ui_runge.h"

Runge::Runge(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Runge)
{
    ui->setupUi(this);
    connect(ui->metodo,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->limpiar,SIGNAL(clicked()),this,SLOT(limpiar()));
}

Runge::~Runge()
{
    delete ui;
}

// A sample differential equation "dy/dx = (x - y)/2"
double dxdy(double dx, double dy)
{
   return ((dx-dy)/2);
}

double rungeKutta(double x0, double y0, double dx, double h)
{
    // Count number of iterations using step size or
    // step height h
    int n = (int)((dx - x0) / h);

    double k1, k2, k3, k4;

    // Iterate for number of iterations
    double dy = y0;
    for (int i=1; i<=n; i++)
    {
        // Apply Runge Kutta Formulas to find
        // next value of y
        k1 = h*dxdy(x0, dy);
        k2 = h*dxdy(x0 + 0.5*h, dy + 0.5*k1);
        k3 = h*dxdy(x0 + 0.5*h, dy + 0.5*k2);
        k4 = h*dxdy(x0 + h, dy + k3);

        // Update next value of y
        dy = dy + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);;

        // Update next value of
        x0 = x0 + h;
    }

    return dy;
}
void Runge::metodo()
{
    // Finds value of y for a given x using step size h
    // and initial value y0 at x0.
    QString temp,temp1,temp2,temp3,temp4;
    double dx=ui->bot_dx->value();
    double dy=ui->bot_dy->value();
    double h=ui->bot_h->value();
    double x0=ui->bot_x0->value();
    double y0;

    temp.append("El Valor de Y en X es: ").append(temp1.setNum(rungeKutta(x0, y0, dx, h)));
    ui-> textBrowser-> setText (temp);
}
void Runge:: limpiar ()
{
         ui->bot_dx->setValue( 0.0 );
         ui->bot_dy-> setValue( 0.0 );
         ui->bot_h-> setValue( 0.0 );
         ui->bot_x0-> setValue( 0.0 );
         ui->textBrowser-> clear();

}
