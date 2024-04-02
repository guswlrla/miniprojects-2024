/*
- 첫번째 project. 아이디와 비밀번호를 입력하여 맞으면 본인의 정보가 저장된 파일을 open한다.
  파일명 : myinfo.txt
*/

/*
File : project01.c
Created : 2024-03-13
Author : 김현지
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcmp 함수가 포함된 헤더 파일

void main()
{
  char id[30] = "iot2024";
  char pw[30] = "login123";
  char data[100] = "이름 : 김현지, 나이 : 24세";
  
  FILE* fp;
  FILE* cpfp;

  while(1) {
    printf("--------로그인--------\n\n");

    printf("아이디 : ");
    scanf("%s", id);
    printf("비밀번호 : ");
    scanf("%s", pw);
    printf("\n");

    if(strcmp(id, "iot2024") == 0 && strcmp(pw, "login123") == 0) {
      printf("로그인 성공!!\n");

      fp = fopen("myinfo.txt", "w");
      if(fp == NULL) {
        fprintf(stderr, "Error");
        exit(1);
      }
      else {
      fprintf(fp, "%s", data);
      printf("%s\n", data);
      fclose(fp);
      }

      fp = fopen("myinfo.txt", "r");
      if(fp == NULL) {
        fprintf(stderr, "Error");
        exit(1);
      }
      else {
      fscanf(fp, "%s", data);
      fclose(fp);
      }

      break;
    }
    else {
      printf("아이디 또는 비밀번호를 잘못 입력했습니다.\n\n");
    }
  }
}