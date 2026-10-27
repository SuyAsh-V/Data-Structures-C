#include  <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX 50

typedef struct {
    char items[MAX][MAX];
    int top;
} Stack;

void push(Stack *s, char str[]) {
    if (s->top < MAX - 1) {
        s->top++;
        strcpy(s->items[s->top], str);
    }
}

void pop(Stack *s, char str[]) {
    if (s->top >= 0) {
        strcpy(str, s->items[s->top]);
        s->top--;
    }
}

void prefixToInfix(char prefix[], char infix[]) {
    Stack s;
    s.top = -1;

    int len = strlen(prefix);
    char op1[MAX], op2[MAX], temp[MAX];

    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            push(&s, operand);
        }
        else {
            pop(&s, op1);
            pop(&s, op2);

            snprintf(temp, sizeof(temp), "(%s%c%s)", op1, ch, op2);

            push(&s, temp);
        }
    }

    pop(&s, infix);
}

int main() {
    char prefix[MAX], infix[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    prefixToInfix(prefix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
