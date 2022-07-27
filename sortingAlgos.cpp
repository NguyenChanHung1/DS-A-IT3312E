#include <bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void insertionSort(int a[],int size){
    int pos,temp;
    for(int i=1;i<size;++i){
        temp=a[i];
        pos=i;
        while(pos>0 && a[pos-1]>temp){
            a[pos]=a[pos-1];
            pos--;
        }
        a[pos]=temp;
    }
    for(int i=0;i<size;++i) cout << a[i] << " ";
    cout << endl;
} // Repeatedly swap the ith element with the one to its left if smaller (Time complexity: O(n^2))

void selectionSort(int a[],int size){
    for(int i=0;i<size-1;++i)
        for(int j=i+1;j<size;++j)
            if(a[i]>a[j]) swap(a[i],a[j]);
    for(int i=0;i<size;++i) cout << a[i] << " ";
    cout << endl;
} // Repeatedly swap the current element with the afterward elements that are smaller than the current one.
// Time complexity: O(n^2)

void bubbleSort(int a[],int size){
    bool sorted=false;
    for(int i=1;i<size;++i)
        if(sorted==false){
            sorted=true;
            for(int j=0;j<size-i;j++)
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    sorted=false; // exchange signal
                }
        }
    for(int i=0;i<size;i++) cout << a[i] << " ";
    cout << endl;
} // Time complexity: O(n^2). Each iteration directs the largest unsorted element to its correct position.

void nonRecursiveMergeSort(int a[],int first,int mid,int last){
    int tempA[last+1];
    int first1=first,last1=mid;
    int first2=mid+1,last2=last;
    int index=first1;
    for(;first1<=last1 && first2<=last2;index++){
        if(a[first1]<a[first2]){
            tempA[index]=a[first1];
            first1++;
        } 
        else {
            tempA[index]=a[first2];
            first2++;
        }
    }
    for(;first1<=last1;first1++,index++) tempA[index]=a[first1];
    for(;first2<=last2;first2++,index++) tempA[index]=a[first2];
    for(index=first;index<=last;index++) a[index]=tempA[index];
    for(int i=0;i<=last;i++) cout << a[i] << " ";
    cout << endl;
} // Time complexity: O(n)

// void merge(int a[],int const f,int const m,int const l){
//     // Create size variable
//     int const Lsize=m-f+1,Rsize=l-m; 
//     // Create 2 temporary arrays
//     int *left=new int[Lsize];
//     int *right=new int[Rsize];
//     // Copy data
//     for(int i=0;i<Lsize;i++) left[i]=a[f+i];
//     for(int i=0;i<Rsize;i++) right[i]=a[m+i+1];
//     // Initial index of 2 arrays
//     int Li=0,Ri=0;
//     int Merged_i=f;
//     // Copy data from temporary arrays to the original one, in correct positions
//     while(Li<Lsize && Ri<Rsize){
//         if(left[Li]<=right[Ri]){
//             a[Merged_i]=left[Li];
//             Li++;
//         } else {
//             a[Merged_i]=right[Ri];
//             Ri++;
//         }
//         Merged_i++;
//     }
//     // Copy the remaining ones
//     while(Li<Lsize){
//         a[Merged_i]=left[Li];
//         Li++;Merged_i++;
//     }
//     while(Ri<Rsize){
//         a[Merged_i]=right[Ri];
//         Ri++;Merged_i++;
//     }
//     // Free the memory utilized from left and right
//     delete[] left; delete[] right;
// }

// void recursiveMergeSort(int a[],int first,int last){
//     if(last>first){
//         int mid=last+(first-last)/2;
//         recursiveMergeSort(a,first,mid);
//         recursiveMergeSort(a,mid+1,last);  
//         merge(a,first,mid,last);
//     }
// }

int partition(int a[],int low, int high){ // Arrange the array if the previous elements is less than pivot
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return (i+1); // Always returns the pivot
}

void quickSort(int a[],int low,int high){
    if(low<high){
        int pi=partition(a,low,high); // Determine the index of pivot, in order to divide the array
        /* Arrange the left and right subarrays recursively, except the pivot, which is in the correct  
position */
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
} // Time complexity O(nlogn)

void HeapSort(int a[],int low,int high);

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i) cin >> arr[i];
    cout << "Insertion Sort:\n";
    insertionSort(arr,n);
    cout << "Selection Sort:\n";
    selectionSort(arr,n);
    cout << "Bubble Sort:\n";
    bubbleSort(arr,n);
    cout << "Non-recursive Merge Sort:\n";
    nonRecursiveMergeSort(arr,0,(n-1)/2,n-1);
    // cout << "Recursive Merge Sort:\n";
    // recursiveMergeSort(arr,0,n-1);
    // for(int i=0;i<n;++i) cout << arr[i] << " "; cout << endl;
    cout << "Quick Sort:\n";
    quickSort(arr,0,n-1);
    for(int i=0;i<n;++i) cout << arr[i] << " ";
    cout << endl;
    return 0;
}