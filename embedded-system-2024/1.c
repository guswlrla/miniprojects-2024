#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// å ������ ��� ����ü
typedef struct Book {
    char title[100];
    char author[100];
    char publisher[100];
    float price;
    struct Book *next;
} Book;

// ���� ����Ʈ�� �����ϴ� ����ü
typedef struct Library {
    Book *head;
} Library;

// ���� �߰� �Լ�
void addBook(Library *lib) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return;
    }

    printf("���� ����: ");
    scanf("%s", newBook->title);
    printf("����: ");
    scanf("%s", newBook->author);
    printf("���ǻ�: ");
    scanf("%s", newBook->publisher);
    printf("����: ");
    scanf("%f", &(newBook->price));

    newBook->next = lib->head;
    lib->head = newBook;

    printf("������ ��ϵǾ����ϴ�.\n");
}

// ���� �˻� �Լ�
void searchBook(Library *lib) {
    char title[100];
    printf("�˻��� ���� ������ �Է��ϼ���: ");
    scanf("%s", title);

    Book *current = lib->head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("������ �����մϴ�.\n");
            return;
        }
        current = current->next;
    }
    printf("������ �������� �ʽ��ϴ�.\n");
}

// ���� ���� �Լ�
void removeBook(Library *lib) {
    char title[100];
    printf("������ ���� ������ �Է��ϼ���: ");
    scanf("%s", title);

    Book *current = lib->head;
    Book *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                lib->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("������ �����Ǿ����ϴ�.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("������ ������ ã�� �� �����ϴ�.\n");
}

// ���� ��� �Լ�
void printBooks(Library *lib) {
    Book *current = lib->head;

    if (current == NULL) {
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }

    printf("���� ���:\n");
    while (current != NULL) {
        printf("����: %s | ����: %s | ���ǻ�: %s | ����: %.2f\n", current->title, current->author, current->publisher, current->price);
        current = current->next;
    }
}

// �޴� ��� �Լ�
void printMenu() {
    printf("\n------�޴�------\n");
    printf("1. ���� ����(���)\n");
    printf("2. ���� �˻�\n");
    printf("3. ���� ����\n");
    printf("4. ���� ���\n");
    printf("0. ����\n");
}

int main() {
    Library lib;
    lib.head = NULL;
    int choice;

    do {
        printMenu();
        printf("����: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&lib);
                break;
            case 2:
                searchBook(&lib);
                break;
            case 3:
                removeBook(&lib);
                break;
            case 4:
                printBooks(&lib);
                break;
            case 0:
                printf("���α׷��� �����մϴ�.\n");
                break;
            default:
                printf("�ùٸ� �޴� ��ȣ�� �Է��ϼ���.\n");
        }
    } while (choice != 0);

    return 0;
}
