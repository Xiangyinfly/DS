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
    return (c >= '0' && c <= '9');
}

int operatorPriority(char c) {
    if (c == '+' || c == '-') {
        return 0;
    }
    if (c == '*' || c == '/') {
        return 1;
    }
    return -1; 
}

string toRPN(string s) {
    string rpn = "";
    Sqstack* stack = create();

    for (int i = 0; i < s.length(); i++) {
        if (isNum(s[i])) {
            rpn += s[i];
            if (!isNum(s[i + 1])) {
                rpn += '#';
            }
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            char c;
            while (!isEmpty(stack) && operatorPriority(c = stack->data[stack->top]) >= operatorPriority(s[i])) {
                rpn += c;
                pop(stack); 
            }
            push(stack, s[i]);
        } else if (s[i] == '(') {
            push(stack, s[i]);
        } else if (s[i] == ')') {
            while (!isEmpty(stack) && stack->data[stack->top] != '(') {
                rpn += stack->data[stack->top];
                pop(stack); 
            }
            if (!isEmpty(stack) && stack->data[stack->top] == '(') {
                pop(stack); 
            }
        }
    }

    while (!isEmpty(stack)) {
        rpn += stack->data[stack->top];
        pop(stack);
    }

    destroy(stack);
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
    int result = pop(num);
    destroy(num);
    return result;
}

void calculate(string s) {
    cout << getValue(toRPN(s)) << endl;
}

int main() {
    string expression = "((21+4)/5-3)";
    calculate(expression);
    return 0;
}

