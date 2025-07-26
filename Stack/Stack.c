#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MAX 100
typedef int32_t StackType;

typedef struct {
    StackType arr[MAX];
    int top;
} Stack;

void CreateStack(Stack *s) {
    s->top = -1;
}

bool Check_Empty(Stack *s) {
    return s->top == -1;
}

bool Check_Full(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, StackType input) {
    if (Check_Full(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++s->top] = input;
    printf("Element %d has been pushed to the stack.\n", input);
}

StackType pop(Stack *s) {
    if (Check_Empty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    StackType removed = s->arr[s->top--];
    printf("Element %d has been removed.\n", removed);
    return removed;
}

StackType peek(Stack *s) {
    if (Check_Empty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    Stack stack;
    CreateStack(&stack);

    StackType Num;
    printf("Enter number of elements to push to the stack: ");
    scanf("%d", &Num);

    StackType Stack_Num;
    for (int i = 1; i <= Num; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &Stack_Num);
        push(&stack, Stack_Num);
        printf("Top element now: %d\n\n", peek(&stack));
    }

    printf("\nNow popping all elements:\n");
    while (!Check_Empty(&stack)) {
        printf("Top element: %d\n", peek(&stack));
        pop(&stack);
        printf("\n");
    }

    return 0;
}
