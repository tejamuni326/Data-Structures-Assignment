#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int checkBalance(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == -1) return 0;
            pop();
        }
    }
    return (top == -1);
}

int main() {
    char exp[MAX];
    printf("Input: ");
    scanf("%s", exp);
    if (checkBalance(exp)) {
        printf("Output: Balanced Expression\n");
    } else {
        printf("Output: Unbalanced Expression\n");
    }
    return 0;
}
