#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void quicksort(int *number,int first,int last, int count){
int i, j, pivot, temp;
if(first<last)
{
  pivot=first;
  i=first;
  j=last;
  while(i<j)
  {
    while(number[i]<=number[pivot]&&i<last)
    i++;
    while(number[j]>number[pivot])
    j--;
    if(i<j)
    {
      temp=number[i];
      number[i]=number[j];
      number[j]=temp;
      count ++;
    }
  }
  temp=number[pivot];
  number[pivot]=number[j];
  number[j]=temp;
  quicksort(number,first,j-1, count);
  quicksort(number,j+1,last, count);
}
}


int main(void)
{
int i, j, k, n, temp, tmp, step;
  long long count = 0;
  int *a;
  clock_t start, end;
  double time_spent;
  // printf("Selection sort started\n");
  // for (n = 100000; n <= 1000000; n += 100000)
  // {
  //   a = (int *)malloc(n * sizeof(int));
  //   for (i = 0; i < n; i++)
  //   {
  //     a[i] = rand() % n;
  //   }
  //   start = clock();
  //   for (i = 0; i < n; i++)
  //   {
  //     for (j = i + 1; j < n; j++)
  //     {
  //       if (a[i] > a[j])
  //       {
  //         temp = a[i];
  //         a[i] = a[j];
  //         a[j] = temp;
  //         count++;
  //       }
  //     }
  //   }
  //   end = clock();
  //   time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  //   printf("Swap count %lld elements %d time %.6f\n", count, n, (double)(end - start) / CLOCKS_PER_SEC);
  //   free(a);
  //   count = 0;
  // }
  printf("\n\n");
  printf("Shell sort started\n");
  for (n = 100000; n <= 1000000; n += 100000)
  {
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
      a[i] = rand() % n;
    }
    start = clock();
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < a[j - step])
                {
                  a[j] = a[j - step];
                  count++;
                }
                else
                {
                  break;
                }
            }
            a[j] = tmp;
        }
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Swap count %lld elements %d time %.6f\n", count, n, (double)(end - start) / CLOCKS_PER_SEC);
    free(a);
    count = 0;
  }
  printf("\n\n");
  printf("Quick sort started\n");
  for (n = 100000; n <= 1000000; n += 100000)
  {
    count = 0 ;
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
      a[i] = rand() % n;
    }
    start = clock();
    quicksort(a,0,n-1, count);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Swap count %lld elements %d time %.6f\n", count, n, (double)(end - start) / CLOCKS_PER_SEC);
    free(a);
    count = 0;
  }
}