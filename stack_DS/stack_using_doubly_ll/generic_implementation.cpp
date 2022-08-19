#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

int globalId = 100;

class person{
    string name;
    int id;
    float salary;
public:
    person(){
        name = "";
        id = -1;
        salary = 1.0;
    }
    void setName (string name){
        this->name = name;
    }
    void setSalary(float salary){
        this->salary = salary;
    }
    person(string name, float salary){
        setName(name);
        setSalary(salary);
        id=globalId;
        globalId++;
    }

    int getID(){
        return id;
    }
    string getName(){
        return name;
    }
    float getSalary(){
        return salary;
    }

    void print(){
        cout<<name<<" | "<<id<<" | "<<salary<<endl;
    }
};

int main(){
    // Stack <pair<int, char>> st;

    // st.push(make_pair(1, 'a'));
    // st.push(make_pair(5, 't'));
    // st.push(make_pair(100, 's'));
    // while(!st.empty()){
    //     pair <int, char> chk;
    //     chk = st.pop();
    //     cout<< chk.first<<" | "<<chk.second<<endl;
    //     // cout<< st.pop()<<endl;
    // }
    // cout<<st.size()<<endl;
    // if(!st.empty()){
    //     pair <int, char> chk;
    //     chk = st.Top();
    //     cout<< chk.first<<" | "<<chk.second<<endl;
    //     // cout<< st.pop()<<endl;
    // }
    // // if(!st.empty()) cout << st.Top()<<endl;

    Stack <person> st;
    person a ("Akib Zaman", 1654.6);
    person b ("Zalil", 2000.6);
    person c ("Farid", 1600.6);
    st.push(a);
    st.push(b);
    st.push(c);

    person printObj;
    printObj = st.Top();
    printObj.print();
    
    while(!st.empty()){
        person printObj;
        printObj = st.pop();
        printObj.print();
    }

    cout<<st.size()<<endl;

    return 0;
}