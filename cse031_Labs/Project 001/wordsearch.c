#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Group Partner: Kane Timmons, Maurico Granera(Me)

void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;
int wSize;

//array helpers for adjacancy
int *dx;
int *dy;

//stores the correct directional data to be assigned to the global variables
void inDirect(){
    *(dx + 0) = 0;
    *(dy + 0) = -1;
    *(dx + 1) = 1;
    *(dy + 1) = -1;
    *(dx + 2) = 1;
    *(dy + 2) = 0;
    *(dx + 3) = 1;
    *(dy + 3) = 1;
    *(dx + 4) = 0;
    *(dy + 4) = 1;
    *(dx + 5) = -1;
    *(dy + 5) = 1;
    *(dx + 6) = -1;
    *(dy + 6) = 0;
    *(dx + 7) = -1;
    *(dy + 7) = -1;
};

// Custom Struct set up with int variables, x,y are board coridnents, boal is a nock off boolean because i wasnt sure if we could use the bool include
//typedef-ed to be called 'poisData' so to make 
typedef struct wordData
{
    int x, y, numVal, boal; 
    // wallop is a char variable i made to keep track of the letter that wordData is using.
    char wallop;
}poisData;

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

//prints the puzzle Characters
void printPuzzle(char** arr) {
    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            printf("%c ", *(*(arr+i)+j));
        }
        printf("\n");
    }
};

//dict function is just a hand made toupper function because i didnt know if we could use it at all.
char dict(char let){
    if (let == 'a'){ return 'A';}
    else if (let == 'b'){ return 'B';} 
    else if (let == 'c'){ return 'C';} 
    else if (let == 'd'){ return 'D';} 
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
//cap is the function that pushes a string and updates it using dict passes by value tho.
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

//core function to check adjacent positions for connections, recursive, and backs up and searches againif a particular path doesn't work
//Its a specialized depth first search function without any graph structures.
int searchAdjacent(char** arr, char* word, int row, int col, int a, poisData* valList){
    
    if(a == wSize){ //the fulll word was found
        return 1;
    }
    if (row < 0 || row >= bSize || col < 0 || col >= bSize){
            return 0;
        }

        
    (valList + a)->x = col;
    (valList + a)->y = row;
    (valList + a)->wallop = *(word + a);
    (valList + a)->boal = 1;

    for(int i = 0; i < 8; i++){
        int nRow = row + *(dy + i);
        int nCol = col + *(dx + i);
        //iterating forward
        if(searchAdjacent(arr, word, nRow, nCol, a+1, valList)){
            return 1; // word match found
        }
    }
    //not found, go back and find another.
    (valList + a)->boal = 0;
    return 0;
};

//this prints the solution table
void printSol(int found, poisData *inde){
    char *msg0 = "Word not found! \n";
    char *msg = "Word found! \n";
    char *msg2 = "Printing the search path: \n";

    int tracker = 0;
    int varp = 0;
    
    if (found == 1)
    {
        printf( "\n%s%s", msg, msg2);
        //this for loop is not to be touched and just works. it prints out the board
        //with the proper specified dimensions
        for (int i = 0; i < bSize; i++)
        {   for (int j = 0; j < bSize; j++)
            {   for (int k = 0; k < wSize; k++)
                {   if (i == (inde+k)->y && j == (inde+k)->x)
                    {
                        printf("%i", k+1);
                        varp++;       
                        tracker = 1;
                    }
                }
                if (tracker == 0){ printf("0       "); }
                else
                {   for (int q = 0; q < 8-varp; q++)
                    {printf(" "); }
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
void searchPuzzle(char** arr, char* word) {
    // This function checks if arr contains the search word. If the word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a different message as shown in the sample runs.
    // Your implementation here...
    int found = 0;
    char* WORD = cap(word);    
    wSize = (strlen(WORD));

    //stores directional data
    dx = (int *)malloc(8 * sizeof(int));
    dy = (int *)malloc(8 * sizeof(int));
    inDirect();

    poisData *indHolder = (poisData*)malloc(wSize*sizeof(poisData));
    //additonal logic so recursion works correctly
    //checks if the index is in the board and the word is currently being found
    for (int i = 0; i < bSize && !found; i++) {
        for(int j = 0; j < bSize && !found; j++){
            if ((*(*(arr+i)+j)) == *(WORD+0)){
                for(int a = 0; a < wSize; a++){
                    (indHolder+a)->boal = 0;
                }

                if(searchAdjacent(arr, WORD, i, j, 0, indHolder)){
                    found = 1;
                }
            }
        }
    }
    printSol(found, indHolder);
};