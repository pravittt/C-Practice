#include <stdio.h>
#include <stdint.h>

int main (){

    uint8_t num = 23;
    uint8_t extractEven = num & 0xAA; 
    uint8_t extractOdd = num & 0x55;
    uint8_t result = (extractEven >> 1) | (extractOdd << 1);

    printf("%d\n" , result);
    return 0;
}