#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void print(vector<int> arr){

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ";";
    };
}

void merge(vector<int> &arr, int start, int end){
    int mid = (start+end)/2;
    int left = mid - start + 1;
    int right = end - mid;

    vector<int> tempL(left);
    vector<int> tempR(right);

    for (int i = 0; i < left; i++)
    {
        tempL[i] = arr[start + i];
    };
    for (int i = 0; i < right; i++)
    {
        tempR[i] = arr[mid + 1 + i];
    };
    int i = 0, j = 0;
    int para = start;
    
   do
    {
        if (tempL[i] <= tempR[j])
        {
            arr[para] = tempL[i];
            i++;
        }
        else{
            arr[para] = tempR[j];
            j++;
        }  
        para++;    
    }
   while ((i < left) && (j < right));
   

   for (i; i < left; i++)
   {
        arr[para] = tempL[i];
        para++;
   };
   
   for (j; j < right; j++)
   {
        arr[para] = tempR[j];
        para++;
   };
   
};


void mSort(vector<int> &arr, int l, int r){
    if ( l >= r)
    {   
        return;  
    };
    int mid = (l+r) / 2;
    mSort(arr, l, mid);
    mSort(arr, mid + 1, r);
    merge(arr, l, r);
};


int main () {
    int size;
    cin >> size;
    int varTemp;

    vector<int> arr(size);

    for (int i = 0; i < size; i++)
    {
        cin >> varTemp;
        arr.at(i) = (varTemp);
    };

    mSort(arr, 0, size-1);
    print(arr);
    return 0;
};