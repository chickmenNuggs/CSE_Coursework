#include <iostream>
#include <fstream>
#include <random>
using namespace std;

void printArr(int arr[], int size){
       for (int i = 0; i < size; i++)
    {   
        cout << arr[i] << ";" ;
    }
    
};

int getRandPiv(int a, int b){
    int r = (rand() % b);
    return r;
};

int partition (int * arr, int a, int b){
    int x = arr[b];
    int tempVar;
    int i;
    i = a - 1;

    for (int  j = a; j < b; j++)
    {
        if (arr[j] <= x){

            i++;
            tempVar = arr[j];
            arr[j] = arr[i];
            arr[i] = tempVar;

        };
    }

    tempVar = arr[b];
    arr[b] = arr[i+1];
    arr[i+1] = tempVar;

    return (i + 1);
};

int byParts(int* arr, int a, int b ){

    int i = getRandPiv(a,b);
    int tempArr[2];
    
    tempArr[0] = arr[a];
    tempArr[1] = arr[b];

    arr[b] = tempArr[0];
    arr[a] = tempArr[1];

    return partition(arr, a, b);
};

void QuickSort(int* arr, int low, int high){
    if (low < high)
    {
        int pi = byParts(arr, low, high);

        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
};


int main(){
    int size;
    cin >> size;

    int* arr = nullptr;
    arr = new int[size];

    for (int i = 0; i < size; i++)
    { cin >> arr[i]; };

    QuickSort(arr, 0, size-1);
    
    printArr(arr, size);
    
    delete[] arr;
    
    return 0;
};