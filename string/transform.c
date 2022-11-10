#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 16

void transform(int x, int n, char dest[MAX_SIZE]) {
    int stack[MAX_SIZE] = { 0 };
    int top = -1;
    while (x > 0) {
        stack[++top] = x % n;
        x /= n;
    }
    int i = 0;
    int e = 0;
    char buf[8] = { 0 };
    while (top >= 0) {
        e = stack[top--];
        if (n != 16) {
            snprintf(buf, sizeof(buf), "%d", e);
        }
        else {
            snprintf(buf, sizeof(buf), "%c", e - 10 + 'a');
        }
        strcpy(dest + i, buf);
        i += strlen(buf);
    }
}

int main() {
    int x = (10 * 256) + (11 * 16) + (12 * 1);
    int n = 16;                                     // between 2 and 46
    char str[MAX_SIZE] = { 0 };

    transform(x, n, str);

    printf("%d(10) = %s(%d)\n", x, str, n);

    return 0;
}
