/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-axel.petitjean
** File description:
** main_bis
*/

#include "../include/my.h"

void description(void)
{
    my_printf("Bienvenue dans mon My Hunter\n");
    my_printf("Objectif:\nDes chauves-souris vont apparaitre. ");
    my_printf("A toi d'en tuer un MAX !!\n");
    my_printf("ATTENTION, tu n'as que 3 vies, donc fait attention. ");
    my_printf("En plus, les monstres arrivent de plus en plus vite.\n");
    my_printf("Ton score s'affichera dans le terminal\n");
    my_printf("BONNE CHANCE ^^\n");
}

void main_last(sfRenderWindow const *window, sfEvent event, sfSprite *sprite,
sfSprite *texture03, sfSprite *start, sfTexture *texture02,
sfVector2f scale_start, sfVector2f scale_help, sfVector2f scale_quit,
sfVector2f scale, sfSprite *quit, sfSprite *help, sfTexture *texture04,
sfVideoMode mode)
{
    if (!window)
        return (84);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            condition(window, event);
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, start, NULL);
        sfRenderWindow_drawSprite(window, quit, NULL);
        sfRenderWindow_drawSprite(window, help, NULL);
        sfRenderWindow_display(window);
        clik(window, event);
    }
}

void main_ter(sfRenderWindow const *window, sfEvent event, sfSprite *sprite,
sfSprite *texture03, sfSprite *start, sfTexture *texture02,
sfVector2f scale_start, sfVector2f scale_help, sfVector2f scale_quit,
sfVector2f scale, sfSprite *quit, sfSprite *help, sfTexture *texture04,
sfVideoMode mode)
{
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(start, texture02, sfTrue);
    sfSprite_setScale(start, scale_start);
    sfSprite_setTexture(quit, texture03, sfTrue);
    sfSprite_setScale(quit, scale_quit);
    sfSprite_setTexture(help, texture04, sfTrue);
    sfSprite_setScale(help, scale_help);
    window = SFWC(mode, "My Hunter", sfResize | sfClose, NULL);
    main_last(window, event, sprite, texture03, start, texture02, scale_start,
    scale_help, scale_quit, scale, quit, help, texture04, mode);

}

void main_bis(void)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfRenderWindow *window; sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("./image/menu.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture02 = sfTexture_createFromFile("./image/strt.png", NULL);
    sfSprite *start = sfSprite_create();
    sfTexture *texture03 = sfTexture_createFromFile("./image/quit.png", NULL);
    sfSprite *quit = sfSprite_create();
    sfTexture *texture04 = sfTexture_createFromFile("./image/help.png", NULL);
    sfSprite *help = sfSprite_create();
    sfVector2f scale = {1, 1}; sfVector2f scale_start = {1.5, 1.5};
    sfVector2f position_start = {850, 780}; sfVector2f scale_quit = {1.5, 1.5};
    sfVector2f position_quit = {1400, 790}; sfVector2f scale_help = {1.5, 1.5};
    sfVector2f position_help = {300, 750};
    sfSprite_setPosition(start, position_start);
    sfSprite_setPosition(quit, position_quit);
    sfSprite_setPosition(help, position_help);
    sfSprite_setTexture(sprite, texture, sfTrue);
    main_ter(window, event, sprite, texture03, start, texture02, scale_start,
    scale_help, scale_quit, scale, quit, help, texture04, mode);
}
