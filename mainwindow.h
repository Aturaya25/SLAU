#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix.h"
#include <QDebug>
#include "gaussmetod.h"
#include "kramermetod.h"
#include "jacobi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbMatrix_clicked();
    void changeEq();
    void on_pbGaussMetod_clicked();
    void error_throw(QString _error);

    void on_pbKramerMetod_clicked();

    void on_pbJacobiMetod_clicked();

private:
    Ui::MainWindow *ui;
    Matrix *matrix = new Matrix();
    bool isError = false;
};
#endif // MAINWINDOW_H
