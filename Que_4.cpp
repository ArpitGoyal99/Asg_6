#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

// Function to check palindrome
bool isPalindrome(Node* head) {
    if (head == NULL) return true;

    // Move to the end to get the tail
    Node* tail = head;
    while (tail->next)
        tail = tail->next;

    // Check from both ends
    while (head != tail && head->prev != tail) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

// Helper to create and link nodes for test
int main() {
    // Example: L <-> E <-> V <-> E <-> L
    Node* n1 = new Node{'L', NULL, NULL};
    Node* n2 = new Node{'E', n1, NULL};
    Node* n3 = new Node{'V', n2, NULL};
    Node* n4 = new Node{'E', n3, NULL};
    Node* n5 = new Node{'L', n4, NULL};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    if (isPalindrome(n1))
        cout << "True";
    else
        cout << "False";
    return 0;
}
