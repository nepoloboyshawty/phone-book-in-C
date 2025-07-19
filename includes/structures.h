#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

enum {
    max_size_name = 24,
    max_size_surname = 24,
    max_size_number = 8
};

typedef struct {
    int id;
    char name[max_size_name];
    char surname[max_size_surname];
    char number[max_size_number];
} person_info;

#endif