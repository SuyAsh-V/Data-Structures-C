#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 20

char stack[MAX];
int top = -1;

int isfull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(char item[])
{
    if (!isfull())
    {
        top++;
        stack[top] = item[0];
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

char pop()
{
    if (!isempty())
    {
        return stack[top--];
    }
    else
    {
        printf("Stack Underflow\n");
        return '\0';
    }
}

int priority(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void reverse(char str[])
{
    int len = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[MAX], char prefix[MAX])
{
    char ch;
    int i, k = 0;
    reverse(infix);
    for (i = 0; infix[i] != '\0'; i++){
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    for (i = 0; infix[i] != '\0'; i++){
        ch = infix[i];
        if (isalnum(ch)) {
            prefix[k++] = ch;}
        else if (ch == '('){
            push(&ch);}
        else if (ch == ')'){
            while (!isempty() && stack[top] != '('){
                prefix[k++] = pop();}
            if (!isempty() && stack[top] == '('){
                pop();}}
        else{
            if (ch == '^'){
                while (!isempty() &&
                       stack[top] != '(' &&
                       priority(stack[top]) >= priority(ch)){
                    prefix[k++] = pop();}}
            else{
                while (!isempty() &&
                       stack[top] != '(' &&
                       priority(stack[top]) > priority(ch))
                {
                    prefix[k++] = pop();}}
            push(&ch);}}

    while (!isempty()){
        prefix[k++] = pop();}

    prefix[k] = '\0';

    reverse(prefix);
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%19s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}