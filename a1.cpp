// Linked List Assignment 1: Doubly Linked Lists
#include<bits/stdc++.h>
using namespace std;

// creation of node
class Node{
public:
    string Name;
    int Age;
    Node* prev;
    Node* next;
    Node(string n,int a){
        Name = n;
        Age = a;
        next = NULL;
        prev = NULL;
    }
};

// Function to add elements in the list
void pushBack(Node*& head,Node*& current){
    if(head==NULL){
        head = current;
        return;
    }
    // if no head then set new node as head
    Node* temp = head;
    // if next not none (tail) then continue traversing
    while(temp->next!=NULL){
        temp = temp->next;
    }
    // if tail, add to end
    temp->next = current;
    // set prev pointer to current node
    current->prev = temp;
    return;
}

// Function to display the list
void printFamily(Node* head){
    // Start at head and check if next is not tail
    while(head!=NULL){
        // Display current node of list and traverse forward
        cout<<head->Name<<" "<<head->Age<<endl;
        head = head->next;
    }
    return;
}

// Main function
int main(){
    Node* head = NULL;
    int n;
    cout<<"Enter the number of family members: ";
    cin>>n;
    int i=0;
    while(i<n){
        string s;
        int a;
        cout<<"Enter Name: ";
        cin>>s;
        cout<<"Enter Age: ";
        cin>>a;
        Node* current = new Node(s,a);
        pushBack(head,current);
        i++;
    }
    printFamily(head);
    return 0;
}