#include <bits/stdc++.h>
using namespace std;

// Simple searching algorithms

void linearSearch(int a[],int size,int target){
    for(int i=0;i<size;++i){
        if(a[i]==target){
            cout << "The target is in the list!\n";
            break;
        }
        else if(i==size-1 && a[i]!=target){
            cout << "The target isn't in the list!\n";
            break;
        }
    }
}

int binarySearch(int a[],int low,int mid,int high,int target){ // return index of the element
    if(low>high) return -1;
    if(a[mid]==target) return mid;
    else if(a[mid]>target) return binarySearch(a,low,(mid+low)/2,mid,target);
    else return binarySearch(a,mid+1,(high+mid+1)/2,high,target);
}

int main(){
    int n;
    cin >> n;
    int *arr=new int[n];
    for(int i=0;i<n;++i) cin>>arr[i];
    int key; cin>>key;
    linearSearch(arr,n,key);
    cout << "The index of the target in the list: " << binarySearch(arr,0,(n-1)/2,n-1,key) << endl;
    return 0;
}