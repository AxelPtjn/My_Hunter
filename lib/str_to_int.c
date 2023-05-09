/*
** EPITECH PROJECT, 2022
** str_to_int
** File description:
** str_to_int
*/
#include "../include/my.h"

int str_to_int(char *str)
{
    int res = 0;
    for (int i = 0; str[i]; i++)
        res = res * 10 + str[i] + '0' - 96;
    return res;
}
