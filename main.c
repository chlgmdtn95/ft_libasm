#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>        // errno 사용

extern size_t ft_strlen(char *in);
extern char *ft_strcpy(char *dst, char *src);
extern int ft_strcmp(char *s1, char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);  // ft_write 추가

int main()
{
    char in[100];
    char *src = "this is for test\n";
    char dst[100];
    size_t len;

    write(1, "enter string\n", 13);
    len = read(0, in, 40);
    in[len] = '\0';
    write(1, in, strlen(in));
    write(1, in, ft_strlen(in));

    write(1, "\nstrcpy test\n", 13);
    write(1, src, strlen(src));
    ft_strcpy(dst, src);
    write(1, dst, ft_strlen(dst));

    write(1, "\nstrcmp test\n", 13);
    char *t1 = "2";
    char *t2 = "";
    printf("strcmp: %d\n", strcmp(t1, t2));
    printf("ft_strcmp: %d\n", ft_strcmp(t1, t2));
    
    // errno 테스트 추가
    write(1, "\nft_write errno test\n", 21);
    
    // 성공 케이스
    ssize_t result = ft_write(1, "Success!\n", 9);
    printf("ft_write result: %zd\n", result);
    
    // 실패 케이스 (잘못된 fd)
    errno = 0;  // errno 초기화
    result = ft_write(-1, "test", 4);
    if (result == -1) {
        printf("ft_write failed! errno: %d\n", errno);
        perror("ft_write error");  // 에러 메시지 출력
    }
    
    return 0;
}