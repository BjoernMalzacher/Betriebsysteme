#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int list[10][10];
   
   
         for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            list[j][i] = (i+1)*(j+1);
        }
        
    }
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            printf("%d : ",list[j][i]);
        }

        printf("\n");
    }
    
    return 0;
}


