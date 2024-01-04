// 5. Searching Method of Trie
#include<iostream>
using namespace std;

class TrieNode
{
    public:
        char value;
        bool isTerminal;
        TrieNode* children[26];

        TrieNode(char value){
            this->value = value;
            this->isTerminal = false;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
        }
};

// Insertion of word into trie
void insertWord(TrieNode* root, string word){
    // Base Case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    // 1 Case hum solve kar lenge
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* childNode;
    if(root->children[index] != NULL){
        // Present hai -> traverse
        childNode = root->children[index];
    }
    else{
        // Absent hai -> create new child and traverse
        childNode = new TrieNode(ch);
        root->children[index] = childNode;
    }

    // Baki ka recursion solve kar lega
    insertWord(childNode, word.substr(1));
}

// Searching of word from trie
bool searchWord(TrieNode* root, string word){
    // Base case
    if(word.length() == 0){
        return root->isTerminal;
    }

    // 1 case hum solve kar lenge
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* childNode;

    if(root->children[index] != NULL){
        // Present hai -> found means traverse kro
        childNode = root->children[index];
    }
    else{
        // absent hai -> not found means word hai nhi hai
        return false;
    }

    // ab recursion solve kar lega
    bool recursionKaAns = searchWord(childNode, word.substr(1));
    return recursionKaAns;
}

int main(){
    // Create Root Node
    TrieNode* root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "cdm");
    insertWord(root, "lover");
    insertWord(root, "load");
    insertWord(root, "bat");
    insertWord(root, "car");
    insertWord(root, "cat");
    insertWord(root, "lov");
    
    if(searchWord(root, "lov")){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    return 0;
}