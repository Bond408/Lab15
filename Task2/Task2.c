#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define ROWS 7
#define COLS 7

void fill_array(int array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = rand() % 15 - 10;
        }
    }
}

void print_array(int array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}

void transpose_array(int array[ROWS][COLS], int transposed[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transposed[j][i] = array[i][j];
        }
    }
}

int count_of_elements_of_the_second_col_lower_than_minus_five(int array[ROWS][COLS]) {
    int c = 0;
    for (int i = 0; i < ROWS; i++) {
        if (array[i][1] < -5) {
            c++;

        }
    }
    return c;
}

int equal_cols(int array[ROWS][COLS]) {
    int c = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 1; j++) {
            if (array[i][j] == array[i][j + 1]) {
                c++;
            }
        }
    }
    return c;
}

int equal_rows(int array[ROWS][COLS]) {
    int c = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 1; j++) {
            if (array[i][j] == array[i + 1][j]) {
                c++;
            }
        }
    }
    return c;
}

int equal_all(int array[ROWS][COLS]) {
    int c = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 1; j++) {
            if (array[i][j] == array[i + 1][j + 1]) {
                c++;
            }
        }
    }
    for (int j = 0; j < ROWS; j++) {
        for (int i = 0; i < COLS - 1; i++) {
            if (array[i][j] == array[i + 1][j]) {
                c++;
            }
        }
    }
    return c;
}

int find_max_coordinates(int array[ROWS][COLS], int* max_row, int* max_col) {
    int max_value = array[0][0];
    *max_row = 0;
    *max_col = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] > max_value) { 
                max_value = array[i][j];
                *max_row = i;
                *max_col = j;
            }
    
            else if (array[i][j] == max_value && i > *max_row) {
                *max_row = i;
                *max_col = j;
            }
        }
    }
}

int main(void) {

    int array[ROWS][COLS];
    int transposed[ROWS][COLS]; 

    fill_array(array);
    printf("Исходный массив: \n");
    print_array(array);

    transpose_array(array, transposed);

    printf("Транспонированный массив: \n");
    print_array(transposed);
    
    int minus_five = count_of_elements_of_the_second_col_lower_than_minus_five(array);
    printf("Элементов во 2 столбце < -5: %d\n", minus_five);
    
    int eq_rows = equal_rows(array);
    int eq_cols = equal_cols(array);
    int eq_all = equal_all(array);

    int max_row, max_col;
    printf("Число пар элементов, расположенных в одной строке: %d\nЧисло пар элементов, расположенных в одном столбце: %d\nЧисло пар элементов, расположенных в одном столбце и строке: %d\n", eq_cols, eq_rows, eq_all);
    int coordinates_max_elem = find_max_coordinates(array, &max_row, &max_col);
    printf("Максимальный элемент расположен в строке %d, столбце %d\n", max_row, max_col);
}