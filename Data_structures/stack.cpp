#include <iostream>
#include <vector>

using namespace std;

struct Stack {
    int Capacity, Size, Top;
    int *A;

    Stack (){
        Capacity = 0;
        Size = 0;
        Top = -1;
    };
};

void stack_insert(Stack *S, int val) {
    if (S->Size == S->Capacity) {
        cerr << "Cant input anymore stack is full" << endl;
        return;
    }
    S->Size += 1;
    S->Top += 1;
    S->A[S->Top] = val;
}

bool stack_empty(Stack *S) {
    if (S->Top == -1)
        return true;
    return false;
}

void pop(Stack *S) {
    if (!stack_empty(S)) {
        S->Top -= 1;
    }
    else {
        cerr << "Empty Stack" << endl;
    }
}


int main() {
    Stack myS;
    myS.Capacity = 6;
    myS.A = new int[myS.Capacity];

    stack_insert(&myS, 9);
    stack_insert(&myS, 4);
    stack_insert(&myS, 1);
    stack_insert(&myS, 34);
    stack_insert(&myS, 2);
    stack_insert(&myS, 0);
    stack_insert(&myS, 0);
    pop(&myS);
    pop(&myS);
    pop(&myS);
    pop(&myS);
    pop(&myS);
    pop(&myS);
    pop(&myS);
    pop(&myS);
    pop(&myS);
    pop(&myS);

    delete my.A;

    return 0;
}
