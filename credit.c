#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long factor = 1;
    long long temp = 1;
    long long size = 0;
    long long sum = 0;
    int product = 1;
    int index = 0;

    //get a digit from the user
    long long cardNumber = get_long_long("Number: ");
    temp = cardNumber;

    //split the card number into individual digits
    while (temp > 0)
    {
        temp /= 10;
        factor *= 10;
        size++;
    }

    //make an array to store the single digits from the card number
    //Size is how many digits were in the card number
    int digits[size];

    //fill the array that we just made
    while (factor > 1)
    {
        factor /= 10;

        digits[index++] = cardNumber / factor;
        cardNumber %= factor;
    }

    //multiply every other digit by two and add them together
    for (int i = size - 2; i >= 0; i -= 2)
    {
        product = digits[i] * 2;

        if (product > 9)
        {
            sum += product / 10;
            sum += product % 10;
        }
        else
        {
            sum += product;
        }
    }

    //add the rest of the digits to the total sum
    for (int i = size - 1; i >= 0; i -= 2)
    {
        sum += digits[i];
    }

    //check if the card did not pass Luhn's algorithm print INVALID
    //the rest of the if else statement should be ignored by the program
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }

    //if the card number starts with four and is 13 to 16 digits long then it is a Visa card
    else if (digits[0] == 4 && size >= 13 && size <= 16)
    {
        printf("VISA\n");
    }

    //if the card number starts with a 34 or a 37 and is 15 digits long then it is an American Express card
    else if (digits[0] == 3 && size == 15)
    {
        if (digits[1] == 4 || digits[1] == 7)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    //if the card starts with 51, 52, 53, 54, or 55 and is 16 digits long then it is a Master card
    else if (digits[0] == 5 && size == 16)
    {
        if (digits[1] == 1 || digits[1] == 2 || digits[1] == 3 || digits[1] == 4 || digits[1] == 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    //if it is none of these then the card is invalid
    else
    {
        printf("INVALID\n");
    }

    return 0;
}