#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int getSizeDoubly(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Example usage
int main() {
    Node* head = new Node{1, NULL, NULL};
    Node* second = new Node{2, head, NULL};
    Node* third = new Node{3, second, NULL};
    head->next = second;
    second->next = third;

    cout << "Size of Doubly Linked List: " << getSizeDoubly(head);
    return 0;
}
