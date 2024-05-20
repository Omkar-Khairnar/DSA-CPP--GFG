#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cuts = 0;
        int idx = 0;
        bool isOne = false;
        int reduction =0;
        while(idx < s.size()){
            if(s[idx] == '1') isOne = true;
            if(s[idx] == '0' && isOne){
                while(s[idx] == '0') idx++;
                cuts+=2;
                if(idx < s.size()) reduction =1;
            }
        }
        if(s[s.size()-1] == '0') cuts-=1;
        cuts -= reduction;

        cout<<cuts+1<<endl;
        
    }
 
  return 0;
}