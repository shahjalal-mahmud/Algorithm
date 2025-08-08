#include<iostream>
using namespace std;

void isort(int a[], int n){
    for(int i=1, j, k; i<n; i++){
        for(k=a[i], j=i-1; j>=0 && a[j]>k; j--) a[j+1]=a[j];
        a[j+1]=k;
    }
}

int main(){
    int a[]={6,2,7,9,15,1,8,3}, n=8;
    isort(a, n);
    for(int x:a) cout<<x<<" ";
}