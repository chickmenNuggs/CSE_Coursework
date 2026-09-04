#include <stdio.h>
int main()
{
    int reps;
    int buhg;


    int boil;

    char key[] = "Coding with C is awesome! \n";
    char broke[] = "Cading wiht is C avesone! \n";
    char prompt[] = "Enter the repetition count for the punishment phrase: ";
    char prompt2[] = "Enter the line where you want to insert the typo: ";
    char p1error[]= "You entered an invalid value for the repetition count! Please re-enter: ";
    char p2error[] = "You entered an invalid value for the typo placement! Please re-enter: ";

    printf("%s",prompt);
    scanf("%d", &reps);
    if (reps < 1)
    {
        int boil = 1;
        while (boil == 1)
        {
            printf("%s",p1error);
            scanf("%d", &reps);
            if (reps >=1)
            {
                boil = 0;
                break;
            }
        }
    }

    printf("%s",prompt2);
    scanf("%d", &buhg);
    if (buhg <=0 || buhg > reps)
    {
        while (buhg <=0 || buhg > reps)
        {
            printf("%s",p2error);
            scanf("%d", &buhg);
        }
    }

    for (int i = 1; i < reps+1; i++)
    {
        if (buhg == i)
        {
           printf("%s",broke); 
        }
        
        else
        {
            printf("%s",key);
        }   
    }
    

return 0;
}