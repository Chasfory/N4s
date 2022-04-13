/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** check_car
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nfours.h"

static void check_speed_ter(float run, car_t *car)
{
    if (run >= 400) {
        car->speed = 0.2;
    }
    else if (run < 400) {
        car->speed = 0.1;
    }
}

static void check_speed_bis(float run, car_t *car)
{
    if (run >= 1000) {
        car->speed = 0.4;
    }
    else if (run >= 600) {
        car->speed = 0.3;
    } else {
        check_speed_ter(run, car);
    }
}

void check_speed(char **action, car_t *car)
{
    float run = atoi(action[14]);

    if (run >= 2000) {
        car->speed = 0.8;
    }
    else if (run >= 1500) {
        car->speed = 0.6;
    } else {
        check_speed_bis(run, car);
    }
}

int check_finish(char **action)
{
    size_t n = 0;
    char *buffer = NULL;

    if (strcmp(action[35], "Track Cleared") == 0) {
        dprintf(1, "car_forward:0\n");
        getline(&buffer, &n, stdin);
        dprintf(1, "stop_simulation\n");
        return 1;
    }
    return 0;
}