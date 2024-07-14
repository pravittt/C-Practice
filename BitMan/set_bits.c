#include <stdio.h>

int main()
{
    printf("Count set bits\n");
    unsigned int num = 0xff0000ff;
    int count = 0;
    while (num != 0){
        
        if ((num & 1) == 1){
            count ++;
        }
        num = num >> 1;
    }
    printf("Number of set bits: %d\n", count);
    
}