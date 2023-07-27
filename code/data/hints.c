#include <stdio.h>

void test(char str[]) {
    printf("##### TEST ");
    printf("%s", str);
    printf(" #####\n");
}

void test_done() {
    printf("##### TEST DONE #####\n\n");
}

void print_array(int *arr, int len) {
    printf("[");
    int i;
    for (i = 0; i < len - 1; i++)
        printf("%d,", arr[i]);
    printf("%d", arr[i]);
    printf("]\n");
}