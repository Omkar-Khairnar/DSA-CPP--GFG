#include <bits/stdc++.h>
 
using namespace std;

struct Node{
    Node *links[26];
    bool flag=false;

    bool getPresenceKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node*node){
        links[ch - 'a']=node;
    }

    Node *get(char ch){
        return links[ch - 'a'];
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag=true;
    }
};

class Trie{
    public:
    Node *root;
    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node * node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->getPresenceKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node * node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->getPresenceKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix){
        Node *node=root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->getPresenceKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }

        return true;
    }

};
 
int main(int argc, char const *argv[])
{
 
  return 0;
}