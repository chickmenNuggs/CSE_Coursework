#include <stdio.h>

int EvO( int k){
    if(k % 2 == 0){
        return 1;
    }  
    return 0;
};

int digSum (int i){
    int sumInt = 0;
    int n = 0;
    if (i < 0)
    {
        n = 1;
        i = -i;
    }
    
    while (i != 0) {
        sumInt = sumInt + i % 10;     
        i = i / 10;     
    }

    if (n = 1)
    {
        sumInt = sumInt;
    }
    

    return sumInt;
};

char* suffCalc( int i){
    
    if (i == 11 || i == 12 || i == 13){ return "th";}        
    switch (i % 10)
    {
    case 1:
       return "st";
    case 2:
        return "nd";
    case 3:
        return "rd";
    default:
        return "th";
    }
};

int main(){

    int I;
    int J;
    int size;
    size = 1;
    int sizeOdd = 0;
    int sizeEven = 0;

    float sumOdd = 0;
    float avgOdd = 0;

    float sumEven = 0;
    float avgEven = 0;

    char *suff = "st";

    int t = 1;
   
    while (1) {
        suff = suffCalc(size);
        printf("Enter the %d%s value: ", size, suff);
        scanf("%d", &I);
        if (I == 0)
        {
            printf("%s", "\n");
            break;
        }

        J = digSum(I);
        
        if ( J % 2 == 0)
        {   
            
            sumEven += I;
            sizeEven++;
            
        }
        else if ( J % 2 == 1)
        {
            sumOdd += I; 
            sizeOdd ++;
            
        }
        J = 0;
        size++;

    };
    if (size == 1 && I == 0){
        printf("There is no average to compute.\n");
    } else {
        if (sizeEven > 0){
            if (sizeEven > 0)
                printf("Average of input values whose digits sum up to an even number: %.2f\n", sumEven / sizeEven);
            else
                printf("Average of inputs whose digits sum up to an even number: %.2f\n", sumEven / sizeEven);
        }
        if (sizeOdd > 0){
            if (sizeOdd> 0)
                printf("Average of input values whose digits sum up to an odd number: %.2f\n", sumOdd / sizeOdd);
            else
                printf("Average of inputs whose digits sum up to an odd number: %.2f\n", sumOdd / sizeOdd);
        }
    }
return 0;
}