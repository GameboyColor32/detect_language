/*
** PROJECT, 2022
** levenshtein.c
** File description:
** source file for implementing the levenshtein distance algorithm
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "program.h"

void print_matrix(int **matrix, int x, int y)
{
    printf("Levenshtein distance found: \n");
    for (int i = 0; i < y; i += 1) {
        for (int j = 0; j < x; j += 1)
            printf("[%2d]", matrix[i][j]);
        printf("\n");
    }
}

void free_tab(int **matrix, int y)
{
    for (int i = 0; i < y; i += 1)
        free(matrix[i]);
    free(matrix);
}

int levenshtein_distance(char *s1, char *s2)
{
    int y;
    int x;
    int result;
    int **matrix;

    if (s1 == NULL || s2 == NULL)
        return (-1);
    y = strlen(s2) + 1;
    if ((matrix = malloc(sizeof(int *) * y)) == NULL)
        return (-1);
    x = strlen(s1) + 1;
    for (int i = 0; i < y; i += 1) {
        if ((matrix[i] = malloc(sizeof(int) * x)) == NULL)
            return (-1);
        for (int j = 0; j < x; j += 1)
            matrix[i][j] = j;
    }
    for (int i = 1; i < y; i += 1) {
        matrix[i][0] = matrix[i - 1][0] + 1;
        for (int j = 1; j < x; j += 1) {
            matrix[i][j] = (s2[i - 1] == s1[j - 1]) ? matrix[i - 1][j - 1] :
                1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
        }
    }
#ifdef HARD_DEBUG
    print_matrix(matrix, x, y);
#endif
    result = matrix[y - 1][x - 1];
    free_tab(matrix, y);
    return (result);
}
