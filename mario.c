#include <stdio.h>
#include <cs50.h>

void printChar(char);

int main(void)
{
    //rows is the number of rows that the final "pipe" will have
    int rows = 0;

    //get the number of rows from the user, and make sure that the value is between 1 and 22 inclusive
    do
    {
        rows = get_int("Height: ");
    }
    while (rows < 0 || rows > 23);

    char toPrint = '#';

    //print the pipe!
    for (int i = 1; i <= rows; i++)
    {
        for (int j = i; j < rows; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf("%c", toPrint);
        }

        printf("  ");

        for (int j = 0; j < i; j++)
        {
            printf("%c", toPrint);
        }

        printf("\n");
    }

}