#include <iostream>
#include <fstream>
#include <vector> 

using namespace std;

const int numb = 10;
const int maxVal = 4;

void printArr(vector<vector<int>>matrix){
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < numb; j++)
        {
            cout << matrix[i][j] <<";";
        }
    cout<< endl;
    }
};

void countingSort (vector<vector<int>> &matrix, int piff){
    vector<vector<int>> outMatrix(matrix.size(),vector<int>(numb));
    int i, count[maxVal] = { 0, 0, 0, 0};

    for (int i = 0; i < matrix.size(); i++)
    {   //gets instance count
        count[(matrix[i][piff])]++;
    }
    for (int i = 1; i < maxVal; i++)
    {   //moves instance into position
        count[i] += count[i - 1];
    }

    for (int i = matrix.size() - 1; i >= 0; i--) 
    {   
        count[matrix[i][piff]]--;
        outMatrix[count[matrix[i][piff]]] = matrix[i];
    }

    matrix = outMatrix;
};

void radixSort(vector<vector<int>> &matrix){
    for (int piff = 9; piff >= 0 ; piff--)
    {
        countingSort(matrix, piff);
    }
};

int main(){
    int size;
    cin >> size;

    vector<vector<int>> matrix(size, vector<int>(numb));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < numb; j++)
        {
            cin >> matrix[i][j];
        }
    }

    radixSort(matrix);
    
    printArr(matrix);
    
    return 0;
};