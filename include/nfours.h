/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** nfours
*/

#ifndef _NFOURS_H_
#define _NFOURS_H_

typedef struct car_s {
    float direction;
    float speed;
} car_t;

char **str_to_word_array(char *str, char sep);

int needfstek(void);
int check_finish(char **action);

void check_speed(char **action, car_t *car);
void check_direction(char **action, car_t *car);

#endif /* !NFOURS_H_ */
