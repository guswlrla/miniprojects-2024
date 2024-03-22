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

typedef struct BOOK {
    char title[30];
    char author[30];
    char publisher[30];
    char price[30];
    struct BOOK* next;
}book;

void main()
{
    int menu_num;

    while(1) {
        printf("-----------도서관리 프로그램-----------\n");
        printf("1) 도서구입, 2) 도서검색, 3) 도서삭제, 4) 도서출력, 0) 종료 > ");
        scanf("%d", menu_num);

        if(menu_num == 1) {
            
        }
        else if(menu_num == 2) {

        }
        else if(menu_num == 3) {

        }
        else if(menu_num == 4) {

        }
        else if(menu_num == 0) {
            break;
        }
        else {
            printf("올바른 숫자를 입력하세요.\n");
            continue;
        }       
    }
}