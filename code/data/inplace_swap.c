#include <stdio.h>
#include "hints.h"
#define TEST_NAME_IPSWP "In-Place Swap"
#define TEST_NAME_RVSARR "Reverse Array"

static void inplace_swap(int *x, int *y) {
    *y = *x ^ *y; /*yt = xo ^ yo*/
    *x = *x ^ *y; /*xn = xo ^ yt = xo ^ xo ^ yo = yo*/
    *y = *x ^ *y; /*yn = xn ^ yt = yo ^ xo ^ yo = xo*/
}

static void reverse_array(int a[], int cnt) {
    int first, last;
    for (
        first = 0, last = cnt - 1; 
        first < last;
        first++, last--)
        inplace_swap(&a[first], &a[last]);
}

void test_inplace_swap() {
    test(TEST_NAME_IPSWP);
    int a = 15, b = 29, c = 30;
    printf("before inplace swap a = %d, b = %d, c = %d\n", a, b, c);
    inplace_swap(&a, &b);
    inplace_swap(&c, &c);
    printf("after inplace swap a = %d, b = %d, c = %d\n", a, b, c);
    test_done();
}

void test_reverse_array() {
    test(TEST_NAME_RVSARR);
    int a[4] = {1,2,3,4};
    int b[5] = {1,2,3,4,5};
    int loop = 0;
    printf("before reverse array a = ");
    print_array(a, 4);
    printf("before reverse array b = ");
    print_array(b, 5);
    reverse_array(a, 4);
    reverse_array(b, 5);
    printf("after reverse array a");
    for (loop = 0; loop < 4; loop++)
        printf(" %d", a[loop]);
    printf("\n");
    printf("before reverse array b");
    for (loop = 0; loop < 5; loop++)
        printf(" %d", b[loop]);
    printf("\n");
    test_done();
}