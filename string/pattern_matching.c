#include <stdio.h>
#define MAX_SIZE 100
int pattern_matching(char *m_str, char *p_str) {
    int i = 0, j = 0;
    int k = 0;
    int count = 0;
    while (m_str[i]) {
        k = i;
        j = 0;
        while (p_str[j]) {
            if (p_str[j] != m_str[i]) {
                break;
            }
            i++;
            j++;
        }
        if (!p_str[j]) {
            count++;
            k = i;
        }
        else {
            i++;
        }
    }
    return count;
}
int main() {
    char main_string[MAX_SIZE] = "abababa";
    char pattern_string[MAX_SIZE] = "aba";

    printf("%d\n", pattern_matching(main_string, pattern_string));

    return 0;
}