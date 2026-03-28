#include <stdio.h>
#include <string.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char item) {
    if (top < MAX - 1) {
        stack[++top] = item;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
}

int main() {
    char str[MAX];
    printf("Input: ");
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }

    printf("Output: %s\n", str);
    return 0;
}
