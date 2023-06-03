#include <bits/stdc++.h>
 
using namespace std;

//Array should be sorted
int firstOccurrence(int arr[], int n, int key){
    int ans=-1;
    int low=0, high=n-1, mid;
    while(low <= high){
        mid=(low+high)/2;
       if(key == arr[mid]){
         ans = mid;
         high=mid-1;
       }
       else if(arr[mid]> key){
        high=mid-1;
       }
       else {
        low=mid+1;
       }
    }
    return ans;
} 
    int LastOccurrence(int arr[], int n, int key){
        int ans=-1;
        int low=0, high=n-1, mid;
        while(low <= high){
            mid=(low+high)/2;
        if(key == arr[mid]){
            ans = mid;
            low=mid+1;
        }
        else if(arr[mid]> key){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
        }
        return ans;
    } 
    
int main(int argc, char const *argv[])
{
    int arr[]={80,80,5,1,80,100,765,966,25};
    int n=sizeof(arr)/sizeof(int);
    cout<<LastOccurrence(arr, n,80)<<endl;
 
  return 0;
}