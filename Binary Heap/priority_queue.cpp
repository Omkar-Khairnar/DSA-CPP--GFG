#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(int argc, char const *argv[])
{
// By Default Priority queue is based on MAX Heap. Root element will be maximum.
    priority_queue<int> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);

    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    //Syntax for priority queue based upon min heap. Root element will be minimum.
    priority_queue<int, vector<int>, greater<int>> pq_minHeap;
    pq_minHeap.push(10);
    pq_minHeap.push(15);
    pq_minHeap.push(5);

    while (!pq_minHeap.empty())
    {
        cout<<pq_minHeap.top()<<" ";
        pq_minHeap.pop();
    }
    
    

  return 0;
}