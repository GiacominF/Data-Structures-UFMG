#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

typedef struct alg {
    int num;
    char * name;
} alg_t;

typedef struct opt {
    int size;
    int seed;
    int alg;
} opt_t;

typedef struct sortperf {
    int cmp;
    int move;
    int calls;
} sortperf_t;

int name2num(char * name);
char * num2name(int num);
void resetcounter(sortperf_t * s);
void inccmp(sortperf_t * s, int num);
void incmove(sortperf_t * s, int num);
void inccalls(sortperf_t * s, int num);
char * printsortperf(sortperf_t * s, char * str, char * pref);
void initVector(int * vet, int size);
void printVector(int * vet, int size);
void swap(int *xp, int *yp, sortperf_t *s);
void uso();
void parse_args(int argc, char ** argv, opt_t * opt);
void clkDiff(struct timespec t1, struct timespec t2, struct timespec * res);

#endif
