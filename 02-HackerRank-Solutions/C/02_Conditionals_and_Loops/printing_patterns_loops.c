#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// دالة مساعدة بترجع الرقم الأصغر بين رقمين
int min(int a, int b)
{
       if (a < b)
       {
              return a;
       }
       return b;
}

int main()
{
       int n;
       scanf("%d", &n);

       int size = 2 * n - 1;

       for (int i = 0; i < size; i++)
       {
              for (int j = 0; j < size; j++)
              {
                     int top = i;
                     int left = j;
                     int bottom = (size - 1) - i;
                     int right = (size - 1) - j;

                     int min_dist = min(min(top, bottom), min(left, right));

                     printf("%d ", n - min_dist);
              }
              printf("\n");
       }

       return 0;
}