#include <stdio.h>
struct reactangledata
{
       int x;
       int y;
       int width;
       int height;
};
typedef struct reactangledata react;

int max(int a, int b)
{

       if (a > b)
       {

              return a;
       }
       else
              return b;
}

int min(int a, int b)
{

       if (a < b)
       {
              return a;
       }
       else
              return b;
}

void intersection(react r1, react r2)
{
       int new_height;
       int new_width;
       react r3;
       r3.x = max(r1.x, r2.x);
       r3.y = max(r1.y, r2.y);

       r3.width = min(r1.x + r1.width, r2.x + r2.width);
       r3.height = min(r1.y + r1.height, r2.y + r2.height);
       new_width = r3.width - r3.x;
       new_height = r3.height - r3.y;
       if (new_height < 0)
       {

              r3.height = 0;
              r3.x = 0;
              r3.y = 0;
              r3.width = 0;
       }
       if (new_width < 0)
       {

              r3.height = 0;
              r3.x = 0;
              r3.y = 0;
              r3.width = 0;
       }

       printf("the intersection x is %d\n", r3.x);
       printf("the intersection y is %d\n", r3.y);
       printf("the intersection width is%d\n", new_width);
       printf("the intersection height is %d\n", new_height);
}

int main()
{
       react r1;
       react r2;
       printf("enter the first rect has x then y then width finally  height\n");
       scanf("%d", &r1.x);
       scanf("%d", &r1.y);
       scanf("%d", &r1.height);
       scanf("%d", &r1.width);
       printf("enter the second rect has x then y then width finally  height\n");
       scanf("%d", &r2.x);
       scanf("%d", &r2.y);
       scanf("%d", &r2.height);
       scanf("%d", &r2.width);
       if (r1.width < 0)
       {

              r1.x = r1.x + r1.width;
              r1.width = -r1.width;
       }
       if (r2.width < 0)
       {

              r2.x = r2.x + r2.width;
              r2.width = -r2.width;
       }

       intersection(r1, r2);
       return 0;
}