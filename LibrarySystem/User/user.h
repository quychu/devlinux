#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct{
    int id;
    char name[MAX];
    int book_borrowed[5];
} User;

extern User g_User[MAX];
extern int g_User_count;

void add_user();
void display_users();
int find_user_index_by_id(int id);
void edit_user();
void delete_user();

#endif