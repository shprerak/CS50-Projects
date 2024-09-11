#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void print_the_grade(float k, int n);
int main(void)
{
    int ltcounter = 0;
    int wdcounter = 1;
    int sncounter = 0;
    string text = get_string("Enter text: ");
    int n = strlen(text);
    for (int i = 0; i < n + 1; i++)
    {
        if ((text[i] >=65 && text[i] <=90) || (text[i] >= 97 && text[i] <= 122))
        {
            ltcounter++;
        }
        else if (text[i] == 32)
        {
            wdcounter++;
        }
        else if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sncounter++;
        }
    }
    float index = 0.0588 * ((ltcounter * 100) / wdcounter) - 0.296 * ((sncounter * 100) / wdcounter) - 15.8;
    int p = index;
    float q = p;
    if (index < (q + 0.55))
    {
        print_the_grade(index, p);
    }
    else
    {
        print_the_grade(index, p + 1);
    }
}

void print_the_grade(float k, int n)
{
    if (k < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (k > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
    printf("Grade %i\n", n);
    }

}
