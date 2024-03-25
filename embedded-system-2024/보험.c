#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 책 정보를 담는 구조체
typedef struct Book {
    char title[100];
    char author[100];
    char publisher[100];
    float price;
    struct Book *next;
} Book;

// 연결 리스트를 관리하는 구조체
typedef struct Library {
    Book *head;
} Library;

// 도서 추가 함수
void addBook(Library *lib) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("메모리 할당 오류\n");
        return;
    }

    printf("도서 제목: ");
    scanf("%s", newBook->title);
    printf("저자: ");
    scanf("%s", newBook->author);
    printf("출판사: ");
    scanf("%s", newBook->publisher);
    printf("가격: ");
    scanf("%f", &(newBook->price));

    newBook->next = lib->head;
    lib->head = newBook;

    printf("도서가 등록되었습니다.\n");
}

// 도서 검색 함수
void searchBook(Library *lib) {
    char title[100];
    printf("검색할 도서 제목을 입력하세요: ");
    scanf("%s", title);

    Book *current = lib->head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("도서가 존재합니다.\n");
            return;
        }
        current = current->next;
    }
    printf("도서가 존재하지 않습니다.\n");
}

// 도서 삭제 함수
void removeBook(Library *lib) {
    char title[100];
    printf("삭제할 도서 제목을 입력하세요: ");
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
            printf("도서가 삭제되었습니다.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("삭제할 도서를 찾을 수 없습니다.\n");
}

// 도서 출력 함수
void printBooks(Library *lib) {
    Book *current = lib->head;

    if (current == NULL) {
        printf("등록된 도서가 없습니다.\n");
        return;
    }

    printf("도서 목록:\n");
    while (current != NULL) {
        printf("제목: %s | 저자: %s | 출판사: %s | 가격: %.2f\n", current->title, current->author, current->publisher, current->price);
        current = current->next;
    }
}

// 메뉴 출력 함수
void printMenu() {
    printf("\n------메뉴------\n");
    printf("1. 도서 구입(등록)\n");
    printf("2. 도서 검색\n");
    printf("3. 도서 삭제\n");
    printf("4. 도서 출력\n");
    printf("0. 종료\n");
}

int main() {
    Library lib;
    lib.head = NULL;
    int choice;

    do {
        printMenu();
        printf("선택: ");
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
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("올바른 메뉴 번호를 입력하세요.\n");
        }
    } while (choice != 0);

    return 0;
}
