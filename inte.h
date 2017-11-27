#ifndef INTE_H
#define INTE_H

#include <QMainWindow>

namespace Ui {
class Inte;
}

class Inte : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inte(QWidget *parent = 0);
    ~Inte();
    int nt, ns;
    double ht, hs, *ft, *fs, sumt, sums, x1, x2, x3, x;

private:
    Ui::Inte *ui;

public slots://setting methods
    void metodo ();//method of regretion
    void limpiar ();//method for clean all interface
};

#endif // INTE_H
