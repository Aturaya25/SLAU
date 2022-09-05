#include "jacobi.h"

Jacobi::Jacobi(Matrix *_m):
    _matrix(_m)
{
    a = new double*[n];
    y = new double[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new double[n];
        for (int j = 0; j < n+1; j++)
        {
            if(j == _matrix->rowCount()){
                y[i] = _matrix->getValue(i,j);
            }
            else{
                a[i][j] = _matrix->getValue(i,j);
            }
        }
    }
}

double * Jacobi::getAnswer(){
    return jacobi(a, y, n);
}

double *Jacobi::jacobi(double **a, double *y, int n)
{
    double* TempX = new double[n];
    double norm; // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.
    double *x_value = new double[n];
    for (int i = 0; i < n; i++){
        x_value[i] = 1;
    }

    do {
        for (int i = 0; i < n; i++) {
            TempX[i] = y[i];
            for (int g = 0; g < n; g++) {
                if (i != g)
                    TempX[i] -= a[i][g] * x_value[g];
            }
            TempX[i] /= a[i][i];
        }
        norm = fabs(x_value[0] - TempX[0]);
        for (int h = 0; h < n; h++) {
            if (fabs(x_value[h] - TempX[h]) > norm)
                norm = fabs(x_value[h] - TempX[h]);
            x_value[h] = TempX[h];
        }
    } while (norm > eps);
    delete[] TempX;
    return x_value;
}
