#include <stdio.h>
#include "show_bytes.h"
#include "hints.h"
#define TEST_NAME "show_bytes()"

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

static void show_int(int x) {
    printf("%d -> ", x);
    show_bytes((byte_pointer) &x, sizeof(int));
}

static void show_float(float x) {
    printf("%f -> ", x);
    show_bytes((byte_pointer) &x, sizeof(float));
}

static void show_pointer(void *x) {
    printf("%p -> ", x);
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes() {
    test(TEST_NAME);
    int ival = 12345;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
    test_done();
}

int bis(int x, int m) {
    return x ^ m;
}
int bic(int x, int m) {
    return x & ~m;
}
int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}
int bool_xor(int x, int y) {
    int result = bis(bic(x, y), bic(y, x));  /* x ^ y = (x & ~y) | (~x & y)*/
    return result;
}