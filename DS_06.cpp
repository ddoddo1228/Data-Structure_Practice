#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUES 10  
#define IS_FULL(ptr) (!(ptr))
#define IS_EMPTY(ptr) (!(ptr))

typedef struct 
{
    int key;
} element;


typedef struct queue *queue_pointer;
typedef struct queue
{

    element item;
    queue_pointer link;

} queue;

queue_pointer front[MAX_QUEUES], rear[MAX_QUEUES];  

void addq(queue_pointer *front, queue_pointer *rear, element item);
element deleteq(queue_pointer *front);

int main(void)

{
    element In_Temp, Out_Temp;
    int Cnt, i;

    for(Cnt=0; Cnt<MAX_QUEUES; Cnt++)
    {
    	
        for(i=0; i<5; i++)
        {
            In_Temp.key = i;
            addq(&front[Cnt], &rear[Cnt], In_Temp);
        }
        
    }
	
    for(Cnt=0; Cnt<MAX_QUEUES; Cnt++)
    {
        for(i=0; i<5; i++)
        {
            Out_Temp = deleteq(&front[Cnt]);
            printf("[Queue %d] %d\n\n", Cnt, Out_Temp.key);
        }
    }

	
    return 0;

}

void addq(queue_pointer *front, queue_pointer *rear, element item)

{

    queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
    if(IS_FULL(temp))
    {
        fprintf(stderr, "메모리 공간이 부족합니다.\n");
        exit(1);
    }
    temp->item = item;
    temp->link = NULL;
    if(*front) (*rear)->link = temp;
    else *front = temp;
    *rear = temp;
    printf("Queue의 주소 = %d, 값=%d\n\n", &temp->item, temp->item);
}

element deleteq(queue_pointer *front)
{ 

    queue_pointer temp = *front;
    element item;
    if(IS_EMPTY(temp))
    {
        fprintf(stderr, "저장된 데이터가 없습니다.\n");
        exit(1);
    }

    item = temp->item;
    *front = temp->link;
    free(temp);
    return item;
    

}
