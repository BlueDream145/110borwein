/*
** EPITECH PROJECT, 2018
** instances.c
** File description:
**
*/

#include "borwein.h"

struct request *get_instance(int start)
{
	const double default_end = 5000;
	const double default_interval = 10000;
	const double default_prec = 10;
	struct request *req = malloc(sizeof(struct request));

	if (req == NULL)
		return (NULL);
	req->start = start;
	req->end = default_end;
	req->interval = default_interval;
	req->precision = default_prec;
	return (req);
}