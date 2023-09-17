#include <stdio.h>
#include <stdlib.h>

int happyTicketsCount()
{
    int sums[28] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                ++sums[i + j + k];
            }
        }
    }
    int happyTickets = 0;
    for (int i = 0; i < 28; i++)
    {
        happyTickets += sums[i] * sums[i];
    }
    return happyTickets;
}

int main()
{
    printf("The amount of happy tickets is %d", happyTicketsCount());
}
