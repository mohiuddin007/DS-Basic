#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val){
        value = val;
        next = NULL;
        prev = NULL;
    }
};

class Stack{
    Node* head;
    Node* top;
    int count = 0;

public:
    Stack(){
        head = NULL;
        top = NULL;
    }
    //PUSH
    void push(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = top = newNode;
            count++;
            return;
        } 

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }
    //POP
    int pop(){
        Node* delNode;
        delNode = top;
        int chk=-1;
    
        if(head == NULL){ //there is no element in the stack(underflow)
            cout<< "Stack underflow"<<endl;
            return chk;
        }

        if(head == top){    ///there is only 1 element
            head = top = NULL;
        } else {  //there is more then 1 element
            top = delNode->prev;
            top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        count--;
        return chk;
    }
    //EMPTY
    bool empty(){
        if(head == NULL) return true;
        else return false;
    }
    //SIZE
    int size(){
        return count;
    }
    //TOP
    int Top(){
        int chk;
        if(top == NULL){
            cout<<"Stack underflow | There in no element in Top "<<endl;
            chk = -1;
        } else {
            chk = top->value;
        }
        return chk;
    }
};
