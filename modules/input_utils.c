#include <stdio.h>

void clear_buffer_input(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}