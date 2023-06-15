#include <iostream>

struct Node {
    Node() {
        value = INT_MIN;
        prev = nullptr;
        next = nullptr;
    }

    int value;
    Node *prev;
    Node *next;
};

class LinkedList {
public:
    explicit LinkedList () : root(new Node), end(root), size(0) {}

    explicit LinkedList (const int val) {
        root = new Node;
        root->value = val;
        root->next = nullptr;
        root->prev = nullptr;
        end = root;
        size += 1;
    }

     void addValue (const int val) {
        Node *current = root;

        if (root->value == INT_MIN) {
            root->value = val;
            size += 1;
        }
        else {
            Node *newNode = new Node;
            newNode->value = val;

            while (current->next != nullptr)
                current = current->next;

            newNode->prev = current;
            current->next = newNode;
            size += 1;
        }
    }

    LinkedList operator+ (const LinkedList& other) const {
        LinkedList temp;

        if (root->value == INT_MIN && other.root->value == INT_MIN)
            return temp;

        Node *current = root;
        Node *currentOther = other.root;

        while (current != nullptr && currentOther != nullptr) {
            int sum = current->value + currentOther->value;
            temp.addValue(sum);
            current = current->next;
            currentOther = currentOther->next;
        }

        return temp;
    }

    LinkedList operator- (const LinkedList& other) const {
        LinkedList temp;

        if (root->value == INT_MIN && other.root->value == INT_MIN)
            return temp;

        Node *current = root;
        Node *currentOther = other.root;

        while (current != nullptr && currentOther != nullptr) {
            int sum = current->value - currentOther->value;
            temp.addValue(sum);
            current = current->next;
            currentOther = currentOther->next;
        }

        return temp;
    }

    bool operator== (const LinkedList& other) const {
        Node *current = root;
        Node *currentOther = other.root;

        while (current != nullptr && currentOther != nullptr) {
            if (current->value != currentOther->value)
                return false;

            current = current->next;
            currentOther = currentOther->next;

        }

        return true;
    }

    void printLinkedList () {
        Node *current = root;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }


    ~LinkedList() {
        Node *current = root;
        while (current->next != nullptr) {
            Node *temp = current->next;
            delete current;
            current = temp;
        }
    }
private:
    Node *root;
    Node *end;
    int size;
};

int main() {

    std::cout << "Here is the first linked list: ";
    LinkedList one(1);
    one.addValue(2);
    one.addValue(3);
    one.addValue(4);
    one.printLinkedList();

    std::cout << "Here is the second linked list: ";
    LinkedList two(9);
    two.addValue(8);
    two.addValue(7);
    two.addValue(6);
    two.printLinkedList();

    std::cout << "Here is the third linked list (custom operator +): ";
    LinkedList three = one + two;
    three.printLinkedList();

    std::cout << "Here is the fourth linked list (custom operator -): ";
    LinkedList four = three - two;
    four.printLinkedList();

    std::cout << "Checking operator ==: " << ((one == four) ? "True" : "False");

    return 0;
}

