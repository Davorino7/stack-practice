#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
public:
    Node* top;  

    Stack() {
        top = nullptr;
    }
    void push(int value) {
    Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if (top == nullptr) { 
            cout << "stack is empty.\n";
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    int peek() {
        if (top == nullptr) {
            cout << "stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top is: " << s.peek() << "\n";  

    cout << "Popped: " << s.pop() << "\n";     
    cout << "Popped: " << s.pop() << "\n";     

    cout << "Top is now: " << s.peek() << "\n"; 

    cout << "Is empty? " << (s.isEmpty() ? "yes" : "no") << "\n"; 

    return 0;
}