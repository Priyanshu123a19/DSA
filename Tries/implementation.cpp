#include <iostream>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){

        //first if the base condtion 
        //if the end of the word is reached
        //then we make the isEndOfWord true and return
        if(word.length() == 0){
            root->isEndOfWord = true;
            return;
        }

        //other wise now we will see wather that the character is present or not
        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != nullptr){
            //character is present
            child = root->children[index];
        }
        else{
            //character is not present
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //now we will call the insertUtil function for the remaining part of the word
        insertUtil(child,word.substr(1));
    }
    //over here we will be writing the function for the basic operations
    void insert(string word){
        insertUtil(root,word);
    }


    //!now over here we wil be writing the search function
    bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            return root->isEndOfWord;
        }

        //now over he we will be checking the character is present or not
        int index=word[0]-'A';
        TrieNode* child;

        if(root->children[index]!=nullptr){
            //character is present
            child=root->children[index];
        }
        else{
            //character is not present
            cout<<"word not found"<<endl;
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
};