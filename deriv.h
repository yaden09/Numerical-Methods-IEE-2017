#ifndef DERIV_H
#define DERIV_H

#include <QMainWindow>

namespace Ui {
class Deriv;
}

class Deriv : public QMainWindow
{
    Q_OBJECT

public:
    explicit Deriv(QWidget *parent = 0);
    ~Deriv();

private:
    Ui::Deriv *ui;
public slots:
    void metodo();
    void limpiar();
};

#endif // DERIV_H
