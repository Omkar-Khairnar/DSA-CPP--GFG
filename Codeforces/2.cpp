#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        if(mp.size() > 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
 
  return 0;
}