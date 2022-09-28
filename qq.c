#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "logo.c"
#include "Help.c"
int main(int argi, char *argc[]) 
{   
    logo();
    printf("Работу выполнил Михайлов Артём ИВТ-11\n");
    printf("Задача: Инвертировать столбцы двумерного массива M*N\n");
    if (argi < 4)
    {
        printf("!!!Ошибка. Недостаточно аргументов!!!\n");
        printf("\n");
        Help();
        _Exit (EXIT_SUCCESS);
    }
    if (argi > 4)
    {
        printf("!!!Ошибка. Переизбыток элементов!!!\n");
        printf("\n");
        Help();
        _Exit (EXIT_SUCCESS);
    }
    srand((unsigned int)time(NULL));
    int i, j;
    int n = atoi(argc[1]);
    int m = atoi(argc[2]);
    int A[n][m];
    char Buffer[20];
    if ((n > 10)||(m > 10)||(n < 1)||(m < 1))
    {
        printf("!!!Ошибка. Некоректные параметры!!!\n");
        printf("\n");
        Help();
        _Exit (EXIT_SUCCESS);
    }
	if (strcmp(argc[3],"ruchki")==0)
    {
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("Введите элемент под [%d][%d]\n", i, j);
                fgets(Buffer,10,stdin);
                A[i][j] =atoi(Buffer);
            }
            
        }
    }
    else if (strcmp(argc[3],"random")==0)
    {
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                A[i][j] = rand()%10;
            }
        }
    }
    else
    {
        printf("!!!Ошибка. Некоректные параметры!!!\n");
        printf("\n");
        Help();
        _Exit (EXIT_SUCCESS);
    }

    
    printf("\n");

    printf("Исходный двумерный массив M*N:\n");

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    printf("Инвертированный двумерный массив M*N:\n");

    for(i = (m - 1); i >= 0; i--)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
	
}
