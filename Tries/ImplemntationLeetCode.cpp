#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool endOfTheWord;

    TrieNode(char val){
        data=val;

        for(int i=0;i<26;i++){
            children[i]=NULL;
        }

        endOfTheWord=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode*root,string word){
        //base case
        if(word.length()==0){
            root->endOfTheWord=true;
            return;
        }

        //now getting the index of curently inserting number
        int index=word[0]-'a';
        TrieNode* child;

        //checking if present or not
        if(root->children[index]!=NULL){
            //now just update hte child
            child=root->children[index];
        }
        else{
            //create a new node
            child= new TrieNode(word[0]);
            root->children[index]=child;
        }

        //calling out the recursion for this now
        insertUtil(child,word.substr(1));
    }
    
    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->endOfTheWord;
        }

        //get the fresh index 
        int index=word[0]-'a';
        TrieNode* child;

        //if present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //the word is not present if not found
            return false;
        }

        //calliing out the recusion 
        return searchUtil(child,word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root,word);
    }

    bool Util(TrieNode* root,string prefix){
        //now lets just make a ligic
        if(prefix.length()==0){
            return true;
        }

        //get the index
        int index=prefix[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            //now just make this check again
            child=root->children[index];
        } 
        else{
            return false;
        }
        return Util(child,prefix.substr(1));
    }
    
    bool startsWith(string prefix) {
        return Util(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */