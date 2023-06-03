#include <bits/stdc++.h>
 
using namespace std;

//Here vector is given and it is given that element at position i will be at position p lies between (i-k) and (i+k); Find the sorted array. 
void sort(int arr[], int n, int k){
    //This priority queue give lowest element at top.
    priority_queue<int, vector<int>, greater<int>> pq;

    int index=0;
    for (int i = 0; i <=k; i++){
        pq.push(arr[i]);
    }

    for(int i=k+1; i<n; i++){
        arr[index++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        arr[index++]=pq.top();
        pq.pop();
    }
    
}
 
int main(int argc, char const *argv[])
{
 
  return 0;
}