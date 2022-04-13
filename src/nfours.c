/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** nfours
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nfours.h"

static char **lidar_info(char *buffer)
{
    char **action;
    size_t n = 0;

    buffer = NULL;
    dprintf(1, "get_info_lidar\n");
    getline(&buffer, &n, stdin);
    action = str_to_word_array(buffer, ':');
    return action;
}

static int play_game(char *buffer, car_t *car)
{
    char **action;
    size_t n = 0;

    action = lidar_info(buffer);
    check_direction(action, car);
    dprintf(1, "wheels_dir:%f\n", car->direction);
    getline(&buffer, &n, stdin);
    action = lidar_info(buffer);
    check_speed(action, car);
    dprintf(1, "car_forward:%f\n", car->speed);
    getline(&buffer, &n, stdin);
    action = lidar_info(buffer);
    if (check_finish(action) == 1) {
        return 1;
    }
    return 0;
}

int needfstek(void)
{
    char *buffer = NULL;
    char **action;
    size_t n = 0;
    car_t car = {0};

    dprintf(1, "start_simulation\n");
    getline(&buffer, &n, stdin);
    action = str_to_word_array(buffer, ':');
    printf(buffer);
    if (strcmp(action[1], "KO") == 1) {
        return 84;
    }
    while (1) {
        if (play_game(buffer, &car) == 1) {
            break;
        }
    }
    return 0;
}