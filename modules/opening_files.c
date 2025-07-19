#include <stdio.h>

FILE* open_phone_book(const char* mode)
{
    FILE* file = fopen("phone_book.txt", mode);

    if(file == NULL)
    {
        perror("phone_book.txt");
        return 0;
    }

    return file;
}