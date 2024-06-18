/*
** EPITECH PROJECT, 2018
** math.c
** File description:
**
*/

#include "borwein.h"

double borwein(struct request *req, int i)
{
	double h = (req->end - req->start) / req->interval;
	double result = 0;

	if (req->end > 0)
		for (; ++i < req->interval;)
			result += fact(req->start, req->start + i * h);
	else
		for (; --i > req->interval;)
			result += fact(req->start, req->start + i * h);
	return (result);
}

double simpson(struct request *req)
{
	double h = (req->end - req->start) / req->interval;
	double result = 0;
	int i = -1;

	if (req->end > 0)
		for (; ++i < req->interval;)
			result += fact(req->start, (req->start + i * h) +
				(h / 2));
	else
		for (; --i > req->interval;)
			result += fact(req->start, (req->start + i * h) +
				(h / 2));
	return (result);
}

double fact(double start, double val)
{
	double result = 1;
	int index = -1;

	for (; ++index <= start;)
		if (val != 0)
			result *= (sin(val / ((2 * index) + 1)) /
				(val / ((2 * index) + 1)));
	return (result);
}