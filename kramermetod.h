#ifndef KRAMERMETOD_H
#define KRAMERMETOD_H

#include <QObject>
#include "matrix.h"

class KramerMetod: public QObject
{
    Q_OBJECT
public:
    KramerMetod(Matrix *_m);
    double getDet();

    double *solutionByKramerMetod();
signals:
    void noSolution(QString _error);
private:
    Matrix *_matrix;
    double determinant(double **matrix, unsigned int n);
    double **submatrix(double **matrix, unsigned int n, unsigned int x, unsigned int y);
    double **a, *y;
    int n = _matrix->rowCount();
};

#endif // KRAMERMETOD_H
