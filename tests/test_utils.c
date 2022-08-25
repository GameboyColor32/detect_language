/*
** EPITECH PROJECT, 2021
** test_utils.c
** File description:
** file for testing the utility file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "program.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(levenshtein_distance, lev1)
{
    cr_expect(levenshtein_distance("abc", "yabd") == 2, "Expected 2");
    cr_expect(levenshtein_distance("", "") == 0, "Expected 0");
    cr_expect(levenshtein_distance(NULL, NULL) == -1, "Expected -1");
    cr_expect(levenshtein_distance("", "abc") == 3, "Expected 3");
    cr_expect(levenshtein_distance("abc", "abc") == 0, "Expected 0");
    cr_expect(levenshtein_distance("bright", "bright") == 0, "Expected 2");
    cr_expect(levenshtein_distance("bright", "freight") == 2, "Expected 2");
    cr_expect(levenshtein_distance("bright", "sleight") == 3, "Expected 3");
    cr_expect(levenshtein_distance("bright", "bride") == 3, "Expected 3");
    cr_expect(levenshtein_distance("bright", "plight") == 2, "Expected 2");
    cr_expect(levenshtein_distance("bright", "pride") == 4, "Expected 4");
    cr_expect(levenshtein_distance("bright", "donald duck") == 11, "Expected 11");
}
