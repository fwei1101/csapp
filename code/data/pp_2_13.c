#include <stdio.h>
#include "hints.h"
#define TEST_NAME "Practice Problem 2.13"

static int bis(int x, int m) {
    return x | m;
}
static int bic(int x, int m) {
    return x & ~m;
}

static int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}
static int bool_xor(int x, int y) {
    int result = bis(bic(x, y), bic(y, x)); /* A ^ B = (A & ~B) | (~A & B) */
    return result;
}

void pp_2_13() {
    test(TEST_NAME);
    int x = 0x12345678;
    int y = 0x00ff00ff;
    printf("0x%x | 0x%x using c-build boolean operation gets 0x%x, using bis gets 0x%x\n", x, y, x | y, bool_or(x, y));
    printf("0x%x ^ 0x%x using c-build boolean operation gets 0x%x, using bis gets 0x%x\n", x, y, x ^ y, bool_xor(x, y));
    test_done();
}