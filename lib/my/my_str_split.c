/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Splits a string into an array of string.
*/

#include <stdlib.h>
#include "my.h"

static int count_words(const char *str, const char *seps)
{
	int nb_word = 0;

	for (int i = 0 ; str[i] ; ++i) {
		if (!in_str(str[i], seps)) {
			if (in_str(str[i + 1], seps) || str[i + 1] == '\0')
				++nb_word;
		}
	}
	return (nb_word);
}

static char *get_word(const char **str, const char *seps)
{
	char *word = NULL;
	int wsize = 0;

	while (in_str((*str)[0], seps))
		++(*str);
	for (; !in_str((*str)[wsize], seps) && (*str)[wsize] ; ++wsize);
	word = malloc(sizeof(char) * (wsize + 1));
	if (word == NULL)
		return (NULL);
	my_strncpy(word, *str, wsize);
	word[wsize] = '\0';
	(*str) += wsize;
	return (word);
}

char **my_str_split(const char *str, const char *seps)
{
	int nb_word = 0;
	char **split_str = NULL;

	nb_word = count_words(str, seps);
	split_str = malloc(sizeof(char *) * (nb_word + 1));
	if (split_str == NULL)
		return (NULL);
	for (int i = 0 ; i < nb_word ; ++i) {
		split_str[i] = get_word(&str, seps);
		if (split_str[i] == NULL) {
			while (i--)
				free(split_str[i]);
			free(split_str);
			return (NULL);
		}
	}
	split_str[nb_word] = NULL;
	return (split_str);
}