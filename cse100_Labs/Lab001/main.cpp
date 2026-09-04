#include <iostream>
#include <fstream>
using namespace std;

// int min (int &A, int&B){
//     if (A < B)
//     {
//         return A;
//     }
//     else if (B < A)
//     {
//         return B;
//     }
// };

int main() {
    int* varA;

    int max;
    int* arr;
    int size = 1;

    // varA = new int;
    

    for (int i = 0; i < size; i++)
    {
        cin >> size;
        arr = new int[size];
        cin >> arr[i];
        cout << arr[i];
    }

}