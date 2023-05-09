/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-axel.petitjean
** File description:
** my_put_table
*/
#include "../include/my.h"

int my_put_table(char **str, char **final_map)
{
    int i = 0;
    int nb;
    while (final_map[0][i] != '\n')
        nb = nb + 1;
    while (i < nb) {
        my_putstr(str[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
