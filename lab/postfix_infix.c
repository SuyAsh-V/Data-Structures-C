#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100][100];
int top = -1;

int isfull()
{
    if (top == 99)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char item[])
{
    if (!isfull())
    {
        top++;
        strcpy(stack[top], item);
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

void pop(char item[])
{
    if (!isempty())
    {
        strcpy(item, stack[top]);
        top--;
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

void post_infix(char postexp[], char infix[])
{
    int i;
    char x;
    char op1[100], op2[100], temp[100];

    for (i = 0; postexp[i] != '\0'; i++)
    {
        x = postexp[i];

        if (isalnum(x))
        {
            temp[0] = x;
            temp[1] = '\0';

            push(temp);
        }
        else
        {
            pop(op2);
            pop(op1);

            sprintf(temp, "(%s%c%s)", op1, x, op2);

            push(temp);
        }
    }

    pop(infix);
}

int main()
{
    char postexp[100];
    char infix[100];

    printf("Enter the postfix expression: ");
    scanf("%s", postexp);

    post_infix(postexp, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}