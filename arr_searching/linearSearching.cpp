#include<bits/stdc++.h>
using namespace std;

int main(){
    int siz;
    cin>>siz;

    int arr[siz];

    for(int i=0; i<siz; i++){
        cin>>arr[i];
    }
    char c;
    cout<<"Do you want to search: (Y/N) ";
    cin>>c;

    while(toupper(c) == 'Y'){
        int checkvalue;
        cout<<"please enter the value you want to search: ";
        cin>>checkvalue;
        int flag = 0;

        for(int i=0; i<siz; i++){
            if(arr[i] == checkvalue){
                cout<<"index number"<<i<<" Position: "<<i+1<<endl;
                flag++;
            }
        }
        if(flag == 0) cout<<"Not found"<<endl;

        cout<<"Do you want to continue searching: (Y/N) ";
        cin>>c;
    }


}
