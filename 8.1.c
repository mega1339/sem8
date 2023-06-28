#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    // Проверяем, что длина строки t не превышает длину строки s
    if (len_t > len_s) {
        return 0;
    }

    // Сравниваем символы в обратном порядке
    while (len_t > 0) {
        if (s[len_s - 1] != t[len_t - 1]) {
            return 0;
        }
        len_s--;
        len_t--;
    }

    // Если символы t были сравнены до конца, t находится в конце s
    return 1;
}

int main() {
    char s[100];
    char t[100];

    printf("enter string s: ");
    scanf("%s", s);

    printf("enter string t: ");
    scanf("%s", t);

    if (strend(s, t)) {
        printf("%d\n", 1);
    } else {
        printf("%d\n", 0);
    }

    return 0;
}
