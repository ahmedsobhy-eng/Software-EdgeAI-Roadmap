#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
       char ch;
       char s[100];
       char sen[100];

       // 1. save input
       scanf("%c", &ch);
       scanf("%s", s);
       scanf("\n");             // لمسح السطر الجديد المتبقي قبل قراءة الجملة
       scanf("%[^\n]%*c", sen); // لقراءة الجملة كاملة بالمسافات لحد نهاية السطر

       // 2. print output
       printf("%c\n", ch);
       printf("%s\n", s);
       printf("%s\n", sen);

       return 0;
}