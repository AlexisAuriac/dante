/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Header of the project.
*/

#ifndef SOLVER_H
#define SOLVER_H

#include "const.h"
#include "typedef.h"
#include "macro.h"
#include "errors.h"

//parse_arg.c
bool parse_arg(int ac);

//load_map.c
map_t *load_map(const char *file_name);

#endif