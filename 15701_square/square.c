#include <stdio.h>


int main (void) {

    long i = 3037000499L;

    printf("%10ld %20ld\n", i, i * i);

    return 0;

}

// biggest valid result on my system when i is of type short: 32761 (but i++ afterwards causes infinite loop)
// biggest valid result on my system when i is of type int  : 46340
// biggest valid result on my system when i is of type long : 3037000499 ?


// if the integer type is 16 bit and signed by default, it can store 2^16 states, but because of the sign
// it's 2^15 for the magnitude of the number plus + or -. If the states are to represent consecutive integer
// numbers starting at 0, then the highest number you can write down is 2^(16 - 1) - 1 = 32767
// the largest integer whose square fits in that is 181: 181 * 181 = 32761, whereas 182 * 182 = 33124

// if the integer type is 32 bit and signed by default, it can store 2^32 states, but because of the sign
// it's 2^31 for the magnitude of the number plus + or -. If the states are to represent consecutive integer
// numbers starting at 0, then the highest number you can write down is 2^(32 - 1) - 1 = 2147483647
// the largest integer whose square fits in that is 46340: 46340 * 46340 = 2147395600, whereas 46341 * 46341 = 2147488281

// if the integer type is 64 bit and signed by default, it can store 2^64 states, but because of the sign
// it's 2^63 for the magnitude of the number plus + or -. If the states are to represent consecutive integer
// numbers starting at 0, then the highest number you can write down is 2^(64 - 1) - 1 = 9.223372e+18
// the largest integer whose square fits in that is 3037000499 * 3037000499 = 9223372030926249001

