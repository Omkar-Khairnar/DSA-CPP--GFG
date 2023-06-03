#include <bits/stdc++.h>
 
using namespace std;

int parent(int i){ return (i-1)/2; }
int left(int i){ return (2*i+1);}
int right(int i){ return (2*i+2);}


void insert_MinHeap(vector<int> &arr, int ele){
    arr.push_back(ele);
    for(int i=arr.size()-1 ; i!=0 && arr[parent(i)] > arr[i];){
        swap(arr[parent(i)], arr[i]);
        i=parent(i);
    }
} 
void insert_MaxHeap(vector<int> &arr, int ele){
    arr.push_back(ele);
    for(int i=arr.size()-1 ; i!=0 && arr[parent(i)] < arr[i];){
        swap(arr[parent(i)], arr[i]);
        i=parent(i);
    }
} 

 
int main(int argc, char const *argv[])
{
 
  return 0;
}