#include <stdio.h>
#include "show_bytes.h"
#include "hints.h"
#define TEST_NAME "Practice Problem 2.5"

void pp_2_5() {
    test(TEST_NAME);
    int a = 0x12345678;
    byte_pointer ap = (byte_pointer) &a;
    printf("0x%x show 1 byte -> ", a);
    show_bytes(ap, 1);
    printf("0x%x show 2 byte -> ", a);
    show_bytes(ap, 2);
    printf("0x%x show 3 byte -> ", a);
    show_bytes(ap, 3);
    test_done();
}