#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int size; // Variable to record size of original array arr
int evenCount = 0, oddCount = 0; // Variables to record sizes of new arrays arr_even and arr_odd
int *arr; // Dynamically allocated original array with #elements = size
int *arr_even;  // Dynamically allocated array with #elements = #even elements in arr (evenCount)
int *arr_odd;   // Dynamically allocated array with #elements = #odd elements in arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";

/*
 * DO NOT change the definition of the printArr function when it comes to 
 * adding/removing/modifying the function parameters, or changing its return 
 * type. 
 */
void printArr(int *a, int size, char *prompt){
	// Your code here
    printf("%s", prompt);
    if (size == 0)
    {
        printf("empty");
    }
    else{
        for (int i = 0; i < size; i++)
        {
            printf("%i ", a[i]);
        }
    };
    printf("\n");
}

/* 
 * DO NOT change the definition of the arrCopy function when it comes to 
 * adding/removing/modifying the function parameters, or changing its return 
 * type. 
 */
void arrCopy(){
	// Your code here
    int j;
    int k;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) % 2 == 0)
        {
            *(arr_even + j ) = *(arr + i);
            j++;
        }
        else if (*(arr + i) % 2 == 1)
        {
            *(arr_odd + k) = *(arr + i);
            k++;
        };
    };
}

int main(){
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &size);

    // Dynamically allocate memory for arr (of appropriate size)
    arr = (int*)malloc(sizeof(int) * size);
    // Your code here

    // Ask user to input content of arr and compute evenCount and oddCount
    for (int i = 0; i <size; i++)
    {
        int temp;
        scanf("%d", &temp);
        *(arr + i) = temp; // arr[i] = temp;

        if (temp % 2 == 0)
        {
            evenCount++;
        }
        else if (temp % 2 == 1)
        {
            oddCount ++;
        }; 
    };
    
	// Your code here

    // Dynamically allocate memory for arr_even and arr_odd (of appropriate size)
    arr_even = (int*)malloc(sizeof(int) * evenCount);
    arr_odd =(int*)malloc(sizeof(int) *  oddCount);
     
    // Your code here    
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	// Print original array
    printArr(arr, size, str1);

	/// Copy even elements of arr into arr_even and odd elements into arr_odd
    arrCopy();

    // Print new array containing even elements from arr
    printArr(arr_even, evenCount, str2);

    // Print new array containing odd elements from arr
    printArr(arr_odd, oddCount, str3);

    printf("\n");

    return 0;
}