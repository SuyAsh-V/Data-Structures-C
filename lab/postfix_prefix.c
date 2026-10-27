#include <stdio.h>
#include <ctype.h>
#include<string.h>
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

void postfixToPrefix(char *postfix) {
    struct Stack s;
    s.top = -1;
    
    int length = strlen(postfix);

    for (int i = 0; i < length; i++) {
        if (isspace(postfix[i])) {
            continue;
        }

        if (isOperator(postfix[i])) {
            char op2[MAX], op1[MAX], temp[MAX];
            strcpy(op2, pop(&s));
            strcpy(op1, pop(&s));

            temp[0] = postfix[i];
            temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);

            push(&s, temp);
        } else {
            char operand[2] = {postfix[i], '\0'};
            push(&s, operand);
        }
    }

    printf("Prefix expression: %s\n", pop(&s));
}

int main() {
    char postfix[MAX];
    printf("Enter Postfix expression: ");
    scanf("%s", postfix);

    postfixToPrefix(postfix);

    return 0;
}
