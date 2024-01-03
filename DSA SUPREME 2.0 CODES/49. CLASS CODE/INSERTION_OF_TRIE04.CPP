// 4. Insertion Method of Trie
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
        // Present hai -> to root ko aange traverse krdo
        childNode = root->children[index];
    }
    else{
        // Absent hai -> to ek new childNode create krke root ko aange traverse krdo
        childNode = new TrieNode(ch);
        root->children[index] = childNode;
    }

    // Baki ka recursion solve kar lega
    insertWord(childNode, word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');

    insertWord(root, "donation");

    return 0;
}