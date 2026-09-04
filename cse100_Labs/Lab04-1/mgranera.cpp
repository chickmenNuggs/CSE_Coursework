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

void heapifyPremium(int* arr, int size, int i){
    int larg, l, r; 
     larg = i;
     l = 2*i+1;
     r = 2*i+2;
    
     // choosing largest node in size
     if (l < size && arr[l] > arr[larg])
     {
        larg = l;
     }
     if (r < size && arr[r] > arr[larg])
     {
        larg = r;
     }
     //exchanging i with largest node?
     if (larg != i)
     {  
        //updates larg to be largest node
        int temp = arr[i];
        arr[i] = arr[larg];
        arr[larg] = temp;
        //moves through the tree
        heapifyPremium(arr, size, larg);
     }
};

void heapSort(int* arr, int size){

    //right side
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyPremium(arr, size, i);
    };

    //left side
    for (int i = size - 1; i > 0; i--) {
        //moves node through tree?
        int temp = arr[0]; 
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyPremium(arr, i, 0);
    };
};


int main(){
    int size;
    cin >> size;

    int* arr = nullptr;
    arr = new int[size];

    for (int i = 0; i < size; i++)
    { cin >> arr[i]; };

    heapSort(arr, size);

    printArr(arr, size);

    delete[] arr;
    arr = NULL;
    
    return 0;
};