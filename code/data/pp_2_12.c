#include<stdio.h>
#include "hints.h"
#define TEST_NAME "Practice Problem 2.12"

static int pp_2_12_a(int val) {
    int mask = 0xff;
    return mask & val;
}

static int pp_2_12_b(int val) {
    int mask = 0xffffff00;
    return mask ^ val;
}

static int pp_2_12_c(int val) {
    int mask = 0x000000ff;
    return mask | val;
}

void pp_2_12() {
    test(TEST_NAME);
    int val = 0x87654321;
    printf("answer A %x -> %x\n", val, pp_2_12_a(val));
    printf("answer B %x -> %x\n", val, pp_2_12_b(val));
    printf("answer C %x -> %x\n", val, pp_2_12_c(val));
    test_done();
}