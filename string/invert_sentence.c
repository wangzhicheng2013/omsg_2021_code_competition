#include <stdio.h>

#define MAX_SIZE 100

void invert_word(char *str, int start, int end) {
    char tmp = 0;
    while (start < end) {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        --end;
    }
}
int is_letter(char c) {
    return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}
void invert_sentence(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (0 == is_letter(str[i])) {
            invert_word(str, j, i - 1);
            j = i + 1;
        }
        i++;
    }
    if (j > 0) {
        invert_word(str, j, i - 1);
    }
    invert_word(str, 0, i - 1);
}

int main() {
    char str[MAX_SIZE] = "light and shadow";
    invert_sentence(str);
    printf("%s\n", str);

    return 0;
}