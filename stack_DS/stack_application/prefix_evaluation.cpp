#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

int prefixEvaluation(string chk){

    Stack<int>st;

    for(int i= chk.length()-1; i>=0; i--){
        //chk[i] 0 - 9 --> operand
        if(chk[i] >= '0' && chk[i] <= '9'){
            st.push(chk[i] - '0');
        }else{ //chk[i] ---> operator
            int a = st.pop();
            int b = st.pop();

            switch (chk[i])
            {
            case '+':
                st.push(a+b);
                break;

            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(a/b);
                break;
            case '^':
                st.push(pow(a, b));
                break;
            
            default:
                break;
            }
        }

    }
    return st.Top();
}

int main(){
    cout<<prefixEvaluation("+*423")<<endl<<endl;
    cout<<prefixEvaluation("-+7*45+20")<<endl<<endl;
}