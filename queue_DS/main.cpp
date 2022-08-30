#include<bits/stdc++.h>
#include"MYQUEUE.h"

using namespace std;

typedef pair <int, int> mytype;

int main () {
    Queue <int> q;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int chk;
        cin>>chk;
        q.push(chk);
    }

    while(!q.empty()){
        cout<<q.pop()<<" ";
    }

    if(!q.empty()){
        cout<<q.Front()<<endl;
    } 
    if(!q.empty()){
        cout<<q.Back()<<endl;
    }
}