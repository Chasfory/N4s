/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** check_direction
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nfours.h"

static void check_direction_ter(car_t *car, int sign, float direction_finish)
{
    if (direction_finish >= 200) {
        car->direction = 0.3 * sign;
    }
    else if (direction_finish < 200 && direction_finish >= 40) {
        car->direction = 0.7 * sign;
    } else {
        car->direction = 1 * sign;
    }
}

static void check_direction_bis(car_t *car, int sign, float direction_finish)
{
    if (direction_finish >= 600) {
        car->direction = 0.1 * sign;
    }
    else if (direction_finish >= 400) {
        car->direction = 0.2 * sign;
    } else {
        check_direction_ter(car, sign, direction_finish);
    }
}

void check_direction(char **action, car_t *car)
{
    int sign = (atof(action[3]) - atof(action[31]) < 0) ? -1 : 1;
    float direction_finish = atoi(action[14]);

    if (direction_finish >= 1500) {
        car->direction = 0.01 * sign;
    }
    else if (direction_finish >= 1000) {
        car->direction = 0.05 * sign;
    }
     else {
        check_direction_bis(car, sign, direction_finish);
    }
}