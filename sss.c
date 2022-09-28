#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 21. Дана строка символов S S …S , в которой могут встречаться цифры, пробелы, буква “E” и знаки “+”, “-“. 
// Известно, что первый символ S является цифрой. Из данной строки выделить подстроки, разделенные пробелами. 
// Определить, является ли первая подстрока числом. Если да, то выяснить: целое или вещественное число, положительное или отрицательное.

int main(int argc, char const *argv[])
{
	printf("Вариант 21. Выполнил Суворов Николай. Группа ИВТ-11.\n");
	int count = 0, digCount = 0, check = 0;
	char* filename = "input.txt";
	FILE* file = fopen(filename, "r");
	char buffer[500];
	char sDigit[10];
	fgets(buffer, 50, file);
	for(int i = 0; i < strlen(buffer); i++)
		{
			if(buffer[i] != ' ')
				{
					putchar(buffer[i]);
				}
			else printf("\n");
		}
		for(int i = 0; i < strlen(buffer); i++)
		{
			if(buffer[i] != ' ')
			{
				count++;
			}
			if(buffer[i] == ' ') break;
		}
		for (int i = 0; i < count; ++i)
		{
			if (buffer[0] == '+' || buffer[0] == '-')
			{
				sDigit[i] = buffer[i+1];
			}
			else sDigit[i] = buffer[i];

		}
		for (int i = 0; i < count; ++i)
		{
			if (isdigit(sDigit[i]))
			{
				digCount++;
			}
		}
		for (int i = 0; i < count; ++i)
		{
			if ((sDigit[i] == 'E')||(sDigit[i] == '+')||(sDigit[i] == '-'))
			{
				printf("Первая подстрока не является числом. \n");
				return 1;
			}
		}
		for (int i = 0; i < count; ++i)
		{ 
			if(sDigit[i] == '.' || sDigit[i] == ',')
				{
					//printf("Первая подстрока является вещественным числом. \n");
					check++;
				}
		}

		if (check == 1)
		{
			if (buffer[0] == '+' || buffer[0] >= '0' && buffer[0] <='9')
	      {
	        printf("Первая подстрока является числом вещественным положительным. \n");
	      }
	      if (buffer[0] == '-')
	      {
	      	printf("Первая подстрока является числом вещественным отрицательным. \n");
	      }	     
		}
			
			if (check == 0)
			     {
			     	if (buffer[0] == '+' || buffer[0] >= '0' && buffer[0] <='9')
	      {
	        printf("Первая подстрока является числом целым положительным. \n");
	      }
	      if (buffer[0] == '-')
	      {
	      	printf("Первая подстрока является числом целым отрицательным. \n");
	      }	
			     }     
		
	return 0;
}