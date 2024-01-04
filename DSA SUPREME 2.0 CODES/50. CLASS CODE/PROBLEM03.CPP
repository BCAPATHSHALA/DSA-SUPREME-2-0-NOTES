// 3. Longest Common Prefix (Leetcode-14)

/*
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/


class TrieNode
{
    public:
        char value;
        bool isTerminal;
        TrieNode* children[26];
        int childCount;

        TrieNode(char value){
            this->value = value;
            this->isTerminal = false;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            this->childCount = 0;
        }
};

class Solution {
public:
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
            root->childCount++;
        }

        // Baki ka recursion solve kar lega
        insertWord(childNode, word.substr(1));
    }

    void findLCP(string &ans, TrieNode* root){
        // Base case
        if(root->isTerminal == true){
            return;
        }

        // Abhi me root par hi khada hu
        TrieNode* childNode;
        if(root->childCount == 1){
            // Child Tak Jaaooo
            for(int i=0; i<26; i++){
                if(root->children[i] != NULL){
                    // Mujhe child Node Mil Gya
                    childNode = root->children[i];
                }
            }
            // store child node value into ans 
            ans.push_back(childNode->value);
        }
        else{
            return;
        }

        // Ab me child Node par khda hu
        // ab recursion solve kar lega
        findLCP(ans, childNode);
    }

    string longestCommonPrefix(vector<string>& strs) {
        // create root
        TrieNode* root = new TrieNode('_');

        // Insert All Strings
        for(auto str: strs){
            insertWord(root, str);
        }

        string ans = "";
        findLCP(ans, root);
        return ans;
    }
};