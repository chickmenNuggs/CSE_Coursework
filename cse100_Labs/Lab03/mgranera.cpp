#include <iostream>
#include <fstream>


using namespace std;

int findMaxCrossSub(int* a, int low, int mid, int high){
    int sum, lSum, rSum, maxL, maxR;
    lSum = -99999999999999;
    sum = 0;
    
    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum > lSum)
        {
            lSum = sum;
        }
    }

    rSum = -9999999999999;
    sum = 0;
    for (int i = mid+1; i <= high; i++)
    {
        sum += a[i];
        if (sum > rSum)
        {
            rSum = sum;
        }   
    }
return (lSum + rSum);
};

int findMaxSub(int* a, int low, int high){
    int lSum, rSum, mid, cSum; 
    if (low >= high)
    {
        return (a[low]);
    }
    else
    {
        mid = ((low+(high-low)/2));
        lSum = findMaxSub(a, low, mid);
        rSum = findMaxSub(a, mid+1, high);
        int sum = findMaxCrossSub(a, low, mid, high);
        if (lSum > rSum && lSum > sum)
        {
            return lSum;
        }
        else if (rSum > lSum && rSum > sum)
        {
            return rSum;
        }
        else{
            return sum;
        }
    }  
};

int main(){
    int size;
    cin >> size;
    int varTemp;
    int maxSubArr;
    int low,high, sum, start, end;
    low = 0;
    high = size - 1;
    
    int* arr = nullptr;

    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    };


    sum = findMaxSub(arr, low, high);

    cout << sum;

    delete[] arr;
    
    return 0;
};