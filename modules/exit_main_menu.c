#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "../includes/input_utils.h"

void exit_main_menu(void)
{
    printf("\nВведите букву 'q' для выхода в главное меню...\n\033[1m\033[32mВаш ответ\033[0m: ");

    while(true)
    {
        char answer = tolower(getchar());
        clear_buffer_input();
        
        if(answer == 'q')
        {
            return;
        }
        else
        {
            printf("\nЕсли хотите выйти, то введите букву 'q' для выхода в главное меню...\n\033[1m\033[32mВаш ответ\033[0m: ");
        }
    }
}