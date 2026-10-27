#include <stdio.h>
#include <stdlib.h>

struct node
{
    int RegNo;
    char Name[50];
    struct node* next;
};

void create(struct node* H);
void display(struct node* H);
int len(struct node* H);
void insertbypos(struct node* H);
void delbypos(struct node* H);
void reverse(struct node* H);
void sort(struct node* H);

int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;

    int ch;
    while(1)
    {
        printf("---------------------------------------\n");
        printf("1. Creation of linked list\n");
        printf("2. Display the list\n");
        printf("3. Length of the list\n");
        printf("4. Addition of element by position\n");
        printf("5. Delete element by pos\n");
        printf("6. Reverse the list\n");
        printf("7. Sort the list\n");
        printf("8. Exit\n");
        printf("---------------------------------------\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        printf("---------------------------------------\n");
        
        switch(ch)
        {
            case 1:
                create(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Length of the list: %d\n", len(head));
                break;
            case 4:
                insertbypos(head);
                break;
            case 5:
                delbypos(head);
                break;
            case 6:
                reverse(head);
                display(head);
                break;
            case 7:
                sort(head);
                display(head);
                break;
            case 8:
                return 0;
            default:
                printf("Enter valid choice\n");
                break;
        }
    }

    return 0;
}

void create(struct node* H)
{
    struct node* temp = H;
    char choice = 'y';

    while(choice == 'y' || choice == 'Y')
    {
        struct node* curr = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter the RegNo: ");
        scanf("%d", &curr->RegNo);
        
        printf("Enter the Name: ");
        scanf("%s", curr->Name);
        
        curr->next = NULL;
        temp->next = curr;
        temp = curr;

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    }
}

void display(struct node* H)
{
    if (H->next == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node* curr = H->next;
        printf("\n%-20s %-10s %-20s %-20s\n",
               "Address", "RegNo", "Name", "Next Address");

        while (curr != NULL)
        {
            printf("%-20p %-10d %-20s %-20p\n",
                   (void *)curr,
                   curr->RegNo,
                   curr->Name,
                   (void *)curr->next);

            curr = curr->next;
        }
    }
}

int len(struct node* H)
{
    int i = 0;
    struct node* curr = H->next;
    while(curr != NULL)
    {
        i++;
        curr = curr->next;
    }
    return i;
}

void insertbypos(struct node* H)
{
    int i = 1;
    int pos;
    struct node* curr = H;
    int k = len(H);
    
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    
    if(pos > k + 1 || pos <= 0)
    {
        printf("Data can not be inserted\n");
    }
    else
    {
        struct node* nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the RegNo: ");
        scanf("%d", &nnode->RegNo);
        
        printf("Enter the name: ");
        scanf("%s", nnode->Name);
        
        while(curr != NULL && i < pos)
        {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
    }
    display(H);
}

void delbypos(struct node* H)
{
    struct node* prev = H;
    int ctr = 1;
    struct node* curr = H->next;
    int pos;
    
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    
    int k = len(H);
    if(k < pos || pos <= 0)
    {
        printf("Data can not be deleted\n");
    }
    else
    {
        while(ctr < pos && curr != NULL)
        {
            ctr++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
    }
    display(H);
}

void reverse(struct node* H)
{
    struct node* prev = NULL;
    struct node* curr = H->next;
    
    while(curr != NULL)
    {
        struct node* future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    H->next = prev;
}

void sort(struct node* H)
{
    int l = len(H);
    for(int i = 1; i < l; i++)
    {
        struct node* prev = H;
        struct node* curr = H->next;
        for(int j = 0; j < l - i; j++)
        {
            struct node* temp = curr->next;
            if(curr->RegNo > temp->RegNo)
            {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}