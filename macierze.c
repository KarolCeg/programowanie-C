#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Struktura reprezentująca macierz
typedef struct {
    int rows;
    int cols;
    double data[MAX_ROWS][MAX_COLS];
} Matrix;

// Funkcja do wczytywania danych do macierzy
void inputMatrix(Matrix *mat) {
    printf("Wprowadź elementy macierzy %d x %d:\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            scanf("%lf", &mat->data[i][j]);
        }
    }
}

// Funkcja do obliczania ilorazu dwóch macierzy
Matrix matrixDivision(Matrix mat1, Matrix mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        printf("Nie można obliczyć ilorazu. Macierze mają różne rozmiary.\n");
        exit(1);
    }

    Matrix result;
    result.rows = mat1.rows;
    result.cols = mat1.cols;

    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            if (mat2.data[i][j] == 0.0) {
                printf("Nie można dzielić przez zero. Operacja anulowana.\n");
                exit(1);
            }
            result.data[i][j] = mat1.data[i][j] / mat2.data[i][j];
        }
    }
    return result;
}

int main() {
    int rows, cols;
    printf("Podaj liczbę wierszy macierzy: ");
    scanf("%d", &rows);
    printf("Podaj liczbę kolumn macierzy: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Rozmiar macierzy jest zbyt duży. Maksymalne rozmiary to %dx%d.\n", MAX_ROWS, MAX_COLS);
        return 1;
    }

    Matrix matrix1;
    matrix1.rows = rows;
    matrix1.cols = cols;

    Matrix matrix2;
    matrix2.rows = rows;
    matrix2.cols = cols;

    printf("Macierz 1:\n");
    inputMatrix(&matrix1);
    printf("Macierz 2:\n");
    inputMatrix(&matrix2);

    printf("Macierz 1:\n");
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            printf("%.2lf\t", matrix1.data[i][j]);
        }
        printf("\n");
    }

    printf("Macierz 2:\n");
    for (int i = 0; i < matrix2.rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
            printf("%.2lf\t", matrix2.data[i][j]);
        }
        printf("\n");
    }

    Matrix result = matrixDivision(matrix1, matrix2);

    printf("Wynik dzielenia macierzy:\n");
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            printf("%.2lf\t", result.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}