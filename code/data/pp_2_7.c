#include <stdio.h>
#include <string.h>
#include "show_bytes.h"
#include "hints.h"
#define TEST_NAME "Practice Problem 2.7"

void pp_2_7() {
    test(TEST_NAME);
    char *m = "mnopqr";
    printf("show bytes for \"%s\" -> ", m);
    show_bytes((byte_pointer) m, strlen(m));
    test_done();
}