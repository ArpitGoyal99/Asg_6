#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int getSizeCircular(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Example usage
int main() {
    Node* head = new Node{1, NULL};
    Node* second = new Node{2, NULL};
    Node* third = new Node{3, NULL};
    head->next = second;
    second->next = third;
    third->next = head; // Makes it circular

    cout << "Size of Circular Linked List: " << getSizeCircular(head);
    return 0;
}
