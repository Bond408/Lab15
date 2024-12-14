#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#define ROWS 100
#define COLS 100

int main() {
    int row, col;

    printf("Задайте параметр i (не больше %d): ", ROWS);
    scanf("%d", &row);

    printf("Задайте параметр j (не больше %d): ", COLS);
    scanf("%d", &col);

    double array[ROWS][COLS];

    printf("    "); //1, 2
    for (int j = 0; j < col; j++) {
        printf("%6d", j); 
    }
    printf("\n");

    printf("    ");
    for (int j = 0; j < col; j++) {
        printf("-------");
    }
    printf("\n");


    for (int i = 0; i < row; i++) {
        printf("%d |", i);
        for (int j = 0; j < col; j++) {
            if (j == 0)
                array[i][j] = 0.0;
            else {
                array[i][j] = (double)i / j;
            }
            printf("%6.2lf ", array[i][j]);
        }
        printf("\n");
    }
   
    printf("    "); //3(4)
    for (int j = 0; j < col; j++) {
        printf("%6d", j);
    }
    printf("\n");

    printf("    ");
    for (int j = 0; j < col; j++) {
        printf("-------");
    }
    printf("\n");


    for (int i = 0; i < row; i++) {
        printf("%d |", i);
        for (int j = 0; j < col; j++) {
            if (j == 0)
                array[i][j] = 0.0;
            else {
                array[i][j] = (double)i / j;
            }
            if (i == 0 && j == 0) {
                printf("%6.2lf ", array[0][0]);
            }
        }
        printf("\n");
    }

    int str_min; //4а
    printf("\nВведите номер строки для поиска минимального элемента: ");
    scanf("%d", &str_min);

    if (str_min >= 0 && str_min < row) {
        double min = 100000;
        for (int j = 0; j < col; j++) {
            if (array[str_min][j] < min) {
                min = array[str_min][j];
            }
        }
        printf("Минимальный элемент в строке %d: %.2lf\n", str_min, min);
    }

    int col_max; //4б
    printf("\nВведите номер столбца для поиска максимального элемента: ");
    scanf("%d", &col_max);

    if (col_max >= 0 && col_max < row) {
        double max = -100000;
        for (int i = 0; i < row; i++) {
            if (array[i][col_max] > max) {
                max = array[i][col_max];
            }
        }
        printf("Максимальный элемент в столбце %d: %.2lf\n", col_max, max);
    }

    double diagonal; //4в
    printf("\nВведите значение для поиска на главной диагонали: ");
    scanf("%lf", &diagonal);

    int found = 0;
    int size = (row < col) ? row : col;
    for (int i = 0; i < size; i++) {
        if (array[i][i] == diagonal) {
            printf("Значение %lf найдено на диагонали в позиции [%d][%d]\n", diagonal, i, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Значения %lf нет на главной диагонали.\n", diagonal);
    }

}
