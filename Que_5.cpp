#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to check if linked list is circular
bool isCircular(Node* head) {
    if (head == NULL) return false;
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

// Helper to create and link nodes for test
int main() {
    // Example: 2 -> 4 -> 6 -> 7 -> 5 -> (link back to head)
    Node* n1 = new Node{2, NULL};
    Node* n2 = new Node{4, NULL};
    Node* n3 = new Node{6, NULL};
    Node* n4 = new Node{7, NULL};
    Node* n5 = new Node{5, NULL};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1; // Making the list circular

    if (isCircular(n1))
        cout << "True";
    else
        cout << "False";
    return 0;
}
