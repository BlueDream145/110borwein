/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "borwein.h"

int main(int ac, char **as)
{
	struct request *req = NULL;

	if (ac == 2 && strcmp(as[1], "-h") == 0) {
		display_help();
		return (EXIT_NORMAL);
	}
	if (check(ac, as) == false ||
		(req = get_instance(atoi(as[1]))) == NULL)
		return (EXIT_FAIL);
	process(req);
	free(req);
	return (EXIT_NORMAL);
}

int check(int ac, char **as)
{
	if (ac != 2)
		return (false);
	if (atoi(as[1]) < 0)
		return (false);
	return (true);
}

void display_help(void)
{
	const char *header = "USAGE\n           ./110borwein n\n\n";
	const char *usage = "DESCRIPTION\n           n   constant defining"
		"the integral to be computed\n";

	printf("%s%s", header, usage);
}