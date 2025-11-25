#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height;

    do
    {
        Height = get_int("height: ");
    }
    while (Height < 1 | Height > 8);

    for (int i = 1; i <= Height; i++)
    {
        for (int space = 1; space <= Height - i; space++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
