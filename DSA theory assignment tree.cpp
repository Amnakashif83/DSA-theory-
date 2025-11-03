#include <iostream>
using namespace std;

// Step 1:  structure of Node
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Step 2: Function to create a new node
Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Step 3: Traversal functions
void infix(Node* root) {
    if (root != NULL) {
        cout << "(";
        infix(root->left);
        cout << root->data;
        infix(root->right);
        cout << ")";
    }
}

void prefix(Node* root) {
    if (root != NULL) {
        cout << root->data;
        prefix(root->left);
        prefix(root->right);
    }
}

void postfix(Node* root) {
    if (root != NULL) {
        postfix(root->left);
        postfix(root->right);
        cout << root->data;
    }
}

int main() {
    cout << "=== Expression Tree Program==="<<endl;

    // Step 4: Take input from user
    char mainOp, leftOp, rightOp;
    char A, B, C, D;

    cout << "Enter main operator (like *, +, /): ";
    cin >> mainOp;

    cout << "Enter left side operator (like +): ";
    cin >> leftOp;
    cout << "Enter left operands (like A and B): ";
    cin >> A >> B;

    cout << "Enter right side operator (like -): ";
    cin >> rightOp;
    cout << "Enter right operands (like C and D): ";
    cin >> C >> D;

    Node* root = createNode(mainOp);

    
    root->left = createNode(leftOp);
    root->left->left = createNode(A);
    root->left->right = createNode(B);

    root->right = createNode(rightOp);
    root->right->left = createNode(C);
    root->right->right = createNode(D);
    
    int choice;
    do {
        cout << "--- Choose Traversal Type ---"<<endl;
        cout << "1. Infix Traversal"<<endl;
        cout << "2. Prefix Traversal"<<endl;
        cout << "3. Postfix Traversal"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Infix Expression: ";
                infix(root);
                cout << endl;
                break;
            case 2:
                cout << "Prefix Expression: ";
                prefix(root);
                cout << endl;
                break;
            case 3:
                cout << "Postfix Expression: ";
                postfix(root);
                cout << endl;
                break;
            case 4:
                cout << "Exiting program... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

