#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to display the nodes of the circular linked list
void displayCircularList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << "."; // Repeat head value at the end
}

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Example: 20 -> 100 -> 40 -> 80 -> 60 forming a circle
    Node* head = createNode(20);
    Node* second = createNode(100);
    Node* third = createNode(40);
    Node* fourth = createNode(80);
    Node* fifth = createNode(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head; // Circular link

    displayCircularList(head);

    return 0;
}
