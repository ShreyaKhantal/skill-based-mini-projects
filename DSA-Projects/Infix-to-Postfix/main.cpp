#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct node{
    char data;
    struct node *next;
} *tos = NULL, *p;
void push(int c){
    struct node *p = new struct node;
    p->data = c;
    p->next = tos;
    tos = p;
}
int pop(){
    if (tos == NULL){
        cout << "Deletion not possible" << endl;
        return '0';
    }else{
        p = tos;
        tos = tos->next;
    }
    return p->data;
}
bool isempty(){
    return tos == NULL;
}
int top(){
    if (tos == NULL){
        return -1;
    }
    return tos->data;
}

void clearStack() {
    while (!isempty()) {
        pop();
    }
}

bool isbalanced(char a[]){
    clearStack();
    int len = strlen(a);
    int top;

    for (int i = 0; i < len; i++){
        if (a[i] == '[' || a[i] == '{' || a[i] == '('){
            push(a[i]);
        }
        else if (a[i] == ']' || a[i] == '}' || a[i] == ')'){
            if (tos == NULL){
                return false;
            }else{
                top = pop();
                if ((a[i] == ']' && top != '[') ||
                    (a[i] == '}' && top != '{') ||
                    (a[i] == ')' && top != '('))
                {
                    return false;
                }
            }
        }
    }
    if (tos == NULL){
        return true;
    }else{
        return false;
    }
}
int priority(char x){
    if (x == '^')
        return 3;
    else if (x == '/' || x == '*')
        return 2;
    else if (x == '-' || x == '+')
        return 1;
    else
        return 0;
}
string infixtopostfix(char input[]){
    clearStack();
    string ans;
    int len = strlen(input);

    for (int i = 0; i < len; i++){
        char x = input[i];

        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')){
            ans += x;
        }
        else if (x == '(' || x == '{' || x == '['){
            push(x);
        }
        else if (x == ')'){
            while (tos != NULL && top() != '('){
                ans += top();
                pop();
            }
            pop();
        }else if (x == '}'){
            while (tos != NULL && top() != '{'){
                ans += top();
                pop();
            }
            pop();
        }else if (x == ']'){
            while (tos != NULL && top() != '['){
                ans += top();
                pop();
            }
            pop();
        }else if (priority(x) > 0){
            if (isempty()){
                push(x);
            }else if (priority(top()) < priority(x)){
                push(x);
            }else{
                char t;
                while (priority(top()) >= priority(x)){
                    t = top();
                    ans += t;
                    pop();
                }
                push(x);
            }
        }
    }
    char t;
    while (!isempty()){
        t = top();
        ans += t;
        pop();
    }
    cout << "Postfix is: " << ans << endl;
    return ans;
}
int evaluatepostfix(string input){
    clearStack();
    int len = input.length();
    for (int i = 0; i < len; i++) {
        char x = input[i];
        if (isdigit(x)) {
            push(x - '0');
        } else {
            int a = pop();
            int b = pop();
            switch (x)
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(a * b);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push(ceil(pow(b, a)));
                break;
            default:
                cout << "Invalid expression" << endl;
                return 0;
            }
        }
    }
    return pop();
}
int main(){
    char input[50];
    char ch;
    do{
        cout << "\nEnter The Expression: ";
        cin >> input;

        int len = strlen(input);
        bool a=false;
        bool b=false;

        for (int i = 0; i < len; i++){
            char x = input[i];
            if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')){
                a = true;
            }if (x >= '0' && x <= '9'){
                b = true;
            }
        }

        if (!isbalanced(input)){
            cout << "Expression is invalid" << endl;
        }else{
            if (b && !a){
                cout << "Result: " << evaluatepostfix(infixtopostfix(input)) << endl;
            }else if (a) {
                infixtopostfix(input);
            }else{
                cout << "No data available to proceed" << endl;
            }
        }
        cout << "Another expression(y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}