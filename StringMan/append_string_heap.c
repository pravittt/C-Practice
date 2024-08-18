#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	printf("Malloc Append\n\n");

	char store[] = "String_store";
	char* str = (char*)malloc((strlen(store + 1)) * sizeof(char));
	
	if (str == NULL){
	    printf("ERROR, Can not allocate memory!\n");
	    return 1; 
	}
	strcpy(str, store);
	str = realloc(str, (strlen(str + 2)));
	if (str == NULL){
	    printf("ERROR, Can not allocate memory!\n");
	    return 1; 
	}
// Add a character at the end of the string allocated in HEAP! 
    
    str[strlen(str) ] = 's';
    str[strlen(str) +1] = '\0';
    printf("Appended String : %s\n", str);
	return 0;
}