#include <stdio.h>

int search(int* nums,int numsize,int target);
int binarySearch(int * nums, int target, int left, int right);

int main() {
    int arr[]={1, 3, 4, 6, 7,8, 10, 11, 13, 15};
    printf("%d",search(arr,10,3));
    return 0;
}
int search(int* nums,int numsize,int target){
    return binarySearch(nums,target,0,numsize-1);
}
int binarySearch(int * nums, int target, int left, int right){
    if(left>right) return -1;
    int mid=(left+right)/2;
    if(nums[mid]==target) return mid;
    if(nums[mid]>target)
        return binarySearch(nums,target,left,mid-1);
    else
        return binarySearch(nums,target,mid+1,right);
}

