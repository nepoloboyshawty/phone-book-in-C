#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/input_utils.h"
#include "../includes/structures.h"
#include "../includes/validity_func.h"
#include "../includes/contacts.h"

bool prompt_and_read_name(person_info* info)
{
    printf("Введите имя человека, которого хотите добавить в телефонную книгу.\n");
    printf("Если вы желаете выйти, введите 'q'.\n\033[1m\033[32mВаш ответ\033[0m: ");

    while(true)
    {
        if(scanf("%23s", info->name) != 1)
        {
            printf("\nДлина имени не должна привышать 23 символов.\n");
            printf("Введите имя человека, которого хотите добавить в телефонную книгу.\n\033[1m\033[32mВаш ответ\033[0m: ");
            clear_buffer_input();
        }
        else if(tolower(info->name[0]) == 'q' && info->name[1] == '\0')
        {
            return false;
        }
        else
        {
            clear_buffer_input();
            break;
        }
    }
    return true;
}

bool prompt_and_read_surname(person_info* info)
{
    printf("\nВведите фамилию человека, которого хотите добавить в телефонную книгу.\n\033[1m\033[32mВаш ответ\033[0m: ");

    while(true)
    {
        if(scanf("%23s", info->surname) != 1)
        {
            printf("\nДлина фамилии не должна привышать 23 символов.\n");
            printf("Введите фамилию человека, которого хотите добавить в телефонную книгу.\n\033[1m\033[32mВаш ответ\033[0m: ");
            clear_buffer_input();
        }
        else if(tolower(info->surname[0]) == 'q' && info->surname[1] == '\0')
        {
            return false;
        }
        else
        {
            clear_buffer_input();
            break;
        }
    }
    return true;
}

bool prompt_and_read_phone(person_info* info)
{
    printf("\nВведите номер человека, которого хотите добавить в телефонную книгу (например, 123-456).\n\033[1m\033[32mВаш ответ\033[0m: ");

    while(true)
    {
        scanf("%7s", info->number);

        if(is_valid_phone_format(info->number))
        {
            clear_buffer_input();
            break;
        }
        else if(tolower(info->number[0]) == 'q' && info->number[1] == '\0')
        {
            return false;
        }
        else
        {
            clear_buffer_input();
            break;
        }
    }
    return true;
}

void сollect_data(void)
{
    person_info* person = malloc(sizeof(*person));

    while(true)
    {
        system("clear");

        if(prompt_and_read_name(person) == false) break;
        if(prompt_and_read_surname(person) == false) break;
        if(prompt_and_read_phone(person) == false) break;

        record_contact(person);

        free(person);

        return;
    }
}