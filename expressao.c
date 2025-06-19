#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "expressao.h"

#define MAX 512

typedef struct {
    float items[MAX];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, float v) { s->items[++s->top] = v; }
float pop(Stack *s) { return s->items[s->top--]; }
float peek(Stack *s) { return s->items[s->top]; }

int isOperator(char *token) {
    return !strcmp(token, "+") || !strcmp(token, "-") || !strcmp(token, "*") ||
           !strcmp(token, "/") || !strcmp(token, "%") || !strcmp(token, "^") ||
           !strcmp(token, "log") || !strcmp(token, "sen") || !strcmp(token, "cos") ||
           !strcmp(token, "tg") || !strcmp(token, "raiz");
}

float applyOperator(char *op, float a, float b) {
    if (!strcmp(op, "+")) return a + b;
    if (!strcmp(op, "-")) return a - b;
    if (!strcmp(op, "*")) return a * b;
    if (!strcmp(op, "/")) return a / b;
    if (!strcmp(op, "%")) return fmod(a, b);
    if (!strcmp(op, "^")) return pow(a, b);
    return 0;
}

float applyFunction(char *func, float val) {
    if (!strcmp(func, "log")) return log10(val);
    if (!strcmp(func, "sen")) return sin(val * M_PI / 180);
    if (!strcmp(func, "cos")) return cos(val * M_PI / 180);
    if (!strcmp(func, "tg"))  return tan(val * M_PI / 180);
    if (!strcmp(func, "raiz")) return sqrt(val);
    return 0;
}

float getValorPosFixa(char *expr) {
    Stack s;
    init(&s);
    char *token = strtok(expr, " ");
    while (token) {
        if (isOperator(token)) {
            if (!strcmp(token, "log") || !strcmp(token, "sen") ||
                !strcmp(token, "cos") || !strcmp(token, "tg") || !strcmp(token, "raiz")) {
                float val = pop(&s);
                push(&s, applyFunction(token, val));
            } else {
                float b = pop(&s), a = pop(&s);
                push(&s, applyOperator(token, a, b));
            }
        } else {
            push(&s, atof(token));
        }
        token = strtok(NULL, " ");
    }
    return pop(&s);
}

char *getFormaPosFixa(char *infix) {
    // Implementação de shunting-yard pode ser adicionada aqui
    // Esta função deve converter infix para postfix
    return ""; // Placeholder
}

char *getFormaInFixa(char *postfix) {
    // Conversão de pós-fixa para infixa
    return ""; // Placeholder
}

float getValorInFixa(char *infix) {
    static char buffer[512];
    strcpy(buffer, getFormaPosFixa(infix));
    return getValorPosFixa(buffer);
}