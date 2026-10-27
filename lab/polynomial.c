# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<math.h>

struct polynomial{
    int coeff;
    int exp;
    struct polynomial* next;
};

void poly_create(struct polynomial* H)
{
    struct polynomial* temp = H;
    temp->next = H;
    char choice = 'y';
    while(choice == 'y' || choice == 'Y')
    {
        struct polynomial* curr = (struct polynomial*)malloc(sizeof(struct polynomial));

        printf("Enter the coefficient:");
        scanf("%d",&curr->coeff);
        printf("Enter the exponent:");
        scanf("%d",&curr->exp);
        curr->next = H;
        temp->next = curr;
        temp = curr;
        printf("Do you want to add another node? (y/n):");
        scanf(" %c",&choice);
    }
}

void display_poly(struct polynomial *H)
{
    struct polynomial *curr = H->next;

    if (curr == H){
        printf("List is empty\n");
    }
    else
    {
        printf("Polynomial: ");
        while (curr != H){
            if (curr->coeff > 0 && curr != H->next)
                printf("+");
            if (curr->exp == 0){
                printf("%d", curr->coeff);}
            else if (curr->exp == 1){
                printf("%dx", curr->coeff);}
            else{
                printf("%dx^%d", curr->coeff, curr->exp);}
            curr = curr->next;
        }
        printf("\n");}}

void poly_add(struct polynomial* H1, struct polynomial* H2)
{
    struct polynomial* H3 = (struct polynomial*)malloc(sizeof(struct polynomial));
    H3->exp = -1;
    H3->next = H3;

    struct polynomial* t3 = H3;
    struct polynomial* t1 = H1->next;
    struct polynomial* t2 = H2->next;

    while(t1 != H1 && t2 != H2)
    {
        struct polynomial* temp;

        if(t1->exp == t2->exp)
        {
            int sum = t1->coeff + t2->coeff;

            if(sum != 0)
            {
                temp = (struct polynomial*)malloc(sizeof(struct polynomial));
                temp->coeff = sum;
                temp->exp = t1->exp;
                temp->next = H3;

                t3->next = temp;
                t3 = temp;
            }

            t1 = t1->next;
            t2 = t2->next;
        }
        else if(t1->exp > t2->exp)
        {
            temp = (struct polynomial*)malloc(sizeof(struct polynomial));
            temp->coeff = t1->coeff;
            temp->exp = t1->exp;
            temp->next = H3;

            t3->next = temp;
            t3 = temp;

            t1 = t1->next;
        }
        else
        {
            temp = (struct polynomial*)malloc(sizeof(struct polynomial));
            temp->coeff = t2->coeff;
            temp->exp = t2->exp;
            temp->next = H3;

            t3->next = temp;
            t3 = temp;

            t2 = t2->next;
        }
    }

    while(t1 != H1)
    {
        struct polynomial* temp = (struct polynomial*)malloc(sizeof(struct polynomial));

        temp->coeff = t1->coeff;
        temp->exp = t1->exp;
        temp->next = H3;

        t3->next = temp;
        t3 = temp;

        t1 = t1->next;
    }

    while(t2 != H2)
    {
        struct polynomial* temp = (struct polynomial*)malloc(sizeof(struct polynomial));

        temp->coeff = t2->coeff;
        temp->exp = t2->exp;
        temp->next = H3;

        t3->next = temp;
        t3 = temp;

        t2 = t2->next;
    }

    display_poly(H3);
}
int poly_eval(struct polynomial* H, int x)
{
    struct polynomial* curr = H->next;
    int sum = 0;
    while(curr != H)
    {
        sum+= curr->coeff * pow(x,curr->exp);
        curr = curr->next;
    }
    return sum;
}

int main()
{
    int x; 
    struct polynomial* H1 = (struct polynomial*)malloc(sizeof(struct polynomial));
    H1->exp = -1;
    H1->next = H1;
    struct polynomial* H2 = (struct polynomial*)malloc(sizeof(struct polynomial));
    H2->exp = -1;
    H2->next = H2;
    
    int choice;
    while(1)
    {
        printf("-----------------------------\n");
        printf("1. Create polynomial\n");
        printf("2. Display polynomial\n");
        printf("3. Add polynomials\n");
        printf("4. Evaluate polynomial\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("-----------------------------\n");
        switch(choice)
        {
            case 1:
                poly_create(H1);
                break;
            case 2:
                display_poly(H1);
                break;
            case 3:
                printf("Enter the second polynomial:\n");
                poly_create(H2);
                poly_add(H1,H2);
                break;
            case 4:
                printf("Enter the value of x:");
                scanf("%d",&x);
                int result = poly_eval(H1,x);
                printf("Result: %d\n",result);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}