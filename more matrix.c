// Function to calculate the inverse of a 2x2 matrix
struct Matrix matrixInverse2x2(struct Matrix mat) {
    struct Matrix result;
    result.rows = mat.rows;
    result.cols = mat.cols;

    float det = matrixDeterminant2x2(mat);
    if (det == 0) {
        printf("Error: Matrix is singular, cannot find inverse.\n");
        return result; // Return an empty matrix
    }

    float invDet = 1 / det;
    result.data[0][0] = mat.data[1][1] * invDet;
    result.data[0][1] = -mat.data[0][1] * invDet;
    result.data[1][0] = -mat.data[1][0] * invDet;
    result.data[1][1] = mat.data[0][0] * invDet;

    return result;
}

// Function to calculate the inverse of a 3x3 matrix
struct Matrix matrixInverse3x3(struct Matrix mat) {
    struct Matrix result;
    result.rows = mat.rows;
    result.cols = mat.cols;

    float det = matrixDeterminant(mat);
    if (det == 0) {
        printf("Error: Matrix is singular, cannot find inverse.\n");
        return result; // Return an empty matrix
    }

    float invDet = 1 / det;
    result.data[0][0] = (mat.data[1][1] * mat.data[2][2] - mat.data[1][2] * mat.data[2][1]) * invDet;
    result.data[0][1] = (mat.data[0][2] * mat.data[2][1] - mat.data[0][1] * mat.data[2][2]) * invDet;
    result.data[0][2] = (mat.data[0][1] * mat.data[1][2] - mat.data[0][2] * mat.data[1][1]) * invDet;
    result.data[1][0] = (mat.data[1][2] * mat.data[2][0] - mat.data[1][0] * mat.data[2][2]) * invDet;
    result.data[1][1] = (mat.data[0][0] * mat.data[2][2] - mat.data[0][2] * mat.data[2][0]) * invDet;
    result.data[1][2] = (mat.data[0][2] * mat.data[1][0] - mat.data[0][0] * mat.data[1][2]) * invDet;
    result.data[2][0] = (mat.data[1][0] * mat.data[2][1] - mat.data[1][1] * mat.data[2][0]) * invDet;
    result.data[2][1] = (mat.data[0][1] * mat.data[2][0] - mat.data[0][0] * mat.data[2][1]) * invDet;
    result.data[2][2] = (mat.data[0][0] * mat.data[1][1] - mat.data[0][1] * mat.data[1][0]) * invDet;

    return result;
}

// Function to calculate the adjoint of a matrix
struct Matrix matrixAdjoint(struct Matrix mat) {
    struct Matrix result;
    result.rows = mat.rows;
    result.cols = mat.cols;

    if (mat.rows == 2 && mat.cols == 2) {
        result.data[0][0] = mat.data[1][1];
        result.data[0][1] = -mat.data[0][1];
        result.data[1][0] = -mat.data[1][0];
        result.data[1][1] = mat.data[0][0];
    } else if (mat.rows == 3 && mat.cols == 3) {
        // Calculate cofactors
        struct Matrix cofactors;
        cofactors.rows = 3;
        cofactors.cols = 3;

        cofactors.data[0][0] = mat.data[1][1] * mat.data[2][2] - mat.data[1][2] * mat.data[2][1];
        cofactors.data[0][1] = mat.data[0][2] * mat.data[2][1] - mat.data[0][1] * mat.data[2][2];
        cofactors.data[0][2] = mat.data[0][1] * mat.data[1][2] - mat.data[0][2] * mat.data[1][1];
        cofactors.data[1][0] = mat.data[1][2] * mat.data[2][0] - mat.data[1][0] * mat.data[2][2];
        cofactors.data[1][1] = mat.data[0][0] * mat.data[2][2] - mat.data[0][2] * mat.data[2][0];
        cofactors.data[1][2] = mat.data[0][2] * mat.data[1][0
