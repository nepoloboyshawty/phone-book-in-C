#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#include "../includes/opening_files.h"
#include "../includes/structures.h"
#include "../includes/validity_func.h"
#include "../includes/exit_main_menu.h"
#include "../includes/input_utils.h"

static int find_last_id(FILE* file)
{
    fseek(file, -2, SEEK_END);

    while(ftell(file) > 0)
    {
        if(fgetc(file) == '\n') break;
        fseek(file, -2, SEEK_CUR);
    }

    int last_id = 0;

    fscanf(file, "%d,", &last_id);

    return last_id;
}

void record_contact(person_info* info)
{
    FILE* recording = open_phone_book("a+");

    if(is_book_full(recording))
    {
        printf("\nВ вашей телефонной книге не может быть больше 100 контактов.\n");
        sleep(3);
        return;
    }

    for(int i = 0; i < 1; ++i)
    {
        fseek(recording, 0, SEEK_END);
        int file_is_empty = (ftell(recording) == 0);
        
        if(file_is_empty)
        {
            info->id = 1;

            fprintf(recording, "%d, %s %s %s", info->id, info->name, info->surname, info->number);
            fputc('\n', recording);
        }
        else
        {
            info->id = find_last_id(recording) + 1;

            fprintf(recording, "%d, %s %s %s", info->id, info->name, info->surname, info->number);
            fputc('\n', recording);
        }
    }
    
    fclose(recording);
}

static int сompare_data(const void* str_char_1, const void* str_char_2)
{
    const person_info* str_ch_1 = (const person_info*)str_char_1;
    const person_info* str_ch_2 = (const person_info*)str_char_2;

    return strcasecmp(str_ch_1->name, str_ch_2->name);
}

void print_contacts(void)
{
    FILE* phone_book = open_phone_book("r");

    person_info contact_list[100];
    int count = 0;

    while(count < 99 && fscanf(phone_book, "%d, %23s %23s %7s", 
        &contact_list[count].id, contact_list[count].name, 
        contact_list[count].surname, contact_list[count].number) == 4)
    {
        count++;
    }

    fclose(phone_book);

    qsort(contact_list, count, sizeof(person_info), сompare_data);

    for(int i = 0; i < count; ++i)
    {
        printf("[ID: %d] Имя: %s | Фамилия: %s | Номер телефона: %s.\n", 
            contact_list[i].id, contact_list[i].name, contact_list[i].surname, contact_list[i].number);
    }
}

static int get_id_to_delete()
{
    printf("\nВыберите ID контакта выше, которого желаете удалить.\n");
    printf("Чтобы выйти, введите любой буквенный символ.\n\033[1m\033[32mВаш ответ\033[0m:\n");

    int selected_id;

    if(scanf("%d", &selected_id) != 1)
    {
        clear_buffer_input();
        return -1;
    }

    return selected_id;
}

static bool delete_contact_by_id(FILE* src, FILE* dst, int id)
{
    char line[61];
    int current_id;
    bool is_contact_found = false;

    while(fgets(line, sizeof(line), src))
    {
        if(sscanf(line, "%d,", &current_id) == 1)
        {
            if(current_id == id)
            {
                is_contact_found = true;
                continue;
            }
        }
        fputs(line, dst);
    }

    return is_contact_found;
}

void delete_contact(void)
{
    system("clear");

    print_contacts();

    int id = get_id_to_delete();
    if(id == -1) return;

    FILE* phone_book = open_phone_book("r");
    FILE* temp_file = fopen("temp_file.txt", "w");

    if(temp_file == NULL)
    {
        perror("temp_file.txt");
        fclose(phone_book);
        return;
    }

    bool is_deleted = delete_contact_by_id(phone_book, temp_file, id);

    fclose(phone_book);
    fclose(temp_file);

    if(is_deleted)
    {
        printf("\nКонтакт с ID %d успешно удален...\n", id);
        
        remove("phone_book.txt");
        rename("temp_file.txt", "phone_book.txt");
        
        sleep(3);
    }
    else
    {
        printf("\nКонтакт с ID %d не найден...\n", id);
        remove("temp_file.txt");

        sleep(3);
    }
}

void show_contacts(void)
{
    while(true)
    {
        system("clear");
        print_contacts();
        exit_main_menu();
        break;
    }
}
