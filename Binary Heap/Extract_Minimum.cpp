#include <bits/stdc++.h>
 
using namespace std;
 
 int parent(int i){ return (i-1)/2; }
 int left(int i){ return (2*i+1);}
 int right(int i){ return (2*i+2);}

 void minHeapify(vector<int> &arr, int index){
    int temp=arr[index];
    int sz=arr.size()-1;
    int minVal=-1;
    int lt=left(index), rt=right(index);

    //Checking if Left  and right Exist or not and deciding Minimum value;
    if(rt <= sz){
    minVal=min(min(arr[rt],arr[lt]), arr[index]);
    }
    else if(lt <=sz){
        minVal= min(arr[index], arr[lt]);
    }
    else{
        minVal=arr[index];
    }

    if(minVal == temp) return;
    if(minVal == arr[lt]){
        swap(arr[index], arr[lt]);
        minHeapify(arr, lt);
    }
    else {
        swap(arr[index], arr[rt]);
        minHeapify(arr, rt);
    }
}

int extract_minimum(vector<int> &arr){
    int sz=arr.size();
    
    if(sz==0){
        return INT_MAX;
    }
    else if(sz==1){
        sz--;
        return arr[0];
    }

    int val=arr[0];
    swap(arr[0], arr[sz-1]);
    arr.pop_back();
    minHeapify(arr,0);
    return val;   
}
 
int main(int argc, char const *argv[])
{
 
  return 0;
}