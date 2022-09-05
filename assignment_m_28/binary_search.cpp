#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int x, int lb, int ub){
    if(lb<=ub){
        int mid = (lb+ub)/2;

        if(x == arr[mid])return mid; //centre

        else if(x>arr[mid]) binarySearch(arr, x, mid+1, ub); //right

        else binarySearch(arr, x, lb, mid-1); //left
    }
    else return -1;
}

int main(){
    int siz;
    siz = 10;
    int arr[siz] = {1, 2, 4, 9, 12, 14, 16, 21, 32, 35};

    int checkvalue = 4;

    int indexNumber = binarySearch(arr, checkvalue, 0, siz-1);

    if(indexNumber != -1){
        cout<<"index no: "<< indexNumber << " Position No: " << indexNumber+1<<endl;
    } else {
        cout<<"not found";
    }


    return 0;
}
