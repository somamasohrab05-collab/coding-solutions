
#include <stdlib.h>

int** matrixReshape(int** mat, int matSize,
                    int* matColSize, int r, int c,
                    int* returnSize,
                    int** returnColumnSizes) {

    int m = matSize;
    int n = matColSize[0];

    // Check whether reshaping is possible
    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = malloc(m * sizeof(int));

        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = n;
        }

        return mat;
    }

    int** result = malloc(r * sizeof(int*));

    *returnSize = r;
    *returnColumnSizes = malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        result[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    // Copy elements in order
    for (int i = 0; i < m * n; i++) {
        result[i / c][i % c] = mat[i / n][i % n];
    }

    return result;
}
