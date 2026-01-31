#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef enum{
    AVAILABLE = 1,
    BORROWED  = 0
} BookStatus;

typedef struct{
    int id;
    char title[MAX];
    char author[MAX];
    BookStatus status;
} Book;

extern Book g_Book_library[MAX];
extern int g_Book_count;

void add_book();
void display_book();
int find_book_index_by_id(int id);
void delete_book();
void edit_book();
void search_book_by_title_or_author();

#endif