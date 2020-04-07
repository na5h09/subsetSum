#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool sumsTo(uint x[], uint n, uint k, uint v) {
    if (v == 0 && k == 0) {
        return true;
    }   // check to see if case given was possible, if both the number terms needed and total sum left is 0
    if (v!=0 && k == 0) {
        return false;
    }   // if all numbers needed were checked but the total sum is greater that 0
    if (n == 0) {
        return false;0
    }   // if all numbers in general were checked, if the amount of numbers in set as a whole weren't enough
    int res1 = 0; //recursion to go throw whole set to check for the right numbers
    if (v >= x[0]) {
        res1 = sumsTo(x + 1, n - 1, k -1, v - x[0]);
    }   // include the first number of the array in the sum
    int res2 = sumsTo(x + 1, n - 1, k, v);  // exclude the first number in the sum
    if (res1 + res2 > 0) { //if either or both results turn true, that return true as a final
        return true;
    }
    return false; //return false if everything before doesn't work
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
