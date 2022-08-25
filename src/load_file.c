/*
** EPITECH PROJECT, 2022
** load_file.cù
** File description:
** source file for loading a file to a buffer
*/

#include <stdio.h>
#include <stdlib.h>

char *read_file(char *filepath)
{
    char *buffer = 0;
    long length;
    FILE *fd = fopen(filepath, "rb");

    if (fd == NULL)
        return (NULL);
    fseek(fd, 0, SEEK_END);
    length = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    if ((buffer = malloc(sizeof(char) * (length + 1))) == NULL) {
        fclose(fd);
        return (NULL);
    }
    fread(buffer, 1, length, fd);
    fclose (fd);
    buffer[length] = '\0';
#ifdef HARD_DEBUG
    printf("%s\n\n\n", file_contents);
#endif
    return (buffer);
}
