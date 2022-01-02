#include<iostream>
#include <map>
#include<vector>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *prev;
};

class linkedList {
public:
    linkedList() {
        start = nullptr;
    }

    void insert(int a) {
        Node *current = new Node();
        Node *l = new Node();
        l->val = a;


        if (start == nullptr) {
            start = l;
            end = start;
        }
        else {
            current = start;
            while(current->next != nullptr)
                current = current->next;

            current->next = l;
            l->prev = current;
            end = l;
        }
    }

    void print() {
        Node *current = new Node();
        current = start;

        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
    }

    void getsStart() {
        cout << start->val << endl;
    }

    void getEnd() {
        cout << end->val << endl;
    }

    void deleteAVal(int a) {
        Node *current = new Node();
        current = start;
        while (current != nullptr) {
            if (current->val == a) {
                Node *curPrev = current->prev;
                Node *curNext = current->next;

                curPrev->next = curNext;
                curPrev->prev = curPrev;
            }
            current = current->next;
        }

        print();
    }

private:
    Node *start;
    Node *end;
};

int main() {

    linkedList linkedMake;
    linkedMake.insert(3);
    linkedMake.insert(1);
    linkedMake.insert(6);
    linkedMake.insert(2);
    linkedMake.insert(90);
    linkedMake.insert(140);
    linkedMake.insert(73);
    linkedMake.insert(81);

    linkedMake.print();
    cout << endl;
    linkedMake.deleteAVal(90);

    return 0;
}
