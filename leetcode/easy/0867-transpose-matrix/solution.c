
int** transpose(int** matrix, int matrixSize,
                int* matrixColSize,
                int* returnSize,
                int** returnColumnSizes) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    int** result = malloc(cols * sizeof(int*));

    *returnSize = cols;

    *returnColumnSizes = malloc(cols * sizeof(int));

    for (int i = 0; i < cols; i++) {

        result[i] = malloc(rows * sizeof(int));

        (*returnColumnSizes)[i] = rows;

        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}
