#include "deriv.h"
#include "ui_deriv.h"

Deriv::Deriv(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Deriv)
{
    ui->setupUi(this);
    connect(ui->Metodo,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Clear,SIGNAL(clicked()),this,SLOT(limpiar()));
}

Deriv::~Deriv()
{
    delete ui;
}
void Deriv::metodo()
{
    //Declaration of variables to print results
    QString temp, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11, temp12, temp13, temp14, temp15, temp16, temp17, temp18, temp19, temp20, temp21, temp22, temp23, temp24, temp25;
    QString temp26, temp27, temp28, temp29, temp30, temp31, temp32, temp33, temp34, temp35, temp36, temp37, temp38, temp39, temp40, temp41, temp42, temp43, temp44, temp45, temp46, temp47, temp48, temp49, temp50, temp51, temp52, temp53, temp54;
    //Variables in program
    double fx=ui->fx->value();
    double fxm1=ui->fxm1->value();
    double fxm2=ui->fxm2->value();
    double fxm3=ui->fxm3->value();
    double fxm4=ui->fxm4->value();
    double fxm5=ui->fxm5->value();
    double fxM1=ui->fxM1->value();
    double fxM2=ui->fxM2->value();
    double fxM3=ui->fxM3->value();
    double fxM4=ui->fxM4->value();
    double fxM5=ui->fxM5->value();
    double h=ui->h->value();
    double f1c=0, f2c=0, f3c=0, f4c=0, f11c=0, f22c=0, f33c=0, f44c=0;
    double f1at=0, f2at=0, f3at=0, f4at=0, f11at=0, f22at=0, f33at=0, f44at=0;
    double f1ad=0, f2ad=0, f3ad=0, f4ad=0, f11ad=0, f22ad=0, f33ad=0, f44ad=0;
    double err1c=0, err11c=0, err2c=0, err22c=0, err3c=0, err33c=0, err4c=0, err44c=0;
    double err1at=0, err11at=0, err2at=0, err22at=0, err3at=0, err33at=0, err4at=0, err44at=0;
    double err1ad=0, err11ad=0, err2ad=0, err22ad=0, err3ad=0, err33ad=0, err4ad=0, err44ad=0;

    f1c=(fxM1-fxm1)/(2*h);
        f11c=(-(fxM2)+(8*fxM1)-(8*fxm1)+(fxm2))/(12*h);
        f2c=(fxM1-(2*fx)+fxm1)/(h*h);
        f22c=(-fxM2+(16*fxM1)-(30*fx)+(16*fxm1)-fxm2)/(12*(h*h));
        f3c=(fxm2-(2*fxM1)+(2*fxm1)-fxm2)/(2*(h*h*h));
        f33c=(-fxM3+(8*fxM2)-(13*fxM1)+(13*fxm1)-(8*fxm2)+(fxm3))/(8*(h*h*h));
        f4c=(fxM2-(4*fxM1)+(6*fx)-(4*fxm1)+(fxm2))/(h*h*h*h);
        f44c=(-fxM3+(12*fxM2)+(39*fxM1)+(56*fx)-(39*fxm1)+(12*fxm2)+fxm3)/(6*(h*h*h*h));

        err1c=100*std::abs((f1c-f11c)/f11c);
        err11c=100*std::abs((f11c-f11c)/f11c);
        err2c=100*std::abs((f2c-f11c)/f11c);
        err22c=100*std::abs((f22c-f11c)/f11c);
        err3c=100*std::abs((f3c-f11c)/f11c);
        err33c=100*std::abs((f33c-f11c)/f11c);
        err4c=100*std::abs((f4c-f11c)/f11c);
        err44c=100*std::abs((f44c-f11c)/f11c);

        temp.append("Derivada centrada\n Primera derivada sencilla=").append(temp1.setNum(f1c)).append("\nPrimera derivada=").append(temp2.setNum(f11c)).append("\nSegunda derivada sencilla=").append(temp3.setNum(f2c));
        temp.append("\nSegunda derivada=").append(temp4.setNum(f22c)).append("\nTercera Derivada sencilla=").append(temp5.setNum(f3c)).append("\nTercera derivada=").append(temp6.setNum(f33c)).append("\nCuarta derivada sencilla=").append(temp7.setNum(f4c)).append("\nCuarta derivada=").append(temp8.setNum(f44c));
        temp.append("\nErrores\nError 1° derivada sencilla=").append(temp9.setNum(err1c)).append("\nError 1° derivada=").append(temp10.setNum(err11c)).append("\nError 2° derivada sencilla=").append(temp11.setNum(err2c)).append("\nError 2° derivada=").append(temp12.setNum(err22c)).append("\nError 3° derivada sencilla=").append(temp13.setNum(err3c)).append("\nError 3° derivada=").append(temp14.setNum(err33c)).append("\nError 4° derivada sencilla=").append(temp15.setNum(err4c)).append("\nError 4° derivada=").append(temp16.setNum(err44c));

        f1at=(fx-fxm1)/h;
        f11at=((3*fx)-(4*fxm1)+(fxm2))/(2*h);
        f2at=(fx-(2*fxm1)+fxm2)/(h*h);
        f22at=((2*fx)-(5*fxm1)+(4*fxm2)-fxm3)/(h*h);
        f3at=(fx-(3*fxm1)+(3*fxm2)-fxm3)/(h*h*h);
        f33at=((5*fx)-(18*fxm1)+(24*fxm2)-(14*fxm3)+(3*fxm4))/(2*(h*h*h));
        f4at=(fx-(4*fxm1)+(6*fxm2)-(4*fxm3)+fxm4)/(h*h*h*h);
        f44at=((3*fx)-(14*fxm1)+(26*fxm2)-(24*fxm3)+(11*fxm4)-(2*fxm5))/(h*h*h*h);

        err1at=100*std::abs((f1at-f11c)/f11c);
        err11at=100*std::abs((f11at-f11c)/f11c);
        err2at=100*std::abs((f2at-f11c)/f11c);
        err22at=100*std::abs((f22at-f11c)/f11c);
        err3at=100*std::abs((f3at-f11c)/f11c);
        err33at=100*std::abs((f33at-f11c)/f11c);
        err4at=100*std::abs((f4at-f11c)/f11c);
        err44at=100*std::abs((f44at-f11c)/f11c);
        //derivative results backwards
        temp.append("\nDerivada hacia atras\nPrimera derivada sencilla=").append(temp17.setNum(f1at)).append("\nPrimera derivada=").append(temp18.setNum(f11at)).append("\nSegunda derivada sencilla=").append(temp19.setNum(f2at));
        temp.append("\nSegunda derivada=").append(temp20.setNum(f22at)).append("\nTercera Derivada sencilla=").append(temp21.setNum(f3at)).append("\nTercera derivada=").append(temp22.setNum(f33at)).append("\nCuarta derivada sencilla=").append(temp23.setNum(f4at)).append("\nCuarta derivada=").append(temp24.setNum(f44at));
        temp.append("\nErrores\nError 1° derivada sencilla=").append(temp25.setNum(err1at)).append("\nError 1° derivada=").append(temp26.setNum(err11at)).append("\nError 2° derivada sencilla=").append(temp27.setNum(err2at)).append("\nError 2° derivada=").append(temp28.setNum(err22at)).append("\nError 3° derivada sencilla=").append(temp29.setNum(err3at)).append("\nError 3° derivada=").append(temp30.setNum(err33at)).append("\nError 4° derivada sencilla=").append(temp31.setNum(err4at)).append("\nError 4° derivada=").append(temp32.setNum(err44at));
        //Derived from forward
        f1ad=(fxM1-fx)/h;
        f11ad=(-fxM2+(4*fxM1)-(3*fx))/(2*h);
        f2ad=(fxM2-(2*fxM1)+fx)/(h*h);
        f22ad=(-fxM3+(4*fxM2)-(5*fxM1)+(2*fx))/(h*h);
        f3ad=(fxM3-(3*fxM2)+(3*fxM1)-fx)/(h*h*h);
        f33ad=(-(3*fxM4)+(14*fxM3)-(24*fxM2)+(18*fxM1)-(5*fx))/(2*(h*h*h));
        f4ad=(fxM4-(4*fxM3)+(6*fxM2)-(4*fxM1)+fx)/(h*h*h*h);
        f44ad=(-(2*fxM5)+(11*fxM4)-(24*fxM3)+(26*fxM2)-(14*fxM1)+(3*fx))/(h*h*h*h);
         //Percent errors of forward derivativesm
        err1ad=100*std::abs((f1ad-f11c)/f11c);
        err11ad=100*std::abs((f11ad-f11c)/f11c);
        err2ad=100*std::abs((f2ad-f11c)/f11c);
        err22ad=100*std::abs((f22ad-f11c)/f11c);
        err3ad=100*std::abs((f3ad-f11c)/f11c);
        err33ad=100*std::abs((f33ad-f11c)/f11c);
        err4ad=100*std::abs((f4ad-f11c)/f11c);
        err44ad=100*std::abs((f44ad-f11c)/f11c);
         //Printing Forward Derivative Results
        temp.append("\nDerivada hacia adelante\nPrimera derivada sencilla=").append(temp33.setNum(f1ad)).append("\nPrimera derivada=").append(temp34.setNum(f11ad)).append("\nSegunda derivada sencilla=").append(temp35.setNum(f2ad));
        temp.append("\nSegunda derivada=").append(temp36.setNum(f22ad)).append("\nTercera Derivada sencilla=").append(temp37.setNum(f3ad)).append("\nTercera derivada=").append(temp38.setNum(f33ad)).append("\nCuarta derivada sencilla=").append(temp39.setNum(f4ad)).append("\nCuarta derivada=").append(temp40.setNum(f44ad));
        temp.append("\nErrores\nError 1° derivada sencilla=").append(temp41.setNum(err1ad)).append("\nError 1° derivada=").append(temp42.setNum(err11ad)).append("\nError 2° derivada sencilla=").append(temp43.setNum(err2ad)).append("\nError 2° derivada=").append(temp44.setNum(err22ad)).append("\nError 3° derivada sencilla=").append(temp45.setNum(err3ad)).append("\nError 3° derivada completa=").append(temp46.setNum(err33ad)).append("\nError 4° derivada sencilla=").append(temp47.setNum(err4ad)).append("\nError 4° derivada=").append(temp48.setNum(err44ad));
        ui->textBrowser->setText(temp);
}
void Deriv::limpiar()
{//Clear all fields
    ui->fxm1->setValue(0.0);
    ui->fxm2->setValue(0.0);
    ui->fxm3->setValue(0.0);
    ui->fxm4->setValue(0.0);
    ui->fxm5->setValue(0.0);
    ui->fxM1->setValue(0.0);
    ui->fxM2->setValue(0.0);
    ui->fxM3->setValue(0.0);
    ui->fxM4->setValue(0.0);
    ui->fxM5->setValue(0.0);
    ui->fx->setValue(0.0);
    ui->h->setValue(0.0);
    ui->textBrowser->clear();
}
