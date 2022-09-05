#include "kramermetod.h"

KramerMetod::KramerMetod(Matrix *_m):
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


double KramerMetod::getDet(){
    return determinant(a, n);
}


double **KramerMetod::submatrix(double **matrix, unsigned int n, unsigned int x, unsigned int y) {
    double **submatrix = new double *[n - 1];
    int subi = 0;
    for (int i = 0; i < n; i++) {
        submatrix[subi] = new double[n - 1];
        int subj = 0;
        if (i == y) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j == x) {
                continue;
            }
            submatrix[subi][subj] = matrix[i][j];
            subj++;
        }
        subi++;
    }
    return submatrix;
}

double KramerMetod::determinant(double **matrix, unsigned int n) {
    int det = 0;
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    for (int x = 0; x < n; ++x) {
        det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix(matrix, n, x, 0), n - 1));
    }
    return det;
}


double * KramerMetod::solutionByKramerMetod(){
    double * x_value = new double[n];
    int detA = determinant(a, n);
    if (detA == 0){
            QString _error = "Система не имеет решений";
            emit(noSolution(_error));
            return 0;
    }
    else{
        for(int i = 0; i < n; i++){
            double** optA = new double*[n];
            for (int optIndexR = 0; optIndexR < n; optIndexR ++){
                optA[optIndexR] = new double[n];
                for (int optIndexC = 0; optIndexC < n; optIndexC ++){
                    optA[optIndexR][optIndexC] = a[optIndexR][optIndexC];
                }
            }
            for(int j = 0; j < n; j++){
                optA[j][i] = y[j];
            }
            x_value[i] = (double)determinant(optA, n) / (double)detA;
        }
    }
    return x_value;
}
