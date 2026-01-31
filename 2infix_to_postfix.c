#include <stdio.h>
#include <ctype.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
void push(char item) {
    stack[++top] = item;
}
char pop() {
    return stack[top--];
}
char peek() {
    return stack[top];
}
int precedence(char op) {
    if(op == '^') return 1;
    if (op == '+' || op == '-') return 2;
    if (op == '*' || op == '/') return 3;
    return 0;
}
void infixToPostfix(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (isalnum(ch)) {
            printf("%c", ch);
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(') {
                printf("%c", pop());
            }
            pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                printf("%c", pop());
            }
            push(ch);
        }
    }
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}
int main() {
    char expr[100];
    printf("Enter the expression:");
    scanf("%s",&expr);
    printf("Infix: %s\nPostfix: ", expr);
    infixToPostfix(expr);
    return 0;

}

