#include <bits/stdc++.h>
 
using namespace std;
 
 int minKey(vector<int>key, vector<bool>mSet, int V){
    int min=INT_MAX,min_index;

    for(int i=0; i<V; i++){
        if(mSet[i]==false && key[i] < min){
            min=key[i], min_index=i;
        }
    }
        return min_index;
 }
 

 int MST_Weight(vector<int>graph[], int V){
    vector<int>key(V,INT_MAX);
    key[0]=0;
    vector<bool>mSet(V,false);
    int res=0;

    for(int count=0; count <V; count++){

        int u=minKey(key,mSet,V);
        res=res+key[u];
        mSet[u]=true;

        for(int i=0; i<V; i++){
            if(mSet[i]==false && graph[u][i] !=0){
                key[i]=min(key[i], graph[u][i]);
            }
        }
    }
    return res;
 }
int main(int argc, char const *argv[])
{
 
  return 0;
}