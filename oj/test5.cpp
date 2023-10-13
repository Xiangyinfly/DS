// Author: Sardinary
// Date: 2023-09-25

#ifndef OJ_TEST5_CPP_
#define OJ_TEST5_CPP_

#include <iostream>
#include <string>
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

bool isNum(char c) {
    if ((int)c >= 48 && (int)c <= 57) {
        return true;
    }
    return false;
}

int operatorPriority(char c) {
    if (c == '+' || c == '-') {
        return 0;
    }
    if (c == '*' || c == '/') {
        return 1;
    }
}
//转rpn
string toRPN(string s) {
    string rpn = "";
    Sqstack* stack = create();
    
    for (int i = 0; i < s.length(); i++) {

        if (isNum(s[i])) {
            rpn += s[i];
            if (!isNum(s[i + 1])) {
                rpn += "#";
            }
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            if ((!isEmpty(stack) && operatorPriority(s[i]) >= operatorPriority(stack->data[stack->top])) || isEmpty(stack)) {
                push(stack, s[i]);
            } else {
                char c;
                while (!isEmpty(stack) && operatorPriority(c = pop(stack)) >= operatorPriority(s[i])) {
                    rpn += c;
                }
                push(stack, s[i]);
            }
        } else if (s[i] == '(') {
            push(stack, s[i]);
        } else if (s[i] == ')') {
            while (stack->data[stack->top] != '(') {
                rpn += pop(stack);
            }
            pop(stack);
        }

    }
    
    while (!isEmpty(stack)) {
        rpn += pop(stack);
    }

    return rpn;
}

int getValue(string rpn) {
    Sqstack* num = create();
    for (int i = 0; i < rpn.length(); i++) {
        if (isNum(rpn[i])) {
            string n = "";
            n += rpn[i];
            while (isNum(rpn[i + 1])) {
                n += rpn[++i];
            }
            push(num, stoi(n));
        } else if (rpn[i] == '#') {
            continue;
        } else {
            int operand2 = pop(num);
            int operand1 = pop(num);
            switch (rpn[i]) {
            case '+':
                push(num, operand1 + operand2);
                break;
            case '-':
                push(num, operand1 - operand2);
                break;
            case '*':
                push(num, operand1 * operand2);
                break;
            case '/':
                if (operand2 != 0) {
                    push(num, operand1 / operand2);
                }
                break;
            }
        }
    }
    return pop(num);
}

void calculate(string s) {
    cout << getValue(toRPN(s)) << endl;
}

int main() {
    calculate("((21+4)/5-3)");

}


#endif  // OJ_TEST5_CPP_