/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
    #define __MY_H__

    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <ncurses.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include "struct.h"

    #define SFCF sfTexture_createFromFile
    #define SFWC sfRenderWindow_create

    int my_printf(const char *format, ...);
    int my_put_nbr(int n);
    void my_putchar(char c);
    int my_putstr(char const *str);
    int str_to_int(char *str);
    int my_put_table(char **str, char **final_map);
    int my_strlen(const char str[]);
    void game_function(sfRenderWindow *window, sfEvent event);
    void game_help(sfRenderWindow *window, sfEvent event);
    void main_bis(void);
    void description(void);
    void clik(sfRenderWindow *window, sfEvent event);

#endif /* !__MY_H__ */
