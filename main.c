#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dst, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
#define BLUE "\033[0;34m"

void print_test_header(const char *test_name) {
    printf("\n" BLUE "========== %s ==========" RESET "\n", test_name);
}

void test_strlen() {
    print_test_header("ft_strlen TEST");
    
    char *test1 = "Hello, World!";
    char *test2 = "";
    char *test3 = "42";
    char *test4 = "This is a longer string for testing purposes";
    
    printf("Test 1: \"%s\"\n", test1);
    printf("  strlen:    %zu\n", strlen(test1));
    printf("  ft_strlen: %zu %s\n", ft_strlen(test1), 
           strlen(test1) == ft_strlen(test1) ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("Test 2: \"\" (empty string)\n");
    printf("  strlen:    %zu\n", strlen(test2));
    printf("  ft_strlen: %zu %s\n", ft_strlen(test2),
           strlen(test2) == ft_strlen(test2) ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("Test 3: \"%s\"\n", test3);
    printf("  strlen:    %zu\n", strlen(test3));
    printf("  ft_strlen: %zu %s\n", ft_strlen(test3),
           strlen(test3) == ft_strlen(test3) ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("Test 4: \"%s\"\n", test4);
    printf("  strlen:    %zu\n", strlen(test4));
    printf("  ft_strlen: %zu %s\n", ft_strlen(test4),
           strlen(test4) == ft_strlen(test4) ? GREEN "✓" RESET : RED "✗" RESET);
}

void test_strcpy() {
    print_test_header("ft_strcpy TEST");
    
    char dst1[100], dst2[100];
    char *src1 = "Hello, World!";
    char *src2 = "";
    char *src3 = "42";
    
    printf("Test 1: \"%s\"\n", src1);
    strcpy(dst1, src1);
    ft_strcpy(dst2, src1);
    printf("  strcpy:    \"%s\"\n", dst1);
    printf("  ft_strcpy: \"%s\" %s\n", dst2,
           strcmp(dst1, dst2) == 0 ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("Test 2: \"\" (empty string)\n");
    strcpy(dst1, src2);
    ft_strcpy(dst2, src2);
    printf("  strcpy:    \"%s\"\n", dst1);
    printf("  ft_strcpy: \"%s\" %s\n", dst2,
           strcmp(dst1, dst2) == 0 ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("Test 3: \"%s\"\n", src3);
    strcpy(dst1, src3);
    ft_strcpy(dst2, src3);
    printf("  strcpy:    \"%s\"\n", dst1);
    printf("  ft_strcpy: \"%s\" %s\n", dst2,
           strcmp(dst1, dst2) == 0 ? GREEN "✓" RESET : RED "✗" RESET);
}

void test_strcmp() {
    print_test_header("ft_strcmp TEST");
    
    printf("Test 1: \"Hello\" vs \"Hello\"\n");
    printf("  strcmp:    %d\n", strcmp("Hello", "Hello"));
    printf("  ft_strcmp: %d %s\n", ft_strcmp("Hello", "Hello"),
           (strcmp("Hello", "Hello") == 0 && ft_strcmp("Hello", "Hello") == 0) ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("Test 2: \"Hello\" vs \"World\"\n");
    int r1 = strcmp("Hello", "World");
    int r2 = ft_strcmp("Hello", "World");
    printf("  strcmp:    %d\n", r1);
    printf("  ft_strcmp: %d %s\n", r2,
           ((r1 < 0 && r2 < 0) || (r1 > 0 && r2 > 0) || (r1 == 0 && r2 == 0)) ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("Test 3: \"abc\" vs \"abc\"\n");
    printf("  strcmp:    %d\n", strcmp("abc", "abc"));
    printf("  ft_strcmp: %d %s\n", ft_strcmp("abc", "abc"),
           strcmp("abc", "abc") == ft_strcmp("abc", "abc") ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("Test 4: \"\" vs \"\"\n");
    printf("  strcmp:    %d\n", strcmp("", ""));
    printf("  ft_strcmp: %d %s\n", ft_strcmp("", ""),
           strcmp("", "") == ft_strcmp("", "") ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("Test 5: \"abc\" vs \"abcd\"\n");
    r1 = strcmp("abc", "abcd");
    r2 = ft_strcmp("abc", "abcd");
    printf("  strcmp:    %d\n", r1);
    printf("  ft_strcmp: %d %s\n", r2,
           ((r1 < 0 && r2 < 0) || (r1 > 0 && r2 > 0) || (r1 == 0 && r2 == 0)) ? GREEN "✓" RESET : RED "✗" RESET);
}

void test_write() {
    print_test_header("ft_write TEST");
    
    printf("Test 1: Write to stdout\n");
    printf("  Expected: ");
    ssize_t r1 = write(1, "Hello", 5);
    printf("\n  ft_write: ");
    ssize_t r2 = ft_write(1, "Hello", 5);
    printf("\n  Return: write=%zd, ft_write=%zd %s\n", r1, r2,
           r1 == r2 ? GREEN "✓" RESET : RED "✗" RESET);
    
    printf("\nTest 2: Write with invalid fd (should fail)\n");
    errno = 0;
    r1 = write(-1, "test", 4);
    int err1 = errno;
    errno = 0;
    r2 = ft_write(-1, "test", 4);
    int err2 = errno;
    printf("  write:    return=%zd, errno=%d\n", r1, err1);
    printf("  ft_write: return=%zd, errno=%d %s\n", r2, err2,
           (r1 == -1 && r2 == -1 && err1 == err2) ? GREEN "✓" RESET : RED "✗" RESET);
}

void test_read() {
    print_test_header("ft_read TEST");
    
    printf("Test 1: Read from stdin (please type something and press Enter):\n");
    printf("  > ");
    fflush(stdout);
    
    char buf1[100], buf2[100];
    ssize_t r1 = read(0, buf1, 50);
    
    printf("  You typed: ");
    write(1, buf1, r1);
    
    printf("\nTest 2: Read with invalid fd (should fail)\n");
    errno = 0;
    r1 = read(-1, buf1, 10);
    int err1 = errno;
    errno = 0;
    ssize_t r2 = ft_read(-1, buf2, 10);
    int err2 = errno;
    printf("  read:    return=%zd, errno=%d\n", r1, err1);
    printf("  ft_read: return=%zd, errno=%d %s\n", r2, err2,
           (r1 == -1 && r2 == -1 && err1 == err2) ? GREEN "✓" RESET : RED "✗" RESET);
}

void test_strdup() {
    print_test_header("ft_strdup TEST");
    
    char *str1 = "Hello, World!";
    char *str2 = "";
    char *str3 = "42";
    
    printf("Test 1: \"%s\"\n", str1);
    char *dup1 = strdup(str1);
    char *dup2 = ft_strdup(str1);
    printf("  strdup:    \"%s\" (addr: %p)\n", dup1, (void*)dup1);
    printf("  ft_strdup: \"%s\" (addr: %p) %s\n", dup2, (void*)dup2,
           (dup2 != NULL && strcmp(dup1, dup2) == 0) ? GREEN "✓" RESET : RED "✗" RESET);
    if (dup2 == NULL) {
        printf("  " RED "ERROR: ft_strdup returned NULL!" RESET "\n");
    }
    if (dup1) free(dup1);
    if (dup2) free(dup2);
    
    printf("Test 2: \"\" (empty string)\n");
    dup1 = strdup(str2);
    dup2 = ft_strdup(str2);
    printf("  strdup:    \"%s\" (addr: %p)\n", dup1, (void*)dup1);
    printf("  ft_strdup: \"%s\" (addr: %p) %s\n", dup2, (void*)dup2,
           (dup2 != NULL && strcmp(dup1, dup2) == 0) ? GREEN "✓" RESET : RED "✗" RESET);
    if (dup2 == NULL) {
        printf("  " RED "ERROR: ft_strdup returned NULL!" RESET "\n");
    }
    if (dup1) free(dup1);
    if (dup2) free(dup2);
    
    printf("Test 3: \"%s\"\n", str3);
    dup1 = strdup(str3);
    dup2 = ft_strdup(str3);
    printf("  strdup:    \"%s\" (addr: %p)\n", dup1, (void*)dup1);
    printf("  ft_strdup: \"%s\" (addr: %p) %s\n", dup2, (void*)dup2,
           (dup2 != NULL && strcmp(dup1, dup2) == 0) ? GREEN "✓" RESET : RED "✗" RESET);
    if (dup2 == NULL) {
        printf("  " RED "ERROR: ft_strdup returned NULL!" RESET "\n");
    }
    if (dup1) free(dup1);
    if (dup2) free(dup2);
    
    // malloc 테스트 추가
    printf("\nTest 4: Malloc verification\n");
    char *test_str = "Testing malloc";
    printf("  Original: \"%s\" (addr: %p)\n", test_str, (void*)test_str);
    
    char *dup = ft_strdup(test_str);
    printf("  ft_strdup result: ");
    if (dup == NULL) {
        printf(RED "NULL - malloc failed!" RESET "\n");
    } else {
        printf("\"%s\" (addr: %p)\n", dup, (void*)dup);
        printf("  String match: %s\n", strcmp(test_str, dup) == 0 ? GREEN "✓" RESET : RED "✗" RESET);
        printf("  Different address: %s\n", (dup != test_str) ? GREEN "✓" RESET : RED "✗" RESET);
        
        // 메모리 수정 테스트
        dup[0] = 'X';
        printf("  After modification: \"%s\"\n", dup);
        printf("  Original unchanged: \"%s\" %s\n", test_str,
               (test_str[0] == 'T') ? GREEN "✓" RESET : RED "✗" RESET);
        free(dup);
    }
}

int main()
{
    printf(BLUE "╔════════════════════════════════════════╗\n");
    printf("║    ft_libasm Test Suite               ║\n");
    printf("╚════════════════════════════════════════╝" RESET "\n");
    
    test_strlen();
    test_strcpy();
    test_strcmp();
    test_write();
    test_read();
    test_strdup();
    
    printf("\n" BLUE "========== ALL TESTS COMPLETE ==========" RESET "\n\n");
    
    return 0;
}