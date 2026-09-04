#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void print(int arr[], int size){

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ";";
    }
}

void sort(int *arr, int size){
 for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        print(arr, i+1);
        cout << endl;
    }
}

int main () {
    int size;

    cin >> size;

    int arr[size];
    int varTemp;
    int tempArr[size];
    int key;

    for (int i = 0; i < size; i++)
    {
        cin >> varTemp;
        arr[i] = varTemp;
    }
    sort(arr, size);
    return 0;
};
