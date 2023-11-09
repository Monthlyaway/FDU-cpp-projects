#include "SparseMatrix.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int array1[3][3] = {
        {0, 0, 0},
        {0, 5, 0},
        {0, 0, 0}
    };

    int array2[3][3] = {
        {1, 0, 0},
        {0, 0, 2},
        {0, 3, 0}
    };

    SparseMatrix matrix1(array1, 3, 3);
    SparseMatrix matrix2(array2, 3, 3);

    cout << "Sparse Matrix 1:" << endl;
    cout << matrix1;

    cout << "\nSparse Matrix 2:" << endl;
    cout << matrix2;

    return 0;
}
