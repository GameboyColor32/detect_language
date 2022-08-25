/*
** EPITECH PROJECT, 2021
** program.h
** File description:
** main header file for the language_detect program
*/

#pragma once

// Type safe min macro
#define min(a, b)                               \
    ({ __typeof__ (a) _a = (a);                 \
        __typeof__ (b) _b = (b);                \
        _a < _b ? _a : _b; })

#define concat(a, b) a##b


#define ALPHABET        26
#define NUM_LANGUAGES   24

typedef struct dataset_s {
    char *language;
    char *frequency;
} dataset_t;

static const dataset_t DATASET[NUM_LANGUAGES] = {
    {"English", "etaoinsrhldcumfpgwybvkxjqz"},
    {"French", "esaitnrulodcmpévqfbghjàxèyêzçôùâûî"},
    {"German", "enisratdhulcgmobwfkzvüpäßjöyqx"},
    {"Spanish", "eaosrnidlctumpbgyívqóhfzjéáñxúüwk"},
    {"Portuguese", "aeosrinmdutlcphvqgfbãzçjáéxóõêôàyíèú"},
    {"Esperanto", "aieonlsrtkjudmpvgfbcĝĉŭzŝhĵĥwyxq"},
    {"Italian", "eaionlrtscdupmvghfbqzòàùì"},
    {"Turkish", "aeinrlıdkmuytsboüşzgçhğvcöpfjwxq"},
    {"Swedish", "eantrslidomgkvähfupåöbcjyxwzéq"},
    {"Polish", "iaeoznscrwyłdkmtpujlgębąhżśóćńfźvqx"},
    {"Dutch", "enatirodslghvkmubpwjczfxy"},
    {"Danish", "enadtrslgiohmkvufbpøaejycéxqwèzüàóêçaaëä"},
    {"Icelandic", "anriestudhlgmkfhvoáthídjóbyæúöpéýcxwzq"},
    {"Finnish", "enatrsildokgmvfaauphäcböjyxzw"},
    {"Czech", "oeantivlsrdkupímcházyjbřêéĉžýŝũgfúňwďóxť"},
    {"Norwegian", "erntsilakodgmvfupbhøjyaaæcwzx"},
    {"Hungarian", "eatlnskomzrigáéydbvhjo:fupöócu:íúüxw"},
    {"Slovak", "aoesnitrvlkdmcupzyhjgfb"},
    {"Hawaiian", "aiko’enuhlmâpôwêûî"},
    {"Maori", "aiketonuhrmwgp"},
    {"Latin", "eituasrnomcpldqbgvfhxyk"},
    {"Irish", "aihnretscoldgumbáfíéúópvjwykqz"},
    {"Welsh", "ayndreiloghwtfuscmbpâôy^w^jïêáqvî"},
    {"Gaelic", "aihndercsgloutmbàfpo`ùéi`èó"},
};

//sort.c
char *get_frequency_order(unsigned char tab[ALPHABET]);

//levenshtein.c
int levenshtein_distance(char *s1, char *s2);

//detect_lang.c
int find_language(char *arg);

//load_file.c
char *read_file(char *filepath);

//unit_tests
void redirect_all_std(void);

//utils.c
void help(void);
