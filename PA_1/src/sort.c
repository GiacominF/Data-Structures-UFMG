#include "sort.h"

void shellSort(int *A, int n, sortperf_t * s) 
{
    inccalls(s,1);
    for(int h = n/2; h > 0; h /= 2) 
    {
        for (int i = h; i < n; i++) 
        {
            inccmp(s,1);
            int temp = A[i]; 
            incmove(s,1);
            int j;
            for (j = i; j >= h && A[j-h] > temp; j -= h) 
            {
                inccmp(s,1);
                A[j] = A[j-h];  
                incmove(s,1);
            }
            A[j] = temp;
            incmove(s,1);   
        }
    }
}

void recursiveSelectionSort(int arr[], int l, int r, sortperf_t * s) {
    int min = l;
    inccalls(s,1);
    for (int j = l + 1; j <= r; j++) {
        inccmp(s,1);
        if (arr[j] < arr[min]) {
            min = j;
        }
    }
    if (min != l)
        swap(&arr[min], &arr[l], s);

    if (l + 1 < r) {
        recursiveSelectionSort(arr, l + 1, r, s);
    }
}

void selectionSort(int arr[], int l, int r, sortperf_t *s) { 
    inccalls(s, 1);
    int min;

    for (int i = l; i < r; i++) {
        min = i;

        for (int j = i + 1; j <= r; j++) {
            inccmp(s, 1);
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {  
            swap(&arr[i], &arr[min], s);  
        }
    }
}

void insertionSort(int v[], int l, int r, sortperf_t * s) {
    inccalls(s, 1);  
    int aux, j;

    for (int i = l + 1; i <= r; i++) 
    {  
        inccmp(s,1);
        incmove(s, 1);
        aux = v[i];
        j = i - 1;

        while ((j >= l) && (aux < v[j])) 
        {
            inccmp(s, 1); 
            v[j + 1] = v[j];
            incmove(s, 1);
            j--;
        }
        v[j + 1] = aux;
        incmove(s, 1);
    }
}

int median (int a, int b, int c) {
    if ((a <= b) && (b <= c)) return b;
    if ((a <= c) && (c <= b)) return c;
    if ((b <= a) && (a <= c)) return a;
    if ((b <= c) && (c <= a)) return c;
    if ((c <= a) && (a <= b)) return a;
    return b;
}

void partition3(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
    inccalls(s,1);
    int m = (l + r)/2;
    int x = median(A[l], A[m], A[r]);
    *i = l;
    *j = r;

    do
    {   inccmp(s,1);
        while(A[*i] < x) 
        {
            inccmp(s,1); 
            (*i)++;
        }

        while(A[*j] > x) 
        {
            inccmp(s,1); 
            (*j)--;
        }

        inccmp(s,1);
        if(*i <= *j) 
        {
            swap(&A[*i], &A[*j], s);
            (*i)++;
            (*j)--;
        } 
    } while (*i <= *j);
}
  
void partition(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
    inccalls(s,1);
    int x, w;
    *i = l; *j = r;
    x = A[(*i + *j)/2];
    do 
    {
        inccmp(s,1);
        while(x > A[*i]) 
        {
            inccmp(s,1); 
            (*i)++;
        }

        while(x < A[*j]) 
        {
            inccmp(s,1); 
            (*j)--;
        }

        inccmp(s,1);
        if (*i <= *j)
        {   incmove(s,3);
            w=A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++; (*j)--;
        } 
        
    } while (*i <= *j);
}

void quickSort(int * A, int l, int r, sortperf_t *s) { 
    inccalls(s,1);
    int i, j;
    partition(A, l, r, &i, &j, s);
    
    if(l < j) quickSort(A, l, j, s);
    if(i < r) quickSort(A, i, r, s);
}

void quickSort3(int * A, int l, int r, sortperf_t *s) { 
    inccalls(s,1);
    int i, j;

        partition3(A, l, r, &i, &j, s);

        if(l < j) quickSort3(A, l, j, s);
        if(i < r) quickSort3(A, i, r, s);
}

void quickSortIns(int *A, int l, int r, sortperf_t *s) {
    inccalls(s, 1); 
    int i, j;
    partition(A, l, r, &i, &j, s); 

    if (l < j) {
        if(j - l <= 50) {
            insertionSort(A, l , j, s);
        }
        else {
            quickSortIns(A, l, j, s);
        }
    }

    if (i < r) {
        if(r - i <= 50) {
            insertionSort(A, i, r, s);
        }
        else {
            quickSortIns(A, i, r, s);
        }
    }
}

void quickSort3Ins(int * A, int l, int r, sortperf_t *s) { 
    inccalls(s,1);
    int i, j;
    partition3(A, l, r, &i, &j, s);
    
    if (l < j) {
        if(j - l <= 50) {
            insertionSort(A, l , j, s);
        }
        else 
            quickSort3Ins(A, l, j, s); 
    }
    
    if (i < r) {
        if(r - i <= 50) {
            insertionSort(A, i, r, s);
        }
        else 
            quickSort3Ins(A, i, r, s);
    }
}

