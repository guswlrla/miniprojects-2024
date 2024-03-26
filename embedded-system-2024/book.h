#ifndef BOOK_H
#define BOOK_H

typedef struct BOOK {
    char title[30];
    char author[30];
    char publisher[30];
    int price;
    int rent_available;
    struct BOOK* next;
}book;

void post_addMenu(book* head);
void printMenu(book* head);
void deleteMenu(book* head);
void searchMenu(book* head);
void rentMenu(book* head);

#endif