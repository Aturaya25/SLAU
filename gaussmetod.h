#ifndef GAUSSMETOD_H
#define GAUSSMETOD_H
#include "matrix.h"
#include <QDebug>
#include <iostream>


class GaussMetod : public QObject
{
    Q_OBJECT
public:
    GaussMetod(Matrix *_m);
    double * getAnswer();

signals:
    void allDiagonal(QString _error);


private:
    Matrix *_matrix;
    double *gauss(double **a, double *y, int n);
    double *x_value, **a, *y;
    int n = _matrix->rowCount();
};

#endif // GAUSSMETOD_H
