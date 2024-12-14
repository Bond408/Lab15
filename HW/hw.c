#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ROWS 25   
#define COLS 36  

int count_sold_tickets_in_row(int array[ROWS][COLS], int row) {
    int count = 0;
    for (int col = 0; col < COLS; col++) {
        if (array[row][col] == 1) {
            count++;
        }
    }
    return count;
}

int main(void) {
    setlocale(LC_ALL, "RUS");

    int hall[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            hall[i][j] = rand() % 2;
        }
    }

    printf("Места в 12 ряду:\n");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", hall[11][j]);
    }
    printf("\n");

    int sold_tickets = count_sold_tickets_in_row(hall, 11);

    printf("Число проданных билетов в 12 ряду: %d\n", sold_tickets);
}