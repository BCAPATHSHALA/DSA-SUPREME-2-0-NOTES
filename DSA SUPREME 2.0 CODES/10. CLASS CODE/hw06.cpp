// HW 06: Common Element in 3 Sorted Array (GFG)
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> ans;
            set<int> st;
            int i=0,j=0,k=0;
            
            while(i<n1 && j<n2 && k<n3){
                if(A[i]==B[j] && B[j]==C[k] && C[k]==A[i]){
                    st.insert(A[i]);
                    i++, j++, k++;
                }
                else if(A[i]<B[j]){
                    i++;
                }
                else if(B[j]<C[k]){
                    j++;
                }
                else{
                    k++;
                }
            }
            
            for(auto i: st){
                ans.push_back(i);
            }
            
            return ans;
        }

};

/*
Example 01:
Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80

Example 02:
Input:
n1 = 3; A = {3, 3, 3}
n2 = 3; B = {3, 3, 3}
n3 = 3; C = {3, 3, 3}
Output: 3
*/