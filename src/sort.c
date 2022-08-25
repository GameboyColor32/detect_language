/*
** PROJECT, 2022
** sort.c
** File description:
** source file implementing the selection sort
*/

#include <stdlib.h>
#include <stdio.h>

#include "program.h"

int get_next_freq(unsigned char tab_placeholder[ALPHABET])
{
    int index = -1;
    int last_max = 0;

    for (int i = 0; i < ALPHABET; i += 1) {
        if (tab_placeholder[i] > last_max) {
            last_max = tab_placeholder[i];
            index = i;
	}
    }
    return (index);
}

char *get_frequency_order(unsigned char tab[ALPHABET])
{
    char *frequency_str = calloc(1, sizeof(char) * ALPHABET + 1);
    int last_idx = 0;
    int i = 0;

    if (frequency_str == NULL)
	return (NULL);
    while ((last_idx = get_next_freq(tab)) != -1) {
        frequency_str[i] = last_idx + 97;
        tab[last_idx] = 0;
	i += 1;
    }
    return (frequency_str);
}
