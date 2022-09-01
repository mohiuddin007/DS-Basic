#include<bits/stdc++.h>
using namespace std;

template <typename N> class Node{
public:
    N value;
    Node* next;
    Node* prev;

    Node(N val){
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template <typename S> class Stack{
    Node <S> *head;
    Node <S> *top;
    int count = 0;

public:
    Stack(){
        head = NULL;
        top = NULL;
    }
    //PUSH
    void push(S val){
        Node <S> *newNode = new Node <S> (val);

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
    S pop(){
        Node <S> *delNode;
        delNode = top;
        S chk;
    
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
    S Top(){
        S chk;
        if(top == NULL){
            cout<<"Stack underflow | There in no element in Top "<<endl;
        } else {
            chk = top->value;
        }
        return chk;
    }
};
