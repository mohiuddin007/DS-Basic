#include<bits/stdc++.h>

using namespace std;

template<typename T> T myMax(T a, T b){
    return (a>b) ? a : b;
}

int main(){
    //functionName <Datatype> (parameter)
    cout<<myMax<int>(3, 7)<<endl;

    cout<<myMax<float>(3.3, 7.8)<<endl;
        
    cout<<myMax<char>('b', 'f')<<endl;
    
    return 0;
}