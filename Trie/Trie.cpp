#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    TrieNode *links[26];
    bool isWordCompleted; 

    TrieNode(){
        isWordCompleted = false; //Initially setting word completed as False (will be true is node contains last char of string);
        for(int i=0; i<26; i++){
            this->links[i]=NULL;
        }
    }
};

class Trie{
    public:
    TrieNode *root;

    //Constructor
    Trie(){
        root = new TrieNode();
    }

    //Return true OR false isWord present in Trie or not.
    bool searchWord(string s){
        TrieNode *curr = root;
        for(int i=0; i<s.size(); i++){
            if(curr->links[s[i]-'a'] == NULL){
                return false;
            }
            curr = curr->links[s[i]-'a'];
        }
        return curr->isWordCompleted;  //Checking at last Node of string is wordCompleted or not. This can be false when trie contains string "geeks" and we are searching for "geek"
    }

    //Inserts Word in Trie
    void insertWord(string s){
        TrieNode *curr = root;
        for(int i=0; i<s.size(); i++){
            if(curr->links[s[i]-'a'] == NULL){
                curr->links[s[i]-'a'] = new TrieNode();
            }
            curr = curr->links[s[i]-'a'];
        }
        curr->isWordCompleted=true;
    }

    //Returns true if any string contains prefix
    bool isPrefixPresent(string prefix){
        TrieNode *curr = root;
        for(int i=0; i<prefix.size(); i++){
            if(curr->links[prefix[i]-'a'] == NULL){
                return false;
            }
            curr = curr->links[prefix[i]-'a'];
        }
        return true; 
    }

    //Checking all childrens are NULL or Not
    bool isEmpty(TrieNode *node){
        for(int i=0; i<26; i++){
            if(node->links[i] != NULL) return false;
        }
        return true;
    }

    //Delete a Word from Trie and return root of Trie if Trie doesn't become empty else NULL
    TrieNode *deleteWord(TrieNode *root, string s, int idx){
        if(root == NULL) return NULL;
        
        if(idx == s.size()){
            root->isWordCompleted = false;
            if(isEmpty(root) == true){
                delete(root);
                root=NULL;
            }
            return root;
        }

        root->links[s[idx]-'a'] = deleteWord(root->links[s[idx]-'a'], s, idx+1);

        //Checking if root becomes empty deleting it and returning NULL else returning root;
        if(isEmpty(root) && root->isWordCompleted == false){
            delete(root); 
            root = NULL;
        }
        return root;
    }


};


 
 
int main(int argc, char const *argv[])
{
 
  return 0;
}