#include <bits/stdc++.h>
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

void listAppend(int val) {
    node* newNode = new node(val);

    node* temp = root;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    cout << val << " inserted at the end" << endl;
}

void listPrepend(int val) {
    node* newNode = new node(val);
    newNode->next = root;
    root = newNode;
    cout << val << " inserted at the beginning" << endl;
}

void insertAt(int target, int val) {
    node* newNode = new node(val);
    node* temp = root;
    int tracker = 1;
    while (temp->next != NULL) {
        if (tracker == target)
            break;
        temp = temp->next;
        tracker++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << val << " inserted at " << target << endl;
}


int listSize() {
    int tracker = 1;
    node* temp = root;
    if (temp == NULL) return 0;
    while (temp->next != NULL) {
        temp = temp->next;
        tracker++;
    }
    return tracker;
}



void deleteAt(int target) {

    int size = listSize(root);
    node* temp = root;
    
    if (target == 1) {
        root = root->next;
        cout << "Deleted Node at " << target << endl;
        return;
    }


    else if (target == size) {
        while (temp->next->next!= NULL) temp = temp->next;
        temp->next = NULL;
        cout << "Deleted Node at " << target << endl;
        return;
    }

    int tracker = 2;
    while (temp->next != NULL) {
        if (tracker == target)
            break;
        temp = temp->next;
        tracker++;
    }
    if (temp->next->next != NULL) {
        temp->next = temp->next->next;
    }
    cout << "Deleted Node at " << target << endl;
}

void listFind(int target){ 
    node* temp = root;
    int tracker = 1;
    while (temp != NULL and temp->data != target) {
        temp = temp->next;
        tracker++;
    }

    if (temp == NULL) {
        cout << target << " not found";
    } 
    else {
        cout << target << " found at " << tracker << endl;
    }
}

node* lastNode() {
    node* temp = root;
    while (temp->next != NULL) temp = temp->next;
    return temp;
}

void printNode(node* nd) {
    if (nd != NULL)
        cout << nd->data << endl;
}

node* previousOfLastNode() {
    node* temp = root;
    if (temp->next == NULL) return NULL;
    while (temp->next->next != NULL)
        temp = temp->next;
    return temp;
}

void deleteLast() {
    if (root->next == NULL) {
        root = root->next;
        return;
    } 
    node* temp = root;
    while (temp->next->next!= NULL) temp = temp->next;

    temp->next = NULL;
    cout << "Last Node Deleted!" << endl;
}

void deleteFirst() {
    root = root->next;
    cout << "First Node Deleted!" << endl;
}

void printList() {
    if (root == NULL) {
        cout << "List : " << endl;
        return;
    }
    cout << endl;
    cout << "List : ";
    node* temp = root;
    while (temp->next != NULL) {
        cout << temp->data << " ==> ";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl << endl;
}



int main (void) {
    system("cls");

    node* root = new node(1);

    for (int i=2; i<=12; i++) listAppend(i);

    printList(root);

    cout << "List size : " << listSize() << endl;

    listPrepend(-1);
    listPrepend(-2);

    printList();

    deleteLast();
    printList();
    deleteFirst();
    printList();

}