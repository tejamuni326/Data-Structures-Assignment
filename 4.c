#include <stdio.h>
#include <string.h>

char queue[10][50];
int front = -1, rear = -1;

void addDocument(char doc[]) {
    if (rear < 9) {
        if (front == -1) front = 0;
        strcpy(queue[++rear], doc);
        printf("Added: %s\n", doc);
    }
}

void printDocument() {
    if (front != -1) {
        printf("Printing: %s\n", queue[front++]);
        if (front > rear) front = rear = -1;
    } else {
        printf("Queue Empty\n");
    }
}

void displayQueue() {
    if (front == -1) return;
    printf("Pending: ");
    for (int i = front; i <= rear; i++) {
        printf("[%s] ", queue[i]);
    }
    printf("\n");
}

int main() {
    addDocument("Report.pdf");
    addDocument("Image.png");
    displayQueue();
    printDocument();
    displayQueue();
    return 0;
}
