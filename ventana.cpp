#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    // Conectar dial de Centigrados con el slot de esta clase
    connect(ui->in_cent, SIGNAL(valueChanged(int)),
            this, SLOT(cent_conv(int)));

    // Conectar dial de Fahrengeit con el slot
    connect(ui->in_fahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr_conv(int)));

    // Conectar dial de Kelvin con el slot
    connect(ui->in_kelvin, SIGNAL(valueChanged(int)),
            this, SLOT(kelv_conv(int)));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::cent_conv(int i)
{
    if(ui->in_cent->hasFocus()){
        float fahr = (i * 9.0/5) + 32;
        ui->in_fahr->setValue(fahr);
        float kelvin = i + 273.15;
        ui->in_kelvin->setValue(kelvin);
    }
}

void Ventana::fahr_conv(int i)
{
    if(ui->in_fahr->hasFocus()){
        float cent = (i - 32) * 5.0/9;
        ui->in_cent->setValue(cent);
        float kelvin = (i - 32) * 5.0/9 + 273.15;
        ui->in_kelvin->setValue(kelvin);
    }
}

void Ventana::kelv_conv(int i)
{
    if(ui->in_kelvin->hasFocus()){
        float cent = i - 273.15;
        ui->in_cent->setValue(cent);
        float fahr = (i - 273.15) * 9.0/5 + 32;
        ui->in_fahr->setValue(fahr);
    }
}

