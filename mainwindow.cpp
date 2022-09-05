#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Решение СЛАУ");
    changeEq();
    connect(matrix, SIGNAL(editFinish()), this, SLOT(changeEq()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbMatrix_clicked()
{
    matrix->show();
}

void MainWindow::changeEq()
{
    ui->lResult->clear();
    QString equal;
    int n = matrix->rowCount();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if(j == matrix->rowCount()){
                equal += " = " + QString::number(matrix->getValue(i,j));
                equal += '\n';
            }
            else{
                if(j != 0){
                    equal += " + ";
                }
                equal += QString::number(matrix->getValue(i,j)) + " * x" + QString::number(j);
            }
        }
    }
    ui->leq->setText(equal);
}

void MainWindow::error_throw(QString _error)
{
    ui->lResult->setText(_error);
    ui->lResult->setStyleSheet("color: rgb(215, 0, 0)");
    isError = true;
}

void MainWindow::on_pbGaussMetod_clicked()
{
    GaussMetod *gaus = new GaussMetod(matrix);
    connect(gaus, SIGNAL(allDiagonal(QString)), this, SLOT(error_throw(QString)));
    QString answer;
    auto x_value = gaus->getAnswer();
    if(not isError){
        for (int i = 0; i < matrix->rowCount(); i++)
            answer += "x[" + QString::number(i) + "] = " + QString::number(x_value[i]) + '\n';
        ui->lResult->setText(answer);
        ui->lResult->setStyleSheet("color: rgb(0, 0, 0)");
    }
    else{
        isError = false;
    }
    delete gaus;
}



void MainWindow::on_pbKramerMetod_clicked()
{
    KramerMetod *kramer = new KramerMetod(matrix);
    connect(kramer, SIGNAL(noSolution(QString)), this, SLOT(error_throw(QString)));
    QString answer;
    auto x_value = kramer->solutionByKramerMetod();
    if(not isError){
        for (int i = 0; i < matrix->rowCount(); i++)
            answer += "x[" + QString::number(i) + "] = " + QString::number(x_value[i]) + '\n';
        ui->lResult->setText(answer);
        ui->lResult->setStyleSheet("color: rgb(0, 0, 0)");
    }
    else{
        isError = false;
    }
    delete kramer;
}

void MainWindow::on_pbJacobiMetod_clicked()
{
    Jacobi *jacobi = new Jacobi(matrix);
//    connect(kramer, SIGNAL(noSolution(QString)), this, SLOT(error_throw(QString)));
    QString answer;
    auto x_value = jacobi->getAnswer();
//    if(not isError){
        for (int i = 0; i < matrix->rowCount(); i++)
            answer += "x[" + QString::number(i) + "] = " + QString::number(x_value[i]) + '\n';
        ui->lResult->setText(answer);
        ui->lResult->setStyleSheet("color: rgb(0, 0, 0)");
//    }
//    else{
//        isError = false;
//    }
    delete jacobi;
}
