#include <stdio.h>

int main()
{
    printf("Swap Endianness\n");
    
    int num = 0x14030619;
    int result; 
    
    result = ((num & 0x000000ff) << 24) | ((num & 0x0000ff00) << 8) | ((num & 0x00ff0000) >> 8) | ((num & 0xff000000) >> 24);
    printf("Result is %x\n", result);
    return 0;
}