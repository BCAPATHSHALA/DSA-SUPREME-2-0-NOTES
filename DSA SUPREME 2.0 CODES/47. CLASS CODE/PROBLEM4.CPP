// PROBLEM 4: Median in a Stream (CodingNinjas)

/*
Time complexity: O(N*Log N)
Space complexity: O(N), Where heap takes space O(N)
Where N is number of elements of input array
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void solveForMedian(int &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element){

    if(maxHeap.size() == minHeap.size()){
        if(element > median){
            minHeap.push(element);
            // ab size maxHeap and minHeap ka not equal hoga
            median = minHeap.top();
        }
        else{
            maxHeap.push(element);
            // ab size maxHeap and minHeap ka not equal hoga
            median = maxHeap.top();
        }
    }
    else if(maxHeap.size() == minHeap.size()+1){
        if(element > median){
            minHeap.push(element);
        }
        else{
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
        }
        // ab size maxHeap and minHeap ka equal hoga
        median = (maxHeap.top() + minHeap.top())/2;
    }
    else if(minHeap.size() == maxHeap.size()+1){
        if(element > median){
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
        }
        else{
            maxHeap.push(element);
        }
        // ab size maxHeap and minHeap ka equal hoga
        median = (maxHeap.top() + minHeap.top())/2;
    }
}

int main(){
    int arr[] = {12, 10, 8, 4, 2, 3, 15};
    int n = 7;

    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++){
        int element = arr[i];
        solveForMedian(median, maxHeap, minHeap, element);
        cout << "Median foud: " << median << endl;
    }

    return 0;
}

/*
OUTPUT:
Median foud: 12
Median foud: 11
Median foud: 10
Median foud: 9
Median foud: 8
Median foud: 6
Median foud: 8
*/



// USING SWITCH CASE
// PROBLEM 4: Median in a Stream (CodingNinjas)

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void solveForMedian(int &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element) {
    int sizeDiff = maxHeap.size() - minHeap.size();
    
    switch (sizeDiff) {
        case 0:
            if (element > median) {
                minHeap.push(element);
                median = minHeap.top();
            } else {
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;

        case 1:
            if (element > median) {
                minHeap.push(element);
            } else {
                int maxTop = maxHeap.top();
                maxHeap.pop();
                minHeap.push(maxTop);
                maxHeap.push(element);
            }
            median = (maxHeap.top() + minHeap.top()) / 2;
            break;

        case -1:
            if (element > median) {
                int minTop = minHeap.top();
                minHeap.pop();
                maxHeap.push(minTop);
                minHeap.push(element);
            } else {
                maxHeap.push(element);
            }
            median = (maxHeap.top() + minHeap.top()) / 2;
            break;
    }
}


int main(){
    int arr[] = {12, 10, 8, 4, 2, 3, 15};
    int n = 7;

    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++){
        int element = arr[i];
        solveForMedian(median, maxHeap, minHeap, element);
        cout << "Median foud: " << median << endl;
    }

    return 0;
}