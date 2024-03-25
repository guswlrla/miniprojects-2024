/*
- 두번째 project. 연결리스트 자료구조로 도서관리 프로그램을 작성하시오.
v1 ->
------메뉴------
1. 도서 구입(등록)
2. 도서 검색 - 검색한 도서의 유무만 출력한다.
3. 도서 삭제
4. 도서 출력
0. 종료

v2 -> 
------메뉴------
1. 도서 구입(등록)
2. 도서 검색 - 검색 후 대여의 기능을 구현한다.
3. 도서 삭제
4. 도서 출력
0. 종료
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
        printf("******도서관리 프로그램******\n");
        printf("1. 도서 구입(등록)\n");
        printf("2. 도서 검색\n");
        printf("3. 도서 삭제\n");
        printf("4. 도서 출력\n");
        printf("0. 종료\n");

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
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("올바른 숫자를 입력하세요.\n");
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

    printf("도서 제목을 입력하세요 : ");
    scanf("%s", title);
    printf("도서 저자를 입력하세요 : ");
    scanf("%s", author);
    printf("도서 출판사를 입력하세요 : ");
    scanf("%s", publisher);
    printf("도서 가격을 입력하세요 : ");
    scanf("%d", price);
    printf("\n");

    printf("%s을(를) 성공적으로 등록하였습니다!!\n\n", title);
    
    book* newBook = (book*)malloc(sizeof(book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->publisher, publisher);
    strcpy(newBook->price, price);

    newBook->next = NULL;
    if(head->next == NULL) { // 헤더의 next가 NULL일때, 가리키지 않는 상태(첫번째 노드를 연결)
        head->next = newBook; // 새로운 노드 생성
    }
    else { // 첫번째 노드 연결 이후
        book* curr = head->next; //curr은 첫번째 노드
        while(curr->next != NULL) { // 첫번째 노드가 다른 노드를 가리키고 있을 때
            curr = curr->next; // curr next를 curr에 대입, 다음 노드를 curr로 바꿈
        }
    curr->next = newBook; // 새로운 노드에 연결
    }
}

void printMenu(book* head)
{
    book* curr = head->next; // curr가 현재 노드를 가리킴
    if(curr == NULL) {
        printf("등록된 도서가 없습니다.\n");
        return;
    }
    else {
        printf("도서 목록 : \n");
        while(curr != NULL) { // 값이 다 출력되도록
        printf("제 목 : %s | 저 자 : %s | 출판사 : %s | 가 격 : %s\n", curr->title, curr->author, curr->publisher, curr->price); // 현재 데이터 출력
        curr = curr->next; // curr가 다음 노드를 가리키도록 함
        }
    }
}

void deleteMenu(book* head)
{
    char title[30];
    printf("삭제할 도서 제목을 입력하세요 : ");
    scanf("%s", title);

    book* curr = head->next;
    while(curr != NULL) {
        if(strcmp(curr->title, title) == 0) {
            head->next = curr->next;
            free(curr);
            printf("도서가 삭제되었습니다.\n");
            return;
        }
        curr = curr->next;
    }
    printf("삭제할 도서를 찾을 수 없습니다.\n");
}

void searchMenu(book* head)
{
    char title[30];
    printf("검색할 도서 제목을 입력하세요 : ");
    scanf("%s", title);

    book*curr = head->next;
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            printf("도서를 찾았습니다!!\n", title);
            printf("제 목 : %s | 저 자 : %s | 출판사 : %s | 가 격 : %s\n", 
                    curr->title, curr->author, curr->publisher, curr->price, curr->borrow ? "대여 가능" : "대여 중");

            if(curr->borrow) {
                printf("대여하시겠습니까? (Y/N) : ");
                char answer;
                scanf("%c", &answer);
                if(answer == 'Y' || answer == 'y'); {
                    curr->borrow = 0;
                    printf("도서가 대여되었습니다.\n");
                }
                printf("대여를 취소합니다.\n");
                
            printf("도서가 이미 대여 중입니다.\n");
            
            return;
            }
        }
        curr = curr->next;
    }
    printf("도서가 존재하지 않습니다.\n");
}
