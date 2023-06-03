#include <bits/stdc++.h>
 
using namespace std;

int parent(int i){ return (i-1)/2; }
int left(int i){ return (2*i+1);}
int right(int i){ return (2*i+2);}

//This minHeapify and MaxHeapify corrects the array having one violation of heap property.
//If it is given array of random elements then we start from lowest internal node and apply minHeapify function for each node upto root.
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


void maxHeapify(vector<int> &arr, int index){
    int temp=arr[index];
    int sz=arr.size()-1;
    int maxVal=-1;
    int lt=left(index), rt=right(index);

    //Checking if Left  and right Exist or not and deciding Minimum value;
    if(rt <= sz){
    maxVal=max(max(arr[rt],arr[lt]), arr[index]);
    }
    else if(lt <=sz){
        maxVal= max(arr[index], arr[lt]);
    }
    else{
        maxVal=arr[index];
    }

    if(maxVal == temp) return;
    if(maxVal == arr[lt]){
        swap(arr[index], arr[lt]);
        maxHeapify(arr, lt);
    }
    else {
        swap(arr[index], arr[rt]);
        maxHeapify(arr, rt);
    }
}

int main(int argc, char const *argv[])
{
 vector<int>arr={10,5,3,8,1};
 int n=arr.size();


 //Here we start from (n-2)/2 which is parent of last node i.e. last internal node. 
 for(int i=(n-2)/2; i>=0; i--){
    minHeapify(arr,i);
 }


  return 0;
}