// 2. Print All Words of Given Prefix String - II

/*
ALGORITHM:
Step 1: input string ke har ek character ko as a last character assume karlo
Step 2: find all solution below the last character of input string
*/

/*
TRIE WORDS: "CCNA", "CCNOP", "CODE", "CARE", "RAANA", "RO", "ROW"
..................................................................

Example 1:
Input: inputStr = "CC" 
Output: [["CCNA", "CCNOP", "CODE", "CARE"],["CCNA", "CCNOP"]]

Example 2:
Input: inputStr = "RO" 
Output: [["RAANA", "RO", "ROW"],["RO", "ROW"]]

Example 3:
Input: inputStr = "C" 
Output: [["CCNA", "CCNOP", "CODE", "CARE"]]

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

// Print All Words of Given Prefix String - II

// Step 2: find all solution below the last character of input string
void storeWord(TrieNode* root, vector<string> &ans, string &prefixStr){
    // Base case
    if(root->isTerminal == true){
        // store ans
        ans.push_back(prefixStr);

        // return nhi karna hai kyunki ho skta hai ki 
        // isTerminal ke bad koi or bhi character ho
    }

    for(char ch = 'a'; ch < 'z'; ch++){
        int index = ch - 'a';
        TrieNode* next = root->children[index];

        if(next != NULL){
            // Child exist karta hai
            prefixStr.push_back(ch);
            // ab recursion solve kar lega
            storeWord(next, ans, prefixStr);
            // Backtrack
            prefixStr.pop_back();
        }
    }
}

// Step 1: input string ke har ek character ko as a last character assume karlo
void findPrefix(TrieNode* root, vector<vector<string>> &ans, string inputStr){
    TrieNode* prev = root;
    string prefixStr = "";

    for (int i = 0; i < inputStr.length(); i++)
    {
        char lastChar = inputStr[0];
        int index = lastChar - 'a';
        TrieNode* curr = prev->children[index];

        if(curr == NULL){
            // Absent hai-> Loop se bahar ho jaao
            break;
        }
        else{
            // Present hai-> 
            // Step 2: find all solution below the last character of input string
            vector<string> nicheKaAns;
            prefixStr.push_back(lastChar);
            storeWord(curr, nicheKaAns, prefixStr);     
            // Store nicheKaAns
            ans.push_back(nicheKaAns);
            // Prev ko update krna hamesha bhool jata hu (IMPORTANT)
            prev = curr;       
        }
    }    
}



int main(){
    // Create Root Node
    TrieNode* root = new TrieNode('-');

    insertWord(root, "ccna");
    insertWord(root, "ccnop");
    insertWord(root, "code");
    insertWord(root, "care");
    insertWord(root, "raana");
    insertWord(root, "ro");
    insertWord(root, "row");
    
    string inputStr = "cc";
    vector<vector<string>> ans;
    findPrefix(root, ans, inputStr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << " -> ";
        for(auto str: ans[i]){
            cout << str << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
0 -> care ccna ccnop code 
1 -> ccna ccnop 
*/