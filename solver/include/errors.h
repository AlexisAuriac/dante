/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Typedefs header file.
*/

#ifndef ERRORS_H
#define ERRORS_H

//arguments
static const char ERROR_NOT_ENOUGH_ARG[] = "Not enough arguments";
static const char ERROR_TOO_MANY_ARG[] = "Too many arguments";

//maze
static const char ERROR_MAZE_BAD_CHARACTER[] =
"Invalid maze: forbidden character found";
static const char ERROR_MAZE_EMPTY[] =
"Empty maze";
static const char ERROR_MAZE_ENDL_FINISHING_FILE[] =
"The maze musn't end with '\\n'";
static const char ERROR_MAZE_NO_EXIT[] =
"Invalid maze: the exit must be down-right corner";
static const char ERROR_MAZE_NO_START[] =
"Invalid maze: the start must be upper-left corner";
static const char ERROR_MAZE_VARIABLE_LINE_LENGTH[] =
"Invalid maze: maze must a rectangle";

//path
static const char ERROR_NO_PATH[] =
"No path";

#endif