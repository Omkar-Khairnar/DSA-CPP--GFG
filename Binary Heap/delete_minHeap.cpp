#include <bits/stdc++.h>
 
using namespace std;

int parent(int i){ return (i-1)/2; }
int left(int i){ return (2*i+1);}
int right(int i){ return (2*i+2);}

void delete_from_minHeap(vector<int>& arr, int index){
    int len=arr.size();
    if(index >= len) return;

    swap(arr[index], arr[len-1]);
    arr.pop_back();
    int lt=left(index), rt=right(index);
    while(index < len && (arr[index] < arr[lt] || arr[index] < arr[rt])){
        if(arr[index] < arr[lt]){
            swap(arr[index], arr[lt]);
            index=lt;
            lt=left(lt);
            rt=right(lt);
        }
        else{
            swap(arr[index], arr[rt]);
            index=rt;
            lt=left(rt);
            rt=right(rt);
        }
    }
}
 
int main(int argc, char const *argv[])
{
 
  return 0;
}