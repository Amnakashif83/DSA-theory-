#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void deleteAtBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
    cout << "Deleted from beginning.\n";
}

void deleteAtEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Deleted last node.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
    cout << "Deleted from end.\n";
}

void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (pos == 1) {
        deleteAtBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of range.\n";
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    delete temp;
    cout << "Deleted node at position " << pos << ".\n";
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    int choice, pos;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Delete from Beginning\n";
        cout << "2. Delete from End\n";
        cout << "3. Delete from Specific Position\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                deleteAtBeginning(head);
                break;
            case 2:
                deleteAtEnd(head);
                break;
            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
