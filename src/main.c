/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-axel.petitjean
** File description:
** main
*/

#include "../include/my.h"

void clik_ter(sfRenderWindow *window, sfEvent event, sfVector2i mouse)
{
    #define CLK_M event.type == sfEvtMouseButtonPressed
    if (mouse.x >= 326 && mouse.x <= 418) {
        if (mouse.y >= 771 && mouse.y <= 857 && CLK_M) {
            game_help(window, event);
        }
    }
}

void clik_bis(sfRenderWindow *window, sfEvent event, sfVector2i mouse)
{

    if (mouse.x >= 1407 && mouse.x <= 1684) {
        if (mouse.y >= 794 && mouse.y <= 848 && CLK_M) {
            sfRenderWindow_close(window);
        }
    } else
        clik_ter(window, event, mouse);
}

void clik(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if (mouse.x >= 866 && mouse.x <= 1084) {
        if (mouse.y >= 794 && mouse.y <= 847 && CLK_M) {
            game_function(window, event);
        }
    } else
        clik_bis(window, event, mouse);
}

void condition(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        description();
    } else if (ac == 1 && av[0][0] == '.' &&
    av[0][1] == '/' && av[0][2] == 'm' && av[0][3] == 'y') {
        main_bis();
        sfSprite_destroy;
        return 0;
    } else {
        my_printf("No such file or directory\n");
        return 84;
    }
}
