#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool sumsTo(uint x[], uint n, uint k, uint v) {
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
    /*//test 1 should work
    uint x[] = {1,8,6,4,3};
    uint n = 5;
    uint k = 3;
    uint v = 13;*/

    //test 2 should work
    uint x[] = {1,2,5,7,6,1,5,4,5,2,4,5,7};
    uint n = 13;
    uint k = 4;
    uint v = 15;

    /*//test 3 should not work
    uint x[] = {8,7,5,2,1,4,9,6};
    uint n = 8;
    uint k = 3;
    uint v = 30;*/

    if(sumsTo(x, n, k, v) == true) {
        printf("works!!\n");
    } else {
      printf("didn't work\n");
    }
}
