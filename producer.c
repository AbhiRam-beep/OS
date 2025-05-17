#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 5

int mutex = 1, empty = BUFFSIZE, full = 0, x = 0;

void wait(int *s) {
    --(*s);
}

void signal(int *s) {
    ++(*s);
}

void producer() {
    if (empty == 0) {
        printf("Buffer is full.\n");
        return;
    }

    wait(&empty);
    wait(&mutex);

    x++;
    printf("Producer has produced item %d\n", x);

    signal(&mutex);
    signal(&full);
}

void consumer() {
    if (full == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    wait(&full);
    wait(&mutex);

    printf("Consumer has consumed item %d\n", x);
    x--;

    signal(&mutex);
    signal(&empty);
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: producer(); break;
            case 2: consumer(); break;
            case 3: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
