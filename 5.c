#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int items[SIZE], front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % SIZE == front) {
        printf("Full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = val;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Empty\n");
    } else {
        printf("Removed: %d\n", items[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }
}

void peek() {
    if (front != -1) printf("Front: %d\n", items[front]);
}

void display() {
    if (front == -1) return;
    int i = front;
    while (1) {
        printf("%d ", items[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int c, v;
    while (1) {
        printf("1.Push 2.Pop 3.Peek 4.Show 5.Exit: ");
        scanf("%d", &c);
        if (c == 1) { scanf("%d", &v); enqueue(v); }
        else if (c == 2) dequeue();
        else if (c == 3) peek();
        else if (c == 4) display();
        else break;
    }
    return 0;
}
