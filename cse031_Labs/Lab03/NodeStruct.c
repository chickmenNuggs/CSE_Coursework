#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};


int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert code here
	
    printf("Int value : %i\n", head->iValue); 
    printf("Int Address %p\n", &head->iValue);
    
    printf("Float value : %f\n", head->fValue); 
    printf("Float Address %p\n", &head->fValue);
    
    printf("Next Address : %p\n", &head->next); 
    
   

	
	return 0;
}