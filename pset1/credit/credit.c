#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n = get_long("NUMBER: ");

    int i = 0;
    long count = n;
    while (count > 0)
    {
        count = count / 10;
        i++;
    }

    int d1 = 0;
    int d2 = 0;
    long x = n;
    int total = 0;
    int b1, b2, m1, m2;

    do
    {
        b1 = x % 10;
        x = x / 10;
        d1 += b1;

        b2 = x % 10;
        x = x / 10;
        b2 = b2 * 2;

        m1 = b2 % 10;
        m2 = b2 / 10;

        d2 += m1 + m2;
    }
    while (x > 1);

    total = d1 + d2;

    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    long g2 = n;
    while (g2 > 100)
    {
        g2 = g2 / 10;
    }
    if (i == 15 && (g2 == 34 || g2 == 37))
    {
        printf("AMEX\n");
        return 0;
    }

    long g1 = n;
    while (g1 > 100)
    {
        g1 = g1 / 10;
    }
    if (i == 16 && (g1 >= 51 && g1 <= 55))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    long g3 = n;
    while (g3 > 10)
    {
        g3 = g3 / 10;
    }
    if ((i == 13 || i == 16) && g3 == 4)
    {
        printf("VISA\n");
        return 0;
    }

    printf("INVALID\n");
}
