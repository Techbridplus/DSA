#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<deque>
#include<algorithm>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }

    void heapify(int i,int n){
        int largest=i;
        int l=i*2;
        int r=i*2+1;
        if(l<=n && arr[l]>arr[largest]){
            largest=l;
        }
        if(r<=n && arr[r]>arr[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(largest,n);
        }
    }


    void insert(int val){
        size++;
        int index=size;
        arr[index]=val;
        for(int i=size/2;i>0;i--){
           heapify(i,size);
    }
    }
    void deletenode(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        for(int i=size/2;i>0;i--){
           heapify(i,size);
    }
    }
    void heapSort(int n){
        while(n>1){
            swap(arr[1],arr[n]);
            n--;
            heapify(1,n);
        }


    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(57);
    h.insert(60);
    h.print();
    h.heapSort(h.size);
    h.print();
    
    return 0;
}