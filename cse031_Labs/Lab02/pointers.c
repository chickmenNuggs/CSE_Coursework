#include <stdio.h>
int main() {

int x, y, *px, *py;
int arr[10];

x = 1, y = 2;
px = &x;
py = &y;


for (int i = 0; i < 10; i++)
{
   arr[i] = i;
}

printf("%p \n", &x);
printf("%p \n", &y);
printf("%p \n", px);
printf("%p \n", py);

for (int i = 0; i < 10; i++)
{
    printf("%p \n", &arr[i]);
}

for (int i = 0; i < 10; i++)
{
    printf("%i \n", *(arr+i));
}

printf("%p \n", &arr);
printf("%p \n", &arr[0]);
printf("%p \n", arr);



return 0;
}