#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    char items[MAX][MAX];
};

void push(struct Stack *s, char *str) {
    if (s->top < MAX - 1) {
        strcpy(s->items[++(s->top)], str);
    }
}

char *pop(struct Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    }
    return NULL;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void prefixToPostfix(char *prefix) {
    struct Stack s;
    s.top = -1;

    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        if (isspace(prefix[i])) {
            continue;
        }

        if (isOperator(prefix[i])) {
            char op1[MAX], op2[MAX], temp[MAX];
            strcpy(op1, pop(&s));
            strcpy(op2, pop(&s));

            strcpy(temp, op1);
            strcat(temp, op2);
            int len = strlen(temp);
            temp[len] = prefix[i];
            temp[len + 1] = '\0';

            push(&s, temp);
        } else {
            char operand[2] = {prefix[i], '\0'};
            push(&s, operand);
        }
    }

    printf("Postfix expression: %s\n", pop(&s));
}

int main() {
    char prefix[MAX];
    printf("Enter Prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix);

    return 0;
}