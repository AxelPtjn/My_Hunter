/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-axel.petitjean
** File description:
** game_help
*/

#include "../include/my.h"
void game_help_bis(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

void game_help(sfRenderWindow *window, sfEvent event)
{
    sfTexture *texture = sfTexture_createFromFile("./image/menu.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfTexture *help = sfTexture_createFromFile("./image/help_page.png", NULL);
    sfSprite *sprite_help = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite_help, help, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        game_help_bis(window, event);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite_help, NULL);
        sfRenderWindow_display(window);
    }
}
