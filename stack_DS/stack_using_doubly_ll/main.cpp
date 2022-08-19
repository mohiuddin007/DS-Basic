#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

int main(){
    Stack <pair<int, char>> st;

    st.push(make_pair(1, 'a'));
    st.push(make_pair(5, 't'));
    st.push(make_pair(100, 's'));
    while(!st.empty()){
        pair <int, char> chk;
        chk = st.pop();
        cout<< chk.first<<" | "<<chk.second<<endl;
        // cout<< st.pop()<<endl;
    }
    cout<<st.size()<<endl;
    if(!st.empty()){
        pair <int, char> chk;
        chk = st.Top();
        cout<< chk.first<<" | "<<chk.second<<endl;
        // cout<< st.pop()<<endl;
    }
    // if(!st.empty()) cout << st.Top()<<endl;

    return 0;
}