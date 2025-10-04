#include <bits/stdc++.h>
using namespace std;
class TrieNode {
    public:
    char val;
    TrieNode* children[26];
    bool endOfNode;

    TrieNode(char c){
        val=c;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        endOfNode=false;
    }
};

class Trie{
    //here we will implement the insertion functions
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    //now over here we will also add on some new things in the insertion fucntion 
    void insertUtil(TrieNode*root,string word){
        //first base case
        if(word.length()==0){
            root->endOfNode=true;
            return;
        }

        //get the child
        TrieNode* child;
        int index=word[0]-'a';

        //now see the logic for having the element or not
        if(root->children[index]!=NULL){
            //just get to the next element
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursion called
        insertUtil(child,word.substr(1));
    }

    void insert(TrieNode* root,string word){
        insertUtil(root,word);
    }

    void findPrefix(TrieNode* root,string &ans){
        //over here we will get the ans
        int cnt=0;
        char latestVal;
        TrieNode* latestNode;
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                cnt++;
                latestVal=root->children[i]->val;
                latestNode=root->children[i];
            }
        }
        if(cnt==1 && !root->endOfNode){
            //over here we will get the ans for this
            ans.push_back(latestVal);
            //calling out the recursion 
            findPrefix(latestNode,ans);
        }else{
        return;
        }
        //else we will just call out the recursion and find the next one 
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //now over here initializing the things and calling out the function in order to recieve the ans
        Trie *trie= new Trie();
        for(int i=0;i<strs.size();i++){
            if(strs[i]==""){
                trie->root->endOfNode=true;
                continue;
            }
            trie->insert(trie->root,strs[i]);
        }

        string ans;
        //making another function to call out for finding out the prefix;
        trie->findPrefix(trie->root,ans);
        return ans;
    }
};