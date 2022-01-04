#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

public slots:
    void cent_conv(int i);
    void fahr_conv(int i);
    void kelv_conv(int i);

private:
    Ui::Ventana *ui;
};
#endif // VENTANA_H
