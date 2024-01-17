#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
    element data;
    struct QueueNode *link;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} LinkedQueueType;

void init(LinkedQueueType *q, int i) {
    q[i].front = q[i].rear = NULL;
}

int is_empty(LinkedQueueType *q, int i) {
    return (q[i].front == NULL);
}

int is_full(LinkedQueueType *q) {
    return 0;
}

void enqueue(LinkedQueueType *q, element data, int i) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if (is_empty(q, i)) {
        q[i].front = temp;
        q[i].rear = temp;
    } else {
        q[i].rear->link = temp;
        q[i].rear = temp;
    }
}

element dequeue(LinkedQueueType *q, int i) {
    QueueNode *temp = q[i].front;
    element data;
    if (is_empty(q, i)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    } else {
        data = temp->data;
        q[i].front = q[i].front->link;
        if (q[i].front == NULL)
            q[i].rear = NULL;
        free(temp);
        return data;
    }
}

void print_queue(LinkedQueueType *q, int i) {
    QueueNode *p;
    printf("q 주소 : %d, ", &q[i]);
    printf("front 주소 : %d, ", q[i].front);
    printf("rear 주소 : %d \n", q[i].rear);
    printf("%d 큐 : \n", i);
    for (p = q[i].front; p != NULL; p = p->link)
        printf("p의 data 값 : %d, p의 data 주소 값 : %d, p의 link 값 : %d, p의 link 주소 값 : %d\n", p->data, &p->data, p->link, &p->link);
}

int main(void) {
    LinkedQueueType queue[3];

    int i = 0;
    while (i < 3) {
        if (i == 0) {
            init(queue, i);
            enqueue(queue, 1, i);
            print_queue(queue, i);
            printf("\n");
            enqueue(queue, 2, i);
            print_queue(queue, i);
            printf("\n");
            i++;
        }
        if (i == 1) {
            init(queue, i);
            enqueue(queue, 2, i);
            print_queue(queue, i);
            printf("\n");
            enqueue(queue, 3, i);
            print_queue(queue, i);
            printf("\n");
            enqueue(queue, 4, i);
            print_queue(queue, i);
            printf("\n");
            dequeue(queue, i);
            print_queue(queue, i);
            printf("\n");
            i++;
        }
        if (i == 2) {
            init(queue, i);
            enqueue(queue, 10, i);
            print_queue(queue, i);
            printf("\n");
            enqueue(queue, 20, i);
            print_queue(queue, i);
            printf("\n");
            enqueue(queue, 30, i);
            print_queue(queue, i);
            printf("\n");
            i++;
        }
    }
    return 0;
}

