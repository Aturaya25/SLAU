#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QDebug>

namespace Ui {
class Matrix;
}

class Matrix : public QWidget
{
    Q_OBJECT

public:
    explicit Matrix(QWidget *parent = nullptr);
    int rowCount();
    int columnCount();
    double getValue(int row, int column);
    ~Matrix();

signals:
    void editFinish();

private slots:
    void on_pbcolumnAdd_clicked();

    void on_pbcolumnDel_clicked();

    void on_pbrowAdd_clicked();

    void on_pbRowDel_clicked();

    void on_pbOk_clicked();

private:
    Ui::Matrix *ui;
    QWidget *initCellMatrix();
    QWidget * initEqual();
    void updateHeaderLabels();
};

#endif // MATRIX_H
