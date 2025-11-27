#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    float l = 0;
    float h = 1;
    float n = 0;
    float a = strlen(text);

    for (int x = 0; x < a; x++)
    {
        if (isalpha(text[x]) != 0)
        {
            l++;
        }

        if (text[x] == 32)
        {
            h++;
        }

        if (text[x] == 46 || text[x] == 33 || text[x] == 63)
        {
            n++;
        }
    }

    float L = 100 * (l / h);
    float S = 100 * (n / h);

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}
