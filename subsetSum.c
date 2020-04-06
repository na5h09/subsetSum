#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool sumsTo(uint x[], uint n, uint k, uint v) {
    // printf("x[0], n, k, v: %d, %d, %d, %d\n", x[0], n, k, v);
    if (v == 0 && k == 0) {
        return true;
    }   // used up all numbers to reach sum 0
    if (v!=0 && k == 0) {
        return false;
    }   // used up all numbers without reaching sum 0
    if (n == 0) {
        return false;
    }   // used up all numbers without reaching sum 0
    int res1 = 0;
    if (v >= x[0]) {
        res1 = sumsTo(x + 1, n - 1, k -1, v - x[0]);
    }   // include the first number of the array in the sum
    int res2 = sumsTo(x + 1, n - 1, k, v);  // exclude the first number in the sum
    if (res1 + res2 > 0) {
        return true;
    }
    return false;
}

int main(void) {
    uint x[] = {1,8,6,4,3};
    if(sumsTo == true) {
        printf("works!!");
    }
}
