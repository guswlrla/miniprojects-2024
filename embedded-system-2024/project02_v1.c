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
            printf("%s이(가) 존재합니다.\n", title);
            return;
        }
        curr = curr->next;
    }
    printf("도서가 존재하지 않습니다.\n");
}

/*
1 #include <stdio.h>
  2 #include <stdlib.h>
  3
  4 typedef struct NODE
  5 {
  6   int data;
  7   struct NODE* next;
  8 }node;
  9
 10 headNode* creatHeadNode(void)
 11 {
 12   node* newNode = (node*)malloc(sizeof(node));
 13   newNode->next = NULL;
 14
 15 }
 16
 17 void pre_addNode(node* pnode, int _data) // 전위삽입
 18 {
 19   node* newNode = (node*)malloc(sizeof(node)); // 노드생성
 20   newNode-> data = _data;
 21   newNode->next = pnode->next;
 22   pnode->next = newNode;
 23 }
 24
 25 void post_addNode(node* pnode, int _data) // 후위삽입
 26 {
 27   node* newNode = (node*)malloc(sizeof(node));
 28   newNode-> data = _data; // 새로운 노드에 데이터 값 넣음
 29   newNode->next = NULL; // 새로운 노드의 next를 NULL로 설정
 30
 31   if(pnode->next == NULL)// 헤더의 next가 NULL일때, 가리키지 않는 상태(첫번째 노드를 연결)
 32   {
 33     pnode->next = newNode; // 새로운 노드 생성
 34   }
 35   else  // 첫번째 노드 연결 이후
 36   {
 37     node* curr = pnode->next; //curr은 첫번째 노드
 38     while(curr->next != NULL) // 첫번째 노드가 다른 노드를 가리키고 있을 때
 39     {
 40       curr = curr->next; // curr next를 curr에 대입, 다음 노드를 curr로 바꿈
 41     }
 42     curr->next = newNode; // 새로운 노드에 연결
 43   }
 44 }
 45
 46 void showNode(node* pnode) // 출력함수
 47 {
 48   node* curr = pnode->next; // curr가 현재 노드를 가리킴
 49   while(curr != NULL) // 값이 다 출력되도록
 50   {
 51     printf("%d", curr->data); // 현재 데이터 출력
 52     curr = curr->next; // curr가 다음 노드를 가리키도록 함
 53   }
 54 }
 55
 56 void allFreeNode(node* pnode) // 전체 메모리 해제
 57 {
 58   node* curr = pnode->next;
 59   while(curr != NULL)
 60   {
 61     free(curr);
 62     curr = curr->next;
 63   }
 64 }
 65
 66 void main()
 67 {
 68   node* head = (node*)malloc(sizeof(node)); // 헤드 노드 생성
 69   head->next = NULL;  // 헤드 노드의 next 포인터를  NULL로 초기화
 70
 71   head->data = 0;
 72
 73   pre_addNode(head, 10); // 첫번째 노드로 삽입
 74   pre_addNode(head, 20);
 75   pre_addNode(head, 30);
 76   pre_addNode(head, 40);
 77   pre_addNode(head, 50);
 78
 79   node* curr = head->next; // curr을 첫번째 노드로 설정
 80   while(curr != NULL) // curr이 NULL이 아닐 때까지
 81   {
 82     printf("%d\n", curr->data);
 83     curr = curr->next; // curr을 다음 노드로 이동
 84   }
 85
 86   // 노드 삭제
 87   curr = head->next;
 88   while(curr != NULL)
 89   {
 90     head->next = curr->next;
 91     free(curr); // 노드 메모리 해제
 92     curr = head->next;
 93   }
 94   printf("%d, %d\n", head->next, curr);
 95   free(curr);
 96
 97   showNode(head); // 출력함수 호출
 98
 99   free(head);
100 }
*/