#ifndef REGRESIONLM_H
#define REGRESIONLM_H

#include <QMainWindow>

namespace Ui {
class RegresionLM;
}

class RegresionLM : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegresionLM(QWidget *parent = 0);
    ~RegresionLM();

private:
    Ui::RegresionLM *ui;
private slots:
    void metodo();
    void limpiar();
};

#endif // REGRESIONLM_H
