// 1. Print All Words of Given Prefix String - I

/*
ALGORITHM:
Step 1: traverse to the last character of input string
Step 2: find all solution below the last character of input string
*/

/*
TRIE WORD: 
"CCNA", "CCNOP", "CODE", "CARE", "RAANA", "RO", "ROW"
.....................................................
Example 1:
Input: inputStr = "CC" 
Output: ["CCNA", "CCNOP"]

Example 2:
Input: inputStr = "R" 
Output: ["RAANA", "RO", "ROW"]

Example 3:
Input: inputStr = "C" 
Output: ["CCNA", "CCNOP", "CODE", "CARE"]

Example 4:
Input: inputStr = "B" 
Output: []
*/

#include<iostream>
#include<vector>
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

// Print All Words of Given Prefix String - I

// Step 2: find all solution below the last character of input string
void storeWord(TrieNode* root, vector<string> &ans, string &inputStr, string &prefixStr){
    // Base case
    if(root->isTerminal == true){
        // store ans
        ans.push_back(prefixStr + inputStr);

        // return nhi karna hai kyunki ho skta hai ki 
        // isTerminal ke bad koi or bhi character ho
    }

    for(char ch = 'a'; ch < 'z'; ch++){
        int index = ch - 'a';
        TrieNode* next = root->children[index];

        if(next != NULL){
            // Child exist karta hai
            inputStr.push_back(ch);
            // ab recursion solve kar lega
            storeWord(next, ans, inputStr, prefixStr);
            // Backtrack
            inputStr.pop_back();
        }
    }
}

// Step 1: traverse to the last character of input string
void findPrefix(TrieNode* root, vector<string> &ans, string inputStr, string prefixStr){
    // Base case
    if(inputStr.length() == 0){
        TrieNode* lastChar = root;

        // Step 2: find all solution below the last character of input string
        storeWord(lastChar, ans, inputStr, prefixStr);

        return;
    }

    // 1 case hum solve kar lenge
    char ch = inputStr[0];
    int index = ch - 'a';
    TrieNode* childNode;

    if(root->children[index] != NULL){
        // Present hai-> Travese the root copy childNode
        childNode = root->children[index];
    }
    else{
        // Absent hai-> Yanhi se bapas chle jaoo
        return;
    }

    // Ab recursion solve kar lega
    findPrefix(childNode, ans, inputStr.substr(1), prefixStr);
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
    insertWord(root, "ccna");
    insertWord(root, "ccnop");
    
    string inputStr = "c";
    string prefixStr = inputStr;
    vector<string> ans;
    findPrefix(root, ans, inputStr, prefixStr);

    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}