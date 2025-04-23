#ifndef SORT_H
#define SORT_H

#define ALGINSERTION 1
#define ALGSELECTION 2
#define ALGQSORT     3
#define ALGQSORT3    4
#define ALGQSORTINS  5
#define ALGQSORT3INS 6
#define ALGSHELLSORT 7
#define ALGRECSEL    8

#include "utils.h"
#include <stdio.h>

void shellSort(int *A, int n, sortperf_t * s);
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t * s);
void selectionSort(int arr[], int l, int r, sortperf_t * s);
void insertionSort(int v[], int l, int r, sortperf_t * s);
int median (int a, int b, int c);
void partition3(int * A, int l, int r, int *i, int *j, sortperf_t *s);
void partition(int * A, int l, int r, int *i, int *j, sortperf_t *s);
void quickSort(int * A, int l, int r, sortperf_t *s);
void quickSort3(int * A, int l, int r, sortperf_t *s);
void quickSortIns(int * A, int l, int r, sortperf_t *s);
void quickSort3Ins(int * A, int l, int r, sortperf_t *s);

#endif
