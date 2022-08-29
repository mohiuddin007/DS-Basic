#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;

public:
    Node(int val){
        value = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue(){
        front = NULL;
        rear = NULL;
    }

    // enqueue --> push
    void push(int val){
        Node* newNode = new Node (val);

        if(front==NULL){
            front = newNode;
            rear = newNode;
            return;
        } 
        
        rear->next = newNode;
        rear = rear->next;
    }

    //dequeue --> pop

    int pop(){
        int chk = -1;
        if(rear == NULL){
            cout<<"Queue underflow | There is no element in the queue!"<<endl;
            return chk;
        }
        Node* delNode;
        delNode = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        chk = delNode->value;
        delete delNode;
        return chk;
    }

    //peek --> front() back()

    int Front(){
        int chk;
        chk = front->value;
        return chk;
    }

    int Back(){
        int chk;
        chk = rear->value;
        return chk;
    }

    //empty --> empty()
    bool empty(){
        if(front == NULL && rear == NULL){
            return true;
        } else {
            return false;
        }
    }
};