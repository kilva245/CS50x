#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int H;
    do
    {
        H = get_int("height: ");
    }
    while (H < 1 | H > 8);

    for (int i = 1; i <= H; i++)
    {

        for (int s = 1; s <= H - i; s++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int x = 1; x <= i; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}