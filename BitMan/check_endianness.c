#include <stdio.h>
#include <stdint.h>

int main()
{
    printf("Endian World\n");
    
    int num = 0x04030609;
    int mask = 0x000000ff;
    char *read_lsb = (char *)&num; 
    
    if (*read_lsb == (num & mask)){
        printf("Little Endian\n");
    }
    else 
        printf("Big Endian\n");
    
    return 0;
}