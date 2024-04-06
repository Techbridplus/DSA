#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<deque>
#include<algorithm>
using namespace std;
vector<int> bubble_sort(vector<int> arr){
    for(int i=0;i<arr.size()-1;i++){
        bool swaped=false;
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaped=true;
            }
        }
        if(!swaped){
            break;
        }
    }
    return arr;
}

int main(){
    vector<int> arr={1,2,3,1,67,};
    cout<<"\nbefore"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    arr=bubble_sort(arr);
    cout<<"\nAfter"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}