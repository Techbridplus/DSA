#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums,int s,int mid,int e){
    
    int size1=mid-s+1;
    int size2=e-mid;
    vector<int> nums1(size1);
    vector<int> nums2(size2);
    for(int i=0;i<size1;i++){
        nums1[i]=nums[s+i];
    }
    for(int j=0;j<size2;j++){
        nums2[j]=nums[mid+1+j];
    }
    int i=0,j=0,k=s;
    while(i<size1 && j<size2){
        if(nums1[i]<nums2[j]){
            nums[k]=nums1[i++];
        }else{
            nums[k]=nums2[j++];
        }
        k++;
    }
    while(i<size1){
        nums[k]=nums1[i++];
        k++;
    }
    while(j<size2){
        nums[k]=nums2[j++];
        k++;
    }
}
void mergesort(vector<int>& nums,int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergesort(nums,s,mid);
    mergesort(nums,mid+1,e);
    merge(nums,s,mid,e);
}
int main()
{
    vector<int> nums={7,5,3,7,0,2,1,6};
    cout<<"\nresult : ";
    mergesort(nums,0,nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}

