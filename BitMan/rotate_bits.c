#include <stdio.h>

int rotate_bits(int number, int k){
    unsigned int result;
    result = (number >> k | number << (32-k));
    return result;
}

int main()
{
    printf("Check even using bitman! \n");
    unsigned int num  = 0x04030602;
    int k = 8;
    
    printf("Rotated Number: %x\n", rotate_bits (num, k));
    return 0;
}