#include<bits/stdc++.h>

using namespace std;

typedef long long ll; //64bit
#define rep(i, end) for(ll i=0; i<end; i++)
#define repx(i, start, end) for(ll i=start; i<end; i++)

ll length, heapsize;

ll left(ll i){
    return 2 * i;
}
ll right(ll i){
    return 2 * i + 1;
}

void max_heapify(ll A[], ll i){
    ll largest, l = left(i), r = right(i);
    
    largest = i;
    if (l<=heapsize && A[l]>A[largest]){    
        largest = l;
    }
    if (r<=heapsize && A[r]>A[largest]){
        largest = r;
    }

    if (largest != i){
        ll temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        max_heapify(A, largest);
    }
}

void build_max_heap(ll A[]){
    for(ll i=length/2 + 1; i>=1; i--)
        max_heapify(A, i);
}

vector<ll> heapsort(ll A[]){
    vector<ll> sorted_A;

    build_max_heap(A);
    rep(i, length+1){
        sorted_A.push_back(A[1]);

        ll temp = A[heapsize];
        A[heapsize] = A[1];
        A[1] = temp;

        heapsize--;
        max_heapify(A, 1);
    }
    return sorted_A;
}

int main(){
    ll i;
    cout<<"Enter the Size of the array"<<endl;
    cin>>length;
    heapsize = length;

    ll A[length+1];
    repx(i, 1, length+1)   cin>>A[i];

    vector<ll> sorted_A = heapsort(A);

    cout<<endl;
    rep(i, length)    cout<<sorted_A[i]<<" ";

    return 0;
}
