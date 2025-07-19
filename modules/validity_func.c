#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


bool is_valid_phone_format(const char* number)
{
    return strlen(number) == 7 && isdigit(number[0]) && isdigit(number[1]) 
           && isdigit(number[2]) && number[3] == '-' && isdigit(number[4]) 
           && isdigit(number[5]) && isdigit(number[6]);
}

bool is_book_full(FILE* file)
{
    char buffer[61];
    int count = 0;

    while(fgets(buffer, sizeof(buffer), file))
    {
        count++;
    }

    if(count >= 100)
    {
       return true;
    }

    return false;
}