#ifndef RUNGE_H
#define RUNGE_H

#include <QMainWindow>

namespace Ui {
class Runge;
}

class Runge : public QMainWindow
{
    Q_OBJECT

public:
    explicit Runge(QWidget *parent = 0);
    ~Runge();

private:
    Ui::Runge *ui;
public slots:
    void metodo();
    void limpiar();
};

#endif // RUNGE_H
