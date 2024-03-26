/*
File : project02_v1.c
Created : 2024-03-27
Author : 김현지
*/
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

void main()
{
    int menu_num;
    book* head = (book*)malloc(sizeof(book));
    head->next = NULL;

    while(1)
    {
        printf("******도서관리 프로그램******\n");
        printf("1. 도서 구입(등록)\n");
        printf("2. 도서 검색\n");
        printf("3. 도서 삭제\n");
        printf("4. 도서 출력\n");
        printf("0. 종료\n\n");

        printf("메뉴를 입력하세요. > ");
        scanf("%d", &menu_num);

        if(menu_num == 1) {
            post_addMenu(head);
        }
        else if(menu_num == 2) {
            searchMenu(head);
        }
        else if(menu_num == 3) {
            deleteMenu(head);
        }
        else if(menu_num == 4) {
            printMenu(head);
        }
        else if(menu_num == 0) {
            printf("\n");
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("올바른 숫자를 입력하세요.\n");
            continue;
        }
        getchar();
    }
}

void post_addMenu(book* head)
{
    char title[30];
    char author[30];
    char publisher[30];
    int price;

    printf("\n");
    printf("도서 제목을 입력하세요 : ");
    scanf("%s", title);
    printf("도서 저자를 입력하세요 : ");
    scanf("%s", author);
    printf("도서 출판사를 입력하세요 : ");
    scanf("%s", publisher);
    printf("도서 가격을 입력하세요 : ");
    scanf("%d", &price);
    printf("\n");

    printf("%s을(를) 성공적으로 등록하였습니다!!\n\n", title);

    book* newBook = (book*)malloc(sizeof(book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->publisher, publisher);
    newBook->price = price;
    newBook->rent_available = 0;

    newBook->next = NULL;
    if(head->next == NULL) {
        head->next = newBook;
    }
    else {
        book* curr = head->next;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newBook;
    }
}
void printMenu(book* head)
{
    book* curr = head->next;
    if(curr == NULL) {
        printf("\n");
        printf("등록된 도서가 없습니다.\n\n");
        return;
    }
    else {
        printf("\n");
        printf("도서 목록 : \n");
        while(curr != NULL) {
            printf("제 목 : %s | 저 자 : %s | 출판사 : %s | 가 격 : %d | 대여 여부 : %s\n\n",
                    curr->title, curr->author, curr->publisher, curr->price, curr->rent_available ? "대여중" : "대여 가능");
            curr = curr->next;
        }
    }
}

void deleteMenu(book* head)
{
    char title[30];
    printf("\n");
    printf("삭제할 도서 제목을 입력하세요 : ");
    scanf("%s", title);

    book* curr = head->next;
    while(curr != NULL) {
        if(strcmp(curr->title, title) == 0) {
            head->next = curr->next;
            free(curr);
            printf("도서가 삭제되었습니다.\n\n");
            return;
        }
        curr = curr->next;
    }
    printf("삭제할 도서를 찾을 수 없습니다!!\n\n");
}

void searchMenu(book* head)
{
    char title[30];
    printf("\n");
    printf("검색할 도서 제목을 입력하세요 : ");
    scanf("%s", title);

    book*curr = head->next;
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            printf("%s이(가) 존재합니다.\n", title);
            rentMenu(head);
            return;
        }
        curr = curr->next;
    }
    printf("도서가 존재하지 않습니다.\n\n");
}

void rentMenu(book* head)
{
    char title[30];
    printf("\n");
    printf("대여할 도서 제목을 입력하세요 : ");
    scanf("%s", title);

    book*curr = head->next;
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            if(curr->rent_available) {
                printf("이 책은 이미 대여 중입니다.\n\n");
            }
            else {
                char answer;
                printf("\n");
                printf("이 책을 대여하시겠습니까? (Y/N) : ");
                getchar();
                scanf("%c", &answer);

                if(answer == 'Y' || answer == 'y') {
                printf("도서가 대여되었습니다!!\n\n");
                curr->rent_available = 1;
                }
                else if(answer == 'N' || answer == 'n') {
                    printf("대여가 취소되었습니다.\n\n");
                }
                else {
                    printf("잘못된 입력입니다. 대여가 취소됩니다.\n\n");
                }
            }
            return;
        }
        curr = curr->next;
    }
    printf("도서가 존재하지 않습니다.\n\n");
}