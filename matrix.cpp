#include "matrix.h"
#include "ui_matrix.h"

Matrix::Matrix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Matrix)
{
    ui->setupUi(this);
    this->setWindowTitle("Матрица");
    ui->twMatrix->setRowCount(3);
    ui->twMatrix->setColumnCount(4);
    for(int i = 0; i < ui->twMatrix->rowCount(); i++){
        for(int j = 0; j < ui->twMatrix->columnCount(); j++){
            ui->twMatrix->setCellWidget(i,j, initCellMatrix());
        }
    }
    updateHeaderLabels();
}

int Matrix::rowCount()
{
    return ui->twMatrix->rowCount();
}

int Matrix::columnCount()
{
    return ui->twMatrix->columnCount();
}

double Matrix::getValue(int row, int column)
{
    auto tmpDSbox = qobject_cast<QDoubleSpinBox*>(ui->twMatrix->cellWidget(row,column));
    if (tmpDSbox){
        return tmpDSbox->value();
    }
    else{
        throw "No Value";
    }
}

Matrix::~Matrix()
{
    delete ui;
}


void Matrix::updateHeaderLabels(){
    for (int j = 0; j < ui->twMatrix->columnCount(); j++){
        QString varName;
        if (j == ui->twMatrix->columnCount()-1){ varName = "y";}
        else{ varName = "x" + QString::number(j);}
        QTableWidgetItem *name = new QTableWidgetItem(varName);
        ui->twMatrix->setHorizontalHeaderItem(j, name);
    }
}


QWidget* Matrix::initCellMatrix(){
    auto cell = new QDoubleSpinBox();
    cell->setValue(0);
    cell->setButtonSymbols(QAbstractSpinBox::NoButtons);
    cell->setRange(0, 10000);
    return cell;
}

void Matrix::on_pbcolumnAdd_clicked()
{
    ui->twMatrix->insertRow(ui->twMatrix->rowCount());
    for (int i = 0; i < ui->twMatrix->columnCount(); i++){
        ui->twMatrix->setCellWidget(ui->twMatrix->rowCount()-1, i, initCellMatrix());
    }
}

void Matrix::on_pbcolumnDel_clicked()
{
    ui->twMatrix->removeRow(ui->twMatrix->rowCount() - 1);
}

void Matrix::on_pbrowAdd_clicked()
{
    ui->twMatrix->insertColumn(ui->twMatrix->columnCount());
    for (int i = 0; i < ui->twMatrix->rowCount(); i++){
        ui->twMatrix->setCellWidget(i, ui->twMatrix->columnCount()-1, initCellMatrix());
    }
    updateHeaderLabels();
}

void Matrix::on_pbRowDel_clicked()
{
    ui->twMatrix->removeColumn(ui->twMatrix->columnCount() - 1);
    updateHeaderLabels();
}



void Matrix::on_pbOk_clicked()
{
    emit(editFinish());
    close();
}
