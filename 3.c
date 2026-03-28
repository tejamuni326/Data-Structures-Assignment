#include <stdio.h>

void printNGE(int arr[], int n) {
    int stack[100];
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[i] > stack[top]) {
            printf("%d -> %d\n", stack[top--], arr[i]);
        }
        stack[++top] = arr[i];
    }

    while (top >= 0) {
        printf("%d -> -1\n", stack[top--]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
