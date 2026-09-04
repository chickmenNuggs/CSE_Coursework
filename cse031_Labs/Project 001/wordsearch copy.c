#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;
int wSize;
int indTick = 0;


typedef struct wordData
{
    int x, y, numVal, boal; 
    char wallop;
    struct wordData* next; 
    struct wordData* prev;
}poisData;

typedef struct usedInd
{
   int x;
   int y; 
}indexData;


// indexData *index;

// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr; 


    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));
    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) {
	// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...

    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            printf("%c ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

char dict(char let){
    if (let == 'a'){ return 'A';}
    else if (let == 'b'){ return 'B';} 
    else if (let == 'c'){ return 'B';} 
    else if (let == 'd'){ return 'C';} 
    else if (let == 'e'){ return 'E';} 
    else if (let == 'f'){ return 'F';} 
    else if (let == 'g'){ return 'G';} 
    else if (let == 'h'){ return 'H';} 
    else if (let == 'i'){ return 'I';} 
    else if (let == 'j'){ return 'J';} 
    else if (let == 'k'){ return 'K';} 
    else if (let == 'l'){ return 'L';} 
    else if (let == 'm'){ return 'M';} 
    else if (let == 'n'){ return 'N';} 
    else if (let == 'o'){ return 'O';} 
    else if (let == 'p'){ return 'P';} 
    else if (let == 'q'){ return 'Q';} 
    else if (let == 'r'){ return 'R';} 
    else if (let == 's'){ return 'S';} 
    else if (let == 't'){ return 'T';} 
    else if (let == 'u'){ return 'U';} 
    else if (let == 'v'){ return 'V';} 
    else if (let == 'w'){ return 'W';} 
    else if (let == 'x'){ return 'X';} 
    else if (let == 'y'){ return 'Y';} 
    else if (let == 'z'){ return 'Z';} 
    else{return let;}
};

char* cap(char* string){
    char* STRING = string;
    char LET;

    for (int i = 0; i < strlen(string); i++)
    {
        LET = dict(*(string+i));
        *(STRING+i) = LET;
    }
    return STRING;
};

int checkMutual(poisData *valList, indexData *index){
    for (int i = 0; i < wSize; i++)
    {
        if (((valList+i)->x == (index+i)->x)&&((valList+i)->y == (index+i)->y))
        {
            return 1;
        }
        
    }
    return 0;
};

char intToChar(int val){
    if (val == 1) {return '1';}
    else if (val == 2){return '2';}
    else if (val == 3){return '3';}
    else if (val == 4){return '4';}
    else if (val == 5){return '5';}
    else if (val == 6){return '6';}
    else if (val == 7){return '7';}
    else if (val == 8){return '8';}
    else if (val == 9){return '9';}
    else if (val == 0){return '0';}
    return 32;
};

char* strUpdater(char* string, int val){
    int check;
    char let;
    char letN = val;
    let = intToChar(val);
    for (int i = 0; i < val; i++)
    {   
        
        *(string + i) = (char)32;  
    }
    return string;
};

void printSol(int found, poisData *inde){
    char *msg0 = "Word not found! \n";
    char *msg = "Word found! \n";
    char *msg2 = "Printing the search path: \n";
    char *pMsg = (char*)malloc(9*sizeof(char));
    *(pMsg + 9) = '\0';

    int tracker = 0;
    int varp = 0;
    
    if (found == 1)
    {
        printf( "\n%s%s", msg, msg2);

        for (int i = 0; i < wSize; i++)
        {
            printf("index: %i | x-Val: %i | y-Val %i | b-Val: %i | l-Val: %c\n", i+1, (inde + i)->x, (inde + i)->y, (inde+ i)->boal, (inde+i)->wallop);
        }
        
        for (int i = 0; i < bSize; i++)
        {
            for (int j = 0; j < bSize; j++)
            {
                
                for (int k = 0; k < wSize; k++)
                {
                    if (i == (inde+k)->y && j == (inde+k)->x)
                    {
                        printf("%i", k+1);
                        varp++;
                        strUpdater(pMsg, varp);
                        
                        tracker = 1;
                    }
                }
                if (tracker == 0)
                {
                   printf("0       ");
                }
                else{
                    for (int q = 0; q < 8-varp; q++)
                    {
                        printf(" ");
                    }
                }
               tracker = 0;
               varp = 0;
            }
            printf("\n");
        }
    }
    else 
    {printf( "\n%s", msg0);}
};

// int check(char Key, char Ref){


//     return 0; //not there
// };

// poisData searchArr (char** arr, char let){
//     poisData valList;
//     valList.boal = 0;
//     for (int i = 0; i < bSize; i++)
//     {

//         for (int j = 0; j < bSize; j++)
//         {
//             if ((let == *(*(arr+i)+j )))
//             {   
//                 valList.x = j;
//                 valList.y = i;
//                 valList.wallop = let;
//                 valList.boal = 1;
//             }         
//         }
//     }
//     return valList;
// };

int checkWord(poisData *ind){
    int found;
    for (int i = 0; i < wSize; i++)
    {
        if ((ind+i)->boal == 1)
        {
            found = 1;
        }
        else if ((ind+i)->boal != 1)
        {
            found = 0;
            return found;
        }
    }  
    return found;
};

void searchPuzzle(char** arr, char* word) {
    // This function checks if arr contains the search word. If the word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a different message as shown in the sample runs.
    // Your implementation here...
    int found = 0;
    char* WORD = cap(word);    
    wSize = (strlen(word));
    char let = '.';
    poisData *tempInd;
    float f = 12.5;

    poisData *indHolder = (poisData*)malloc(wSize*sizeof(poisData));

    for (int w = 0; w < wSize; w++)
    {
        let = *(WORD + w);
        for (int r = 0; r < bSize; r++)
        {
            for (int c = 0; c < bSize; c++)
            {
                
            }
            
        }
        
    }
    

    // for (size_t i = 0; i < wSize; i++)
    // {   
       
    //     (indHolder + i)->node = (indHolder + i+ 1);
    //      if (i = wSize - 1)
    //     {
    //         (indHolder+i)->node = NULL;
    //     }
    // }
    
    
    // for (int i = 0; i < wSize; i++){
    //    let = *(WORD + i);  
    //    (indHolder + i)->boal = searchArr(arr, let).boal;
    //    (indHolder + i)->x = searchArr(arr, let).x;
    //    (indHolder + i)->y = searchArr(arr, let).y; 
    //    (indHolder + i)->wallop = searchArr(arr, let).wallop;
    // }

    found = checkWord(indHolder);
    printSol(found, indHolder);
}
