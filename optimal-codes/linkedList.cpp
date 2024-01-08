#include <bits/stdc++.h>
using namespace std;

/*
    Operations:
        Traverse
        Append
        Prepend
        InsertAt
        DeleteFrom
        Update a node
*/

class Node{
    public:
        int key;
        int data;
        Node* next;

        Node() {
            key = 0;
            data = 0;
            next = NULL;
        }

        Node(int k, int d) {
            key = k;
            data = d;
            next = NULL;
        }
}

class SinglyLinkedList 
{
    public:
        Node* head;
        SinglyLinkedList(Node* &h){
            head = h;
        }
}


int main (void)
{
    Node n1(1, 10);
    Node n2(2, 20);
}