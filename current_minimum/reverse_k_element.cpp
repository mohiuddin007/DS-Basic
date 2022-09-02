#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

/*
    5
    1 2 3 4 5
result: 1 1 1 1 1 

    7
    1 6 43 1 2 0 5
result: 0 0 1 1 1 1 1

    10
    6 5 5 5 4 7 1 2 1 2
result : 1 1 1 1 4 4 5 5 5 6 
*/

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    Stack <int> st;
    Stack <int> minStack;

    int min = INT_MAX;
    for(int i=0; i<n; i++){
        if(array[i] <= min){
            minStack.push(array[i]);
            min = array[i];
        }
        st.push(array[i]);
    }
    
    while(!st.empty()){
        //if top of minStack and st is equal
        if(minStack.Top() != st.Top()){
            st.pop();
            cout<<minStack.Top()<<" ";
        }
        // else
        else {
            cout<<minStack.Top()<<" ";
            minStack.pop();
            st.pop();
        }
    }

    cout<< endl << endl;

    return 0;
}