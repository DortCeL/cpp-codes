#include <iostream>
using namespace std;

typedef struct node {
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
} node;

node* root = NULL;

void insertFirst(int val) {
    node* newNode = new node(val);
    
    if (!root) {
        root = newNode;
        newNode->next = root; 
    } else {
        newNode->next = root->next;
        root->next = newNode;
    }
}

void insertLast(int val) {
    node* newNode = new node(val);
    
    if (!root) {
        root = newNode;
        newNode->next = root;
    } else {
        newNode->next = root->next;
        root->next = newNode;
        root = newNode;
    }
}

void deleteFirst() {
    if (!root) {
        cout << "Cannot delete" << endl;
        return;
    }

    if (root->next == root) {
        delete root;
        root = NULL;
    } else {
        node* temp = root->next;
        root->next = temp->next;
        delete temp;
    }
}


void deleteLast() {
    if (!root) {
        cout << "Cannot delete" << endl;
        return;
    }

    if (root->next == root) {
        delete root;
        root = NULL;
    } else {
        node* current = root->next;
        while (current->next != root) {
            current = current->next;
        }
        current->next = root->next;
        delete root;
        root = current;
    }
}

void insertAt(int position, int value) {
    if (position < 1) {
        cout << "Invalid position" << endl;
        return;
    }

    node* newNode = new node(value);
    
    if (!root) {
        root = newNode;
        newNode->next = root;  // Pointing back to itself for circularity
    } else {
        node* current = root->next;
        for (int i = 1; i < position - 1; ++i) {
            if (current == root)
                return;

            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteAt(int position) {
    if (!root || position < 1) {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 1) {
        deleteFirst();
    } else {
        node* current = root->next;
        for (int i = 1; i < position - 1; ++i) {
            if (current == root) {
                cout << "Invalid position. Cannot delete.\n";
                return;
            }
            current = current->next;
        }
        node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}


void printSize() {
    if (!root) {
        cout << "Size : 0" << endl;
        return;
    }

    int size = 0;
    node* current = root->next;

    do {
        size++;
        current = current->next;
    } while (current != root->next);

    cout << "Size : " << size << endl;
}


void printList() {
    if (!root) {
        cout << "List : " << endl;
        return;
    }

    node* current = root->next;

    cout << "List : ";

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != root->next);

    cout << endl;
}

int main() {
    insertFirst(3);
    insertFirst(2);
    insertFirst(1);

    insertLast(4);
    insertLast(5);

    printList();

    deleteFirst();
    printList();

    deleteLast();
    printList();

    insertAt(2, 6);
    printList();

    deleteAt(2);
    printList();

    printSize();

}