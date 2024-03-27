#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

void main()
{
    int menu_num;
    book* head = (book*)malloc(sizeof(book));
    head->next = NULL;

    while (1)
    {
        printf("******�������� ���α׷�******\n");
        printf("1. ���� ����(���)\n");
        printf("2. ���� �˻�\n");
        printf("3. ���� ����\n");
        printf("4. ���� ���\n");
        printf("0. ����\n\n");

        printf("�޴��� �Է��ϼ���. > ");
        scanf("%d", &menu_num);

        if (menu_num == 1) {
            post_addMenu(head);
        }
        else if (menu_num == 2) {
            searchMenu(head);
        }
        else if (menu_num == 3) {
            deleteMenu(head);
        }
        else if (menu_num == 4) {
            printMenu(head);
        }
        else if (menu_num == 0) {
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
    book* curr = head;
    while (curr != NULL) {
        book* temp = curr;
        curr = curr->next;
        free(temp);
    }
}