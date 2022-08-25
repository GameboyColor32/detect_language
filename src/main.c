/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file for language_detecpute program
*/

#include <stdlib.h>
#include <stdio.h>

#include "program.h"

int main(int ac, char **av)
{
    char *file_contents;

    if (ac < 2)
        return (EXIT_FAILURE);
    if ((file_contents = read_file(av[1])) == NULL)
        return (EXIT_FAILURE);
    return (find_language(file_contents));
}
