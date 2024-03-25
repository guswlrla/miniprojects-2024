/*
- �ι�° project. ���Ḯ��Ʈ �ڷᱸ���� �������� ���α׷��� �ۼ��Ͻÿ�.
v1 ->
------�޴�------
1. ���� ����(���)
2. ���� �˻� - �˻��� ������ ������ ����Ѵ�.
3. ���� ����
4. ���� ���
0. ����

v2 -> 
------�޴�------
1. ���� ����(���)
2. ���� �˻� - �˻� �� �뿩�� ����� �����Ѵ�.
3. ���� ����
4. ���� ���
0. ����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BOOK {
    char title[30];
    char author[30];
    char publisher[30];
    char price[30];
    int borrow;
    struct BOOK* next;
}book;

book* head = NULL;

void post_addMenu(book*);
void printMenu(book*);
void deleteMenu(book*);
void searchMenu(book*);

void main()
{
    int menu_num;

    while(1)
    {
        printf("******�������� ���α׷�******\n");
        printf("1. ���� ����(���)\n");
        printf("2. ���� �˻�\n");
        printf("3. ���� ����\n");
        printf("4. ���� ���\n");
        printf("0. ����\n");

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
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�ùٸ� ���ڸ� �Է��ϼ���.\n");
            continue;
        }       
    }
}

void post_addMenu(book* head)
{
    char title[30];
    char author[30];
    char publisher[30];
    char price[30];

    printf("���� ������ �Է��ϼ��� : ");
    scanf("%s", title);
    printf("���� ���ڸ� �Է��ϼ��� : ");
    scanf("%s", author);
    printf("���� ���ǻ縦 �Է��ϼ��� : ");
    scanf("%s", publisher);
    printf("���� ������ �Է��ϼ��� : ");
    scanf("%d", price);
    printf("\n");

    printf("%s��(��) ���������� ����Ͽ����ϴ�!!\n\n", title);
    
    book* newBook = (book*)malloc(sizeof(book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->publisher, publisher);
    strcpy(newBook->price, price);

    newBook->next = NULL;
    if(head->next == NULL) { // ����� next�� NULL�϶�, ����Ű�� �ʴ� ����(ù��° ��带 ����)
        head->next = newBook; // ���ο� ��� ����
    }
    else { // ù��° ��� ���� ����
        book* curr = head->next; //curr�� ù��° ���
        while(curr->next != NULL) { // ù��° ��尡 �ٸ� ��带 ����Ű�� ���� ��
            curr = curr->next; // curr next�� curr�� ����, ���� ��带 curr�� �ٲ�
        }
    curr->next = newBook; // ���ο� ��忡 ����
    }
}

void printMenu(book* head)
{
    book* curr = head->next; // curr�� ���� ��带 ����Ŵ
    if(curr == NULL) {
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }
    else {
        printf("���� ��� : \n");
        while(curr != NULL) { // ���� �� ��µǵ���
        printf("�� �� : %s | �� �� : %s | ���ǻ� : %s | �� �� : %s\n", curr->title, curr->author, curr->publisher, curr->price); // ���� ������ ���
        curr = curr->next; // curr�� ���� ��带 ����Ű���� ��
        }
    }
}

void deleteMenu(book* head)
{
    char title[30];
    printf("������ ���� ������ �Է��ϼ��� : ");
    scanf("%s", title);

    book* curr = head->next;
    while(curr != NULL) {
        if(strcmp(curr->title, title) == 0) {
            head->next = curr->next;
            free(curr);
            printf("������ �����Ǿ����ϴ�.\n");
            return;
        }
        curr = curr->next;
    }
    printf("������ ������ ã�� �� �����ϴ�.\n");
}

void searchMenu(book* head)
{
    char title[30];
    printf("�˻��� ���� ������ �Է��ϼ��� : ");
    scanf("%s", title);

    book*curr = head->next;
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            printf("������ ã�ҽ��ϴ�!!\n", title);
            printf("�� �� : %s | �� �� : %s | ���ǻ� : %s | �� �� : %s\n", 
                    curr->title, curr->author, curr->publisher, curr->price, curr->borrow ? "�뿩 ����" : "�뿩 ��");

            if(curr->borrow) {
                printf("�뿩�Ͻðڽ��ϱ�? (Y/N) : ");
                char answer;
                scanf("%c", &answer);
                if(answer == 'Y' || answer == 'y'); {
                    curr->borrow = 0;
                    printf("������ �뿩�Ǿ����ϴ�.\n");
                }
                printf("�뿩�� ����մϴ�.\n");
                
            printf("������ �̹� �뿩 ���Դϴ�.\n");
            
            return;
            }
        }
        curr = curr->next;
    }
    printf("������ �������� �ʽ��ϴ�.\n");
}
