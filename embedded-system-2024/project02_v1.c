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
    struct BOOK* next;
}book;

void addMenu();
void searchMenu();

void main()
{
    book* head = NULL;
    int menu_num;

    while(1) {
        printf("******도서관리 프로그램******\n");
        printf("1. 도서 구입(등록)\n");
        printf("2. 도서 검색\n");
        printf("3. 도서 삭제\n");
        printf("4. 도서 출력\n");
        printf("0. 종료\n");

        printf("메뉴를 입력하세요. > ");
        scanf("%d", &menu_num);

        if(menu_num == 1) {
            addMenu();
        }
        else if(menu_num == 2) {
            searchMenu();
        }
        else if(menu_num == 3) {

        }
        else if(menu_num == 4) {

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

void addMenu(book* head)
{
    book* newNode = (book*)malloc(sizeof(book));
    
    printf("도서 제목을 입력하세요 : ");
    scanf("%s", newNode->title);
    printf("도서 저자를 입력하세요 : ");
    scanf("%s", newNode->author);
    printf("도서 출판사를 입력하세요 : ");
    scanf("%s", newNode->publisher);
    printf("도서 가격을 입력하세요 : ");
    scanf("%s", newNode->price);
    printf("\n");

    newNode->next = head;
    head = newNode;

    printf("%s을(를) 성공적으로 등록하였습니다!!\n\n", newNode->title);
}


void searchMenu(book* head)
{
    char _title[30];
    printf("검색할 도서 제목을 입력하세요 :");
    scanf("%s", title);
    book* curr = head;
    while(curr != NULL) {
        if(strcmp(curr->title, title) == 0) {
            printf("[%s] 도서가 존재합니다.\n", title);
            return;
        }
        curr = curr->next;
    }
    printf("[%s] 도서가 존재하지 않습니다.\n", title);
}

/*
void delete()
{

}

void show()
{

}
*/