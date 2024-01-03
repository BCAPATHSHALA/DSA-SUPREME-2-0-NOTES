// 3. Create Trie Node
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

int main(){
    TrieNode* root = new TrieNode('-');
    return 0;
}