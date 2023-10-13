// Author: Sardinary
// Date: 2023-09-24

#ifndef OJ_TEST2_CPP_
#define OJ_TEST2_CPP_

#include <iostream>
#define MAX_SIZE 50

using namespace std;


typedef int ElemType;
typedef struct {
    ElemType data[MAX_SIZE];
    int top;
} Sqstack;

Sqstack* create() {
    Sqstack* stack = new Sqstack();
    stack->top = -1;
    return stack;
}

void destroy(Sqstack* stack) {
    delete stack;
}

void push(Sqstack* stack, ElemType value) {
    if (stack->top == MAX_SIZE - 1) {
        cout << "full" << endl;
        return;
    }

    stack->data[++stack->top] = value;
}

ElemType pop(Sqstack* stack) {
    if (stack->top == -1) {
        cout << "empty" << endl;
        return -1;
    }

    return stack->data[stack->top--];
}

bool isEmpty(Sqstack* stack) {
    return stack->top == -1;
}


void trans(int num, int system) {
    Sqstack* stack = create();

    while (num) {
        push(stack, num % system);
        num /= system;
    }

    while (!isEmpty(stack)) {
        int n = pop(stack);
        if (n > 10) {
            cout << (char) (n + 55);
        } else {
            cout << n;
        }
    }

    destroy(stack);
}

int main() {
    int num, system;
    cin >> num;
    cin >> system;
    trans(num, system);
}


#endif  // OJ_TEST2_CPP_