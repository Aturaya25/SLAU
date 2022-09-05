#ifndef JACOBI_H
#define JACOBI_H

#include <QObject>
#include "matrix.h"
#include <math.h>
const double eps = 0.1;

class Jacobi : public QObject
{
    Q_OBJECT
public:
    Jacobi(Matrix *_m);

    double *getAnswer();
private:
    Matrix *_matrix;
    double *jacobi(double **a, double *y, int n);
    double **a, *y;
    int n = _matrix->rowCount();
};

#endif // JACOBI_H
