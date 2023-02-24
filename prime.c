#include <stdio.h>

int main()
{
    printf("%d\n",1);

    for(int i=2;i<=20;i++)
    {
        for(int j=2;j<=i;j++)
        {
            if ((i%j != 0) && (i%i==0))
            {
              continue;
            }
            else
            {
                if (j==i)
                {
                  printf("%d\n",i);
                }
                break;
            }
        }

    }

    return 0;
}
