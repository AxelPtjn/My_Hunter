/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-axel.petitjean
** File description:
** main
*/

#include "../include/my.h"

void game_function(sfRenderWindow *window, sfEvent event)
{
    int life = 3;
    int compteur = 0;
    float vitesse = 0.9;
    int bat_y = 100;
    float bat_move_x = 50;
    sfTexture *floor_t = sfTexture_createFromFile("./image/map.png", NULL);
    sfSprite *floor_s = sfSprite_create();
    sfTexture *bat_t = sfTexture_createFromFile("./image/bat.png", NULL);
    sfSprite *bat_s = sfSprite_create();
    sfTexture *cible = sfTexture_createFromFile("./image/cible.png", NULL);
    sfSprite *cible_s = sfSprite_create();
    sfVector2f bat_scale = {1.5, 1.5};
    sfVector2f bat_pos = {bat_move_x, bat_y};
    sfIntRect rect;
    sfClock *temps;
    temps = sfClock_create();
    sfTime time;
    float seconde;
    rect.top = 0;
    rect.left = 0;
    rect.width = 80;
    rect.height = 80;
    sfVector2f cible_scale = {0.15, 0.15};
    sfVector2f cible_s_origine = {960, 540};
    sfSprite_setOrigin(cible_s, cible_s_origine);
    sfSprite_setScale(cible_s, cible_scale);
    sfSprite_setTexture(cible_s, cible, sfTrue);
    sfSprite_setPosition(bat_s, bat_pos);
    sfSprite_setTexture(floor_s, floor_t, sfTrue);
    sfSprite_setTexture(bat_s, bat_t, sfTrue);
    sfSprite_setScale(bat_s, bat_scale);
    sfSprite_setPosition(bat_s, bat_pos);
    sfSprite_setTextureRect(bat_s, rect);

    while (sfRenderWindow_isOpen(window)) {
        int touche_cible = 0;
        sfVector2i mouse_cible = sfMouse_getPositionRenderWindow(window);
        sfSprite_setPosition(cible_s, (sfVector2f)
        {mouse_cible.x, mouse_cible.y});
        time = sfClock_getElapsedTime(temps);
        seconde = time.microseconds / 1000000.0;
        if (seconde > 0.2) {
            if (rect.left >= 250)
                rect.left = 0;
            else {
                rect.left += 90;
                sfClock_restart(temps);
            }
        }

        sfVector2i mouse = sfMouse_getPosition(window);

        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        sfSprite_setTextureRect(bat_s, rect);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, floor_s, NULL);
        sfRenderWindow_drawSprite(window, cible_s, NULL);
        sfRenderWindow_drawSprite(window, bat_s, NULL);
        sfVector2f bat_pos = {bat_move_x, bat_y};

        if (bat_move_x >= 1900) {
            life = life - 1;
            bat_move_x = 0;
            bat_y = rand();
            bat_y = bat_y % 1000;
        }

        if (life == 0)
            sfRenderWindow_close(window);

        bat_move_x = bat_move_x + vitesse;
        sfSprite_setPosition(bat_s, bat_pos);
        sfRenderWindow_display(window);

        if (event.type == sfEvtMouseButtonPressed) {
            if (mouse.x >= bat_move_x && mouse.x <= bat_move_x + 69) {
                if (mouse.y >= bat_y && mouse.y <= bat_y + 75) {
                    bat_move_x = 1915;
                    compteur += 1;
                    vitesse = vitesse + 0.01;
                    touche_cible = 1;
                }
            }
        }
        if (touche_cible == 1)
            life = life + 1;
    }

    sfTexture_destroy(bat_t);
    sfTexture_destroy(floor_t);
    sfTexture_destroy(cible);
    sfSprite_destroy(floor_s);
    sfSprite_destroy(bat_s);
    sfSprite_destroy(cible_s);
    sfClock_destroy(temps);
    my_printf(" GG !! Tu as tué %i monstres\n", compteur);
}

