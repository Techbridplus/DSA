#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<deque>
#include<algorithm>
using namespace std; 
void bubble_sort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int j=i-1;
        while(j>=0){
            if(arr[i]< arr[j]){
                j--;
            }else{
                swap(arr[j+1],arr[i]);
            }
        }
    }
}

int main(){
    vector<int> arr={1,2,3,1,67,};
    cout<<"\nbefore"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    bubble_sort(arr);
    cout<<"\nAfter"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}