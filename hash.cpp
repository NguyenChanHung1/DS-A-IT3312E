#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define M 10000

// *** CHAINING METHOD

int m;
int dh_a,dh_b;

int h1(ULL k){
    return k%dh_a;
}

int h2(ULL k){
    return dh_b-(k%dh_b);
}

int h(ULL k){ // hash function
    return k%m;
}

typedef struct Node{ // Linked list
    ULL key;
    struct Node* next;
} Node;

Node* T[M]{NULL};

Node* insertList(Node* head, ULL k){
    // Create new node
    Node* newNode=new Node();
    newNode->key=k;
    // Integrate the node into the linked list
    newNode->next=head;
    head=newNode;
    return head;
}

Node* findList(Node* head, ULL k){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->key==k) return temp;
        else temp=temp->next;
    }
    return temp;
}

int insertTable(ULL k){
    int i=h(k);
    // The head node of the linked list that is possible to include k in is T[i]
    Node* res=findList(T[i],k);
    if(res==NULL){
        T[i]=insertList(T[i],k);
        return 1;
    } else return 0;
}

// *** OPEN ADDRESSING METHOD
/* Some techniques:
    1/ Linear Probing
    2/ Quadratic Probing
    3/ Double Hashing
*/

bool isFull(int arr[],int size){
    for(int i=0;i<size;++i)
        if(!arr[i]) return false;
    return true;
}

void LinearProbing(int arr[],int s_arr,int Hash[]){ 
    // Elements are hashed following the rule: h(x)=(h(x)+i)%sizeoftable.
    // if(isFull(Hash,m)){
    //     cout << "Error!";
    //     return;
    // }
    // for(int i=0;i<s_arr;++i){
    //     int t=h(arr[i]);
    //     if(Hash[t]==0) Hash[t]=arr[i];
    //     else {
    //         while(Hash[t]!=0) t++;
    //         Hash[t]=arr[i];
    //     }
    // } // 1st way of implementation
    // 2nd way:
    if(isFull(Hash,m)){
        cout << "Error!";
        return;
    }
    for(int i=0;i<m;++i){
        if(!Hash[i]) break;
        else if(Hash[i] && i==m-1) return;
    } // Check whether the whole table is occupied
    for(int i=0;i<s_arr;++i){
        int t=h(arr[i]);
        while(Hash[t]!=0) t=(t+1)%m; // hash_size=m
        Hash[t]=arr[i];
    }
}

void QuadraticProbing(int arr[],int s_arr,int Hash[]){ 
    // Check if the Hash table is full
    if(isFull(Hash,m)) {
        cout << "Error!";
        return;
    }
    for(int i=0;i<s_arr;++i){
        int t=h(arr[i]);
        // Check whether the table is occupied.
        // The elements are hashed following the formula: h(x)=(h(x)+i*i)%sizeoftable.
        if(Hash[t]==0) Hash[t]=arr[i];
        else {
            for(int j=0;j<m;++j){
                int nt=(t+j*j)%m; // Finding the index of the table which is not occupied, where t remains unchanged
                if(!Hash[nt]){
                    Hash[nt]=arr[i];
                    break;
                }
            }
        }
    }
}

void DoubleHashing(int arr[],int s_arr,int Hash[]){
    // The elements hashed follow the formula: h(x)=(h1(x)+i*h2(x))%sizeoftable.
    // where: h1(x) is the hash function, h2(x) is called the step function.
    if(isFull(Hash,dh_a)) {
        cout << "Error!"; return;
    }
    for(int i=0;i<s_arr;++i){
        int probe=h1(arr[i]);
        int step=h2(arr[i]);
        while(Hash[probe]) probe=(probe+step)%dh_a; // dh_a is the size of newHash[].
        Hash[probe]=arr[i];
    }
}

// UTILIZING FUNCTIONS
void printTable(int Hash[], int size){
    for(int i=0;i<size;++i) cout << Hash[i] << " "; 
    cout << endl;
}

void reset(int Hash[],int h_size){
    for(int i=0;i<h_size;++i) Hash[i]=0;
}

int main(){
    cout << "Hash: "; cin>>m;
    int Hash[m]{0}; // Initialize an array Hash representing the Hash table, where all the values are 0
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;++i) cin>>arr[i];
    cout << "Linear Probing:\n";
    LinearProbing(arr,n,Hash);
    printTable(Hash,m);
    reset(Hash,m); // Reset before hashing in other ways.
    cout << "Quadratic Probing:\n";
    QuadraticProbing(arr,n,Hash);
    printTable(Hash,m);
    reset(Hash,m); // Reset before hashing in other ways.
    cout << "For double hashing, we need to declare 2 integers dh_a and dh_b which will exist in "<< 
            "the hash functions h1 and h2.\ndh_a="; cin>>dh_a;
    cout << "dh_b="; cin>>dh_b; // Frequently, dh_b is a prime smaller than dh_a
    int newHash[dh_a]{0};
    DoubleHashing(arr,n,newHash);
    printTable(newHash,dh_a);
    reset(newHash,dh_a); // Reset before hashing in other ways.
    return 0;
}