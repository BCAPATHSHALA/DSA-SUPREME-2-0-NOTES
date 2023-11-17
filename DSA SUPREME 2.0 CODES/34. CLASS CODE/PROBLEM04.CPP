// 📂 Problem 4: Largest Rectangle Area in Histogram (Leectcode-84)

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>&arr){
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;
        st.push(-1);

        for(int i=size-1; i>=0; i--){
            int currElement = arr[i];

            // Find ans to currElement from stack
            while (st.top() != -1 && arr[st.top()] >= currElement)
            {
                st.pop();
            }

            // Ynha tak me tabhi pahuncha hoga jab st.top() < currElement
            ans[i] = st.top();
            st.push(i);        
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>&arr){
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;
        st.push(-1);

        for(int i=0; i<size; i++){
            int currElement = arr[i];

            // Find ans to currElement from stack
            while (st.top() != -1 && arr[st.top()] >= currElement)
            {
                st.pop();
            }

            // Ynha tak me tabhi pahuncha hoga jab st.top() < currElement
            ans[i] = st.top();
            st.push(i);        
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        // Step A: Next smaller element index
        vector<int> next = nextSmallerElement(heights);

        // Make sure karna ki next me koi bhi index -1 na ho
        // yadi hai to use next ke size se update kardo
        for(int i=0; i<next.size(); i++){
            if(next[i] == -1){
                next[i] = next.size();
            }
        }

        // Step B: Prev smaller element index
        vector<int> prev = prevSmallerElement(heights);

        // Now find the max area
        int maxArea = INT_MIN;

        for(int i=0; i<heights.size(); i++){
            // Step C: Find the width
            int height = heights[i];
            int width = next[i] - prev[i] - 1;
            int currArea = width * height;
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};