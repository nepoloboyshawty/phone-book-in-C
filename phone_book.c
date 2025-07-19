#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "includes/input_utils.h"
#include "includes/structures.h"
#include "includes/func_to_add.h"
#include "includes/contacts.h"

int main(void)
{
    char action;
    bool is_unknown_action = false;

    while(true)
    {
        system("clear");

        printf("Здравствуйте! Вы открыли телефонную книгу. Выберите действие ниже:\n\n");
        printf("[1] Добавить контакт.\n[2] Просмотреть контакты.\n[3] Удалить контакт.\n[CTRL + C] Выйти.\n");

        if(is_unknown_action == true)
        {
            printf("\n[ERROR] Неизвестное действие.\n");
        }

        printf("\n\033[1m\033[32mВаш ответ\033[0m: ");

        if(scanf(" %d", &action) != 1)
        {
            is_unknown_action = true;

            clear_buffer_input();
            continue;
        }

        switch(action)
        {
            case 1:
                clear_buffer_input();
                сollect_data();

                is_unknown_action = false;
                break;

            case 2:
                clear_buffer_input();
                show_contacts();
                
                is_unknown_action = false;
                break;

            case 3:
                clear_buffer_input();
                delete_contact();
                
                is_unknown_action = false;
                break;

            default:
                is_unknown_action = true;
                clear_buffer_input();
                break;
        }
    }
    return 0;
}