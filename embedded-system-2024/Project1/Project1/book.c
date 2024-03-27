#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

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
    if (head->next == NULL) {
        head->next = newBook;
    }
    else {
        book* curr = head->next;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newBook;
    }
}
void printMenu(book* head)
{
    book* curr = head->next;
    if (curr == NULL) {
        printf("\n");
        printf("��ϵ� ������ �����ϴ�.\n\n");
        return;
    }
    else {
        printf("\n");
        printf("���� ��� : \n");
        while (curr != NULL) {
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
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
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

    book* curr = head->next;
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            printf("%s��(��) �����մϴ�.\n\n", title);
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

    book* curr = head->next;
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            if (curr->rent_available) {
                printf("�� å�� �̹� �뿩 ���Դϴ�.\n\n");
            }
            else {
                char answer;
                printf("�� å�� �뿩�Ͻðڽ��ϱ�? (Y/N) : ");
                getchar();
                scanf("%c", &answer);

                if (answer == 'Y' || answer == 'y') {
                    printf("������ �뿩�Ǿ����ϴ�!!\n\n");
                    curr->rent_available = 1;
                }
                else if (answer == 'N' || answer == 'n') {
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