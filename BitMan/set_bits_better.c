#include <stdio.h>

int main()
{
    printf("Count set bits\n");
    unsigned int num = 0xff00ffff;
    int count = 0;
    while (num){
        num &= num - 1;
        count++;
    }
    printf("Number of set bits: %d\n", count);
    
}