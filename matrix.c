#define MAX_SIZE 10

// Structure to represent a matrix
struct Matrix {
    int rows;
    int cols;
    float data[MAX_SIZE][MAX_SIZE];
};

// Function to display a matrix
void displayMatrix(struct Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%.2f\t", mat.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
struct Matrix matrixAddition(struct Matrix mat1, struct Matrix mat2) {
    struct Matrix result;
    result.rows = mat1.rows;
    result.cols = mat1.cols;

    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
struct Matrix matrixSubtraction(struct Matrix mat1, struct Matrix mat2) {
    struct Matrix result;
    result.rows = mat1.rows;
    result.cols = mat1.cols;

    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices
struct Matrix matrixMultiplication(struct Matrix mat1, struct Matrix mat2) {
    struct Matrix result;
    result.rows = mat1.rows;
    result.cols = mat2.cols;

    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < mat1.cols; k++) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }

    return result;
}

// Function to calculate the determinant of a 2x2 matrix
float matrixDeterminant2x2(struct Matrix mat) {
    return mat.data[0][0] * mat.data[1][1] - mat.data[0][1] * mat.data[1][0];
}

// Function to calculate the determinant of a matrix
float matrixDeterminant(struct Matrix mat) {
    if (mat.rows != mat.cols || (mat.rows != 2 && mat.rows != 3)) {
        printf("Error: Determinant calculation only supports 2x2 or 3x3 matrices.\n");
        return 0;
    }

    if (mat.rows == 2) {
        return matrixDeterminant2x2(mat);
    } else { // 3x3 matrix determinant calculation
        return (mat.data[0][0] * mat.data[1][1] * mat.data[2][2]) +
               (mat.data[0][1] * mat.data[1][2] * mat.data[2][0]) +
               (mat.data[0][2] * mat.data[1][0] * mat.data[2][1]) -
               (mat.data[0][2] * mat.data[1][1] * mat.data[2][0]) -
               (mat.data[0][0] * mat.data[1][2] * mat.data[2][1]) -
               (mat.data[0][1] * mat.data[1][0] * mat.data[2][2]);
    }
}

// ... (Other matrix operations and structures like Eigen values/vectors, inverse, adjoint, etc. can be implemented similarly)
