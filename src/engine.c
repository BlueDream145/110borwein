/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
**
*/

#include "borwein.h"

void process(struct request *req)
{
	process_rectangle(req);
	process_trapezoids(req);
	process_simpson(req);
}

void process_rectangle(struct request *req)
{
	const char *header = "Rectangles:\n";
	double result = borwein(req, req->start - 1);

	result *= (req->end - req->start) / req->interval;
	display(req, result, header);
}

void process_trapezoids(struct request *req)
{
	const char *header = "Trapezoids:\n";
	double result = borwein(req, req->start);

	result = ((result * 2) +
		fact(req->start, req->start) +
		fact(req->start, req->end)) *
		((req->end - req->start) / (2 * req->interval));
	display(req, result, header);
}

void process_simpson(struct request *req)
{
	const char *header = "Simpson:\n";
	double result = borwein(req, req->start);
	double simp = simpson(req);

	result = ((result * 2) + (simp * 4) +
		fact(req->start, req->start) +
		fact(req->start, req->end)) *
		((req->end - req->start) / (6 * req->interval));
	display(req, result, header);
}

void display(struct request *req, double val, const char *header)
{
	const char *last_header = "Simpson:\n";

	printf("%s", header);
	printf("I0 = %.*f\n", req->precision, val);
	printf("diff = %.*f\n", req->precision, val - M_PI / 2);
	if (strcmp(header, last_header) != 0)
		printf("\n");
}