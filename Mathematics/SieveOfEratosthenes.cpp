#include <bits/stdc++.h>
 
using namespace std;
 
 //Find Numbers from 0 to k which are prime--> Returning Vector such that vec[i]=true means i is prime else false;
 vector<bool>sieveOfErastothenes(int k){
    vector<bool>isPrime(k+1, true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2; i*i<=k; i++){
        if(isPrime[i] == false) continue;
        for(int j=2*i; j<=k; j+=i){
            isPrime[j]=false;
        }
    }

    return isPrime;
 }
 
int main(int argc, char const *argv[])
{
    vector<bool>ans(sieveOfErastothenes(100));
    for(int i=0; i<ans.size(); i++){
        cout<<i<<" "<<ans[i]<<"|| ";
    }
 
  return 0;
}