/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef BORWEIN_
	#define BORWEIN_

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <stdbool.h>
	#include <math.h>
	#include <string.h>

	#define EXIT_FAIL (84)
	#define EXIT_NORMAL (0)
	#define M_PI (3.14159265358979323846)

struct request {
	double start;
	double end;
	double interval;
	int precision;
};

// engine.c
void process(struct request *req);
void process_rectangle(struct request *req);
void process_trapezoids(struct request *req);
void process_simpson(struct request *req);
void display(struct request *req, double val, const char *header);

// instances.c
struct request *get_instance(int start);

// main.c
int check(int ac, char **as);
void display_help(void);

// math.c
double borwein(struct request *req, int i);
double simpson(struct request *req);
double fact(double start, double val);

#endif /* BORWEIN */