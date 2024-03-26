/*
File : project02_v1.c
Created : 2024-03-27
Author : ������
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
        printf("******�������� ���α׷�******\n");
        printf("1. ���� ����(���)\n");
        printf("2. ���� �˻�\n");
        printf("3. ���� ����\n");
        printf("4. ���� ���\n");
        printf("0. ����\n\n");

        printf("�޴��� �Է��ϼ���. > ");
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
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�ùٸ� ���ڸ� �Է��ϼ���.\n");
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
    printf("���� ������ �Է��ϼ��� : ");
    scanf("%s", title);
    printf("���� ���ڸ� �Է��ϼ��� : ");
    scanf("%s", author);
    printf("���� ���ǻ縦 �Է��ϼ��� : ");
    scanf("%s", publisher);
    printf("���� ������ �Է��ϼ��� : ");
    scanf("%d", &price);
    printf("\n");

    printf("%s��(��) ���������� ����Ͽ����ϴ�!!\n\n", title);

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
        printf("��ϵ� ������ �����ϴ�.\n\n");
        return;
    }
    else {
        printf("\n");
        printf("���� ��� : \n");
        while(curr != NULL) {
            printf("�� �� : %s | �� �� : %s | ���ǻ� : %s | �� �� : %d | �뿩 ���� : %s\n\n",
                    curr->title, curr->author, curr->publisher, curr->price, curr->rent_available ? "�뿩��" : "�뿩 ����");
            curr = curr->next;
        }
    }
}

void deleteMenu(book* head)
{
    char title[30];
    printf("\n");
    printf("������ ���� ������ �Է��ϼ��� : ");
    scanf("%s", title);

    book* curr = head->next;
    while(curr != NULL) {
        if(strcmp(curr->title, title) == 0) {
            head->next = curr->next;
            free(curr);
            printf("������ �����Ǿ����ϴ�.\n\n");
            return;
        }
        curr = curr->next;
    }
    printf("������ ������ ã�� �� �����ϴ�!!\n\n");
}

void searchMenu(book* head)
{
    char title[30];
    printf("\n");
    printf("�˻��� ���� ������ �Է��ϼ��� : ");
    scanf("%s", title);

    book*curr = head->next;
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            printf("%s��(��) �����մϴ�.\n", title);
            rentMenu(head);
            return;
        }
        curr = curr->next;
    }
    printf("������ �������� �ʽ��ϴ�.\n\n");
}

void rentMenu(book* head)
{
    char title[30];
    printf("\n");
    printf("�뿩�� ���� ������ �Է��ϼ��� : ");
    scanf("%s", title);

    book*curr = head->next;
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            if(curr->rent_available) {
                printf("�� å�� �̹� �뿩 ���Դϴ�.\n\n");
            }
            else {
                char answer;
                printf("\n");
                printf("�� å�� �뿩�Ͻðڽ��ϱ�? (Y/N) : ");
                getchar();
                scanf("%c", &answer);

                if(answer == 'Y' || answer == 'y') {
                printf("������ �뿩�Ǿ����ϴ�!!\n\n");
                curr->rent_available = 1;
                }
                else if(answer == 'N' || answer == 'n') {
                    printf("�뿩�� ��ҵǾ����ϴ�.\n\n");
                }
                else {
                    printf("�߸��� �Է��Դϴ�. �뿩�� ��ҵ˴ϴ�.\n\n");
                }
            }
            return;
        }
        curr = curr->next;
    }
    printf("������ �������� �ʽ��ϴ�.\n\n");
}