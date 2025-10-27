#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert at the beginning
void insertFirst(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (head != nullptr) head->prev = newNode;
    head = newNode;
}

// Function to insert at the end
void insertLast(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert after a specific node
void insertAfter(Node* head, int key, int value) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) temp = temp->next;
    if (temp != nullptr) {
        Node* newNode = new Node{value, temp, temp->next};
        if (temp->next != nullptr) temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// Function to delete a node with a given value
void deleteNode(Node*& head, int key) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp == head) head = temp->next;
    delete temp;
}

// Function to search for a value
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

// Print list
void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice, value, key;

    cout << "Doubly Linked List - Menu" << endl;
    while (true) {
        cout << "\n1. Insert First\n2. Insert Last\n3. Insert After Value\n4. Delete by Value\n5. Search\n6. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertFirst(head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertLast(head, value);
                break;
            case 3:
                cout << "Enter key after which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> value;
                insertAfter(head, key, value);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> key;
                cout << (search(head, key) ? "Found" : "Not Found") << endl;
                break;
            case 6:
                display(head);
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    }
}
