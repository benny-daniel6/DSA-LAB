#include <Stdio.h>
#include <math.h>
#include <ctype.h>
#include <String.h>

int compute(char symbol, int op1, int op2) {
    switch(symbol) {
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '/': return op1/op2;
        case '*': return op1*op2;
        case '%': return op1%op2;
        case '^': return pow(op1,op2);
    }
}

void main() {
    char expression[20];
    int op1, op2, i, top = -1, result, final;
    char symbol;
    int stack[20];
    printf("Enter postfix expression: \n");
    scanf("%s", expression);
    for(i=0; i<strlen(expression); i++) {
        symbol = expression[i];
        if(isdigit(symbol))
            stack[++top] = symbol - '0';
        else {
            op2 = stack[top--];
            op1 = stack[top--];
            result= compute(symbol, op1, op2);
            stack[++top] = result;            
        }
    }
    final = stack[top--];
    printf("Value of expression (%s) : %d\n",expression,final);
}