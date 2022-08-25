/*
** PROJECT, 2022
** detect_lang.c
** File description:
** source file for implementing the detection of the language
*/

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#include "program.h"

void print_tab(unsigned char tab[ALPHABET], int total)
{
    printf("\nFrequency precision:\n");
    for (int i = 0; i < ALPHABET; i += 1) {
        if (tab[i] != 0)
            printf("%c:%d:(%.2f%%)\n", i + 97, tab[i],
                   (float) ((tab[i] * 100.f) / total));
    }
    printf("\n");
}

char *get_letters(char *str)
{
    unsigned char tab[ALPHABET] = { [0 ... ALPHABET - 1] = 0 };
    int total = 0;

    for (; *str != 0; str += 1) {
        if (isalpha(*str)) {
            total += 1;
            tab[(*str | 0x20) - 97] += 1;
        }
    }
#ifdef LOG_DEBUG
    print_tab(tab, total);
#endif
    return (get_frequency_order(tab));
}


int find_language(char *arg)
{
    char *ordered_freq = get_letters(arg);
    char *matching_lang;
    int best_score;
    int result;
    size_t len;
    char corrected_len[ALPHABET] = { [0 ... ALPHABET - 1] = 0 };

    if (ordered_freq == NULL)
        return (EXIT_FAILURE);
#ifdef LOG_DEBUG
    printf("Frequency found: %s\n\n", ordered_freq);
#endif
    best_score = 1000;
    len = strlen(ordered_freq);
    matching_lang = NULL;
    for (int i = 0; i < NUM_LANGUAGES; i += 1) {
        if (strlen(DATASET[i].frequency) > len) {
            strncpy(corrected_len, DATASET[i].frequency, len);
            result = levenshtein_distance(ordered_freq, corrected_len);
            memset(corrected_len, 0, ALPHABET);
        } else
            result = levenshtein_distance(ordered_freq, DATASET[i].frequency);
#ifdef LOG_DEBUG
        printf("%s:%d\n", DATASET[i].language, result);
#endif
        if (result < best_score) {
            best_score = result;
            matching_lang = DATASET[i].language;
        } else if (result == best_score)
            printf("We may have other possibilities: %s\n", DATASET[i].language);
    }
    if (matching_lang != NULL)
        printf("Found language: %s\n", matching_lang);
    else
        printf("Nothing found!\n");
    return (EXIT_SUCCESS);
}
