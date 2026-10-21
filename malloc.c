#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char fname[100];
    char *buffer;
    int start, end, current_line = 1;
    size_t buffer_size = 100;

    printf("파일의 이름을 입력하시오.\n");
    scanf("%99s", fname);  // 파일 이름 입력 (크기 제한)

    // 파일 열기
    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;  // 파일 열기 실패 시 종료
    } else {
        printf("파일 열기 성공\n");
    }

    // 시작 줄과 끝 줄 입력 받기
    printf("출력할 시작 줄 번호를 입력하시오.\n");
    scanf("%d", &start);
    printf("출력할 끝 줄 번호를 입력하시오.\n");
    scanf("%d", &end);

    // 동적 메모리 할당
    buffer = (char *)malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        printf("메모리 할당 실패\n");
        fclose(fp);
        return 1;  // 메모리 할당 실패 시 종료
    }

    // 파일에서 줄을 읽고 출력
    while (fgets(buffer, buffer_size, fp) != NULL) {
        if (current_line >= start && current_line <= end) {
            printf("%s", buffer);  // 해당 범위의 줄을 출력
        }
        current_line++;

        // 끝 줄을 넘으면 종료
        if (current_line > end) {
            break;
        }
    }

    // 메모리 해제 및 파일 닫기
    free(buffer);
    fclose(fp);

    return 0;
}
