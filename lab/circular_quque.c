#include<stdio.h>
#include<string.h>

struct job
{
    int job_id;
    char job_name[50];
};

int front = 0;
int rear = 0;

void enqueue(int max, struct job queue[max], struct job elem[1])
{
    if((rear+1) % max == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = (rear + 1) % max;
        printf("Enter the job_id: ");
        scanf("%d",&elem[0].job_id);
        printf("Enter the job_name: ");
        scanf("%s",elem[0].job_name);
        queue[rear] = elem[0];
    }
}

void dequeue(int max, struct job queue[max])
{
    if(front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        front = (front + 1) % max;
        printf("--------------------------------------------\n");
        printf("Deleted job_id: %d, job_name: %s\n", queue[front].job_id, queue[front].job_name);
        printf("--------------------------------------------\n");
    }
}

void display(int max, struct job queue[max])
{
    if(front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = (front + 1) % max;
        printf("--------------------------------------------\n");
        printf("Queue elements:\n");
        while(i != (rear + 1) % max)
        {
            printf("job_id: %d, job_name: %s\n", queue[i].job_id, queue[i].job_name);
            i = (i + 1) % max;
        }
        printf("--------------------------------------------\n");
    }
}

int main()
{
    int max;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &max);
    struct job queue[max];
    struct job elem[1];
    int choice;

    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue(max, queue, elem);
                display(max, queue);
                break;
            case 2:
                dequeue(max, queue);
                break;
            case 3:
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}