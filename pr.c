#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include"list.h"
#include"logo.c"

int main(int argc, char *argv[])
{   logo(); //LOGOTIP)
    printf("В списке целых чисел последовательности одинаковых чисел длиной более 3 заменить одним числом\n");
    srand(time(NULL));
    int i, tmpRand, tmpRuch[100], count, a, b, c, l;
    
    FILE *config;
    char Conf_Name[50] = "testo.cfg",buffer[100];
    int sposob=0,elementov=0, nach=0, kolvo=0;
    
    if((config=fopen(Conf_Name,"r"))==NULL)
    {
    puts("Config file error!!!");
    puts("Press Enter!!!");
    getchar();exit(0);
    }

    fgets(buffer,80,config);
    if(!strstr(buffer,"#!MYCONFIG"))
    {
    puts("Config file error!!!");
    puts("Press Enter!!!");
    getchar();fclose(config);
    exit(0);
    }

    while(1)
    {
    fgets(buffer,80,config);
    if(feof(config))break;
    if(buffer[0]=='#')continue;
    if(buffer[0]=='!'){puts(buffer);continue;}
    if(strstr(buffer,"sposob="))
        {
            sposob=atoi(buffer+strlen("sposob="));
            continue;
        }
    if(strstr(buffer,"elementov="))
        {
            elementov=atoi(buffer+strlen("elementov="));
            continue;
        }
    }
    puts("=============Result of parsing config file ========");
    printf("sposob = %d\n",sposob);
    printf("elementov = %d\n",elementov);
    puts("Press Enter!!!");
    getchar();fclose(config);
    
    if(sposob != 1 && sposob != 2)
        {
            printf("Некорректный способ заполнения списка\n");
            return 1;
        }
        // "объект" ЛОС с инициализацией
    List list;
    list.head = NULL;
    list.size = 0;

    if (sposob == 2)
    {
        size_t t;
        tmpRand = rand()%3;
        //printf("%d ", tmpRand);
        list = Insert(list, tmpRand);
        for(i = 1; i < elementov; i++)
        {
            tmpRand = rand()%3;
            //printf("%d ", tmpRand);
            //list = Insert_back(list, tmpRand);
            list = Insert(list, tmpRand);
        }
        Print(list);
    }
    if (sposob == 1)
    {
        size_t t;
        i = 0;
        printf("Введите элемент списка: \n");
        scanf("%d", &tmpRuch[i]);
        list = Insert(list, tmpRuch[i]);
        for(i = 1; i < elementov; i++)
        {
            printf("Введите элемент списка: \n");
            scanf("%d", &tmpRuch[i]);
            list = Insert_back(list, tmpRuch[i]);
        }
        Print(list);
    }
    printf("\n");

    list = Destroy_sublist( list );
    printf("Конечный список после преобразования: \n");
    Print( list );
}
