#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BOOK {
    char title[30];
    char author[30];
    char publisher[30];
    int price;
    int rent_available;
    struct BOOK* next;
}book;

void post_addMenu(book*);
void printMenu(book*);
void deleteMenu(book*);
void searchMenu(book*);
void rentMenu(book*);

#endif