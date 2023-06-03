#include <bits/stdc++.h>
 
using namespace std;
int binarySearchIterative(int arr[], int n, int key){
    int low=0, high=n-1;
    int mid;
    while (low<=high)
    {
       mid=(low+high)/2;
       if(key == arr[mid]){
        return mid;
       }
       else if(arr[mid]> key){
        high=mid-1;
       }
       else {
        low=mid+1;
       }
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key){
    int mid=(low+high)/2;
    if(low > high) return -1;
    if (key == arr[mid])
    {
       return mid;
    }
    else if(arr[mid]> key){
        return binarySearchRecursive(arr, low, mid-1, key);
    }
    else if(arr[mid]< key){
        return binarySearchRecursive(arr, mid+1, high, key);
    }
    else{
        return -1;
    }
    
}

 
int main(int argc, char const *argv[])
{
 int arr[]={2,3,5,1,80,100,765,966,25};
 int n=sizeof(arr)/sizeof(int);

 cout<<binarySearchRecursive(arr, 0, n-1,0)<<endl;

  return 0;
}