#include <stdio.h>



int sum(int m, int n){
    int res = 0;
    res = m + n;
    return res;
};

int main(){
    int m = 10;
    int n = 5;
    int x = 0;
    x = sum(m, n);
    printf("%i",x);
};


