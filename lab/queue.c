#include<stdio.h>
#include<string.h>

struct job
{
    int job_id;
    char job_name[50];
};

int rear = -1;
int front = -1;

int isfull(int max)
{
    if(rear == max - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int max,struct job queue[max], struct job elem[1])
{
    if(isfull(max))
    {
        printf("Queue is full\n");
    }

    else
    {
        rear++;
        printf("Enter the job_id: ");
        scanf("%d",&elem[0].job_id);
        printf("Enter the job_name: ");
        scanf("%s",elem[0].job_name);
        queue[rear] = elem[0];
        printf("front = %d rear = %d\n", front, rear);
    }
}

int isempty()
{
    if(rear == front)
    {
        return 1;
    }
    return 0;
}

void delete(int max, struct job queue[max])
{
    if(isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct job elem[1];
        front++;
        elem[0] = queue[front];
        printf("--------------------------------------------\n");
        printf("Deleted job: Job ID: %d, Job Name: %s\n", elem[0].job_id, elem[0].job_name);
        printf("--------------------------------------------\n");
    }
}

void display(int max, struct job queue[max])
{
    if(isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("--------------------------------------------\n");
        for(int i = front + 1; i <= rear; i++)
        {
            printf("Job ID: %d, Job Name: %s\n", queue[i].job_id, queue[i].job_name);
        }
        printf("--------------------------------------------\n");
    }
}

int main()
{
    struct job elem[1];
    int max;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &max);

    struct job queue[max];

    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        int choice;
        printf("Enter the choice from 1 to 3: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue(max, queue, elem);
                display(max, queue);
                break;
            case 2:
                delete(max, queue);
                break;
            case 3:
                printf("Exiting the program\n");
                return 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

}