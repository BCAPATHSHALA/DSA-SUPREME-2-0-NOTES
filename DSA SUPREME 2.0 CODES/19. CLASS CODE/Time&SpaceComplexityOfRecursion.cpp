// ✅What is time complexity:
// Time is taken by any algorithm with respect to a function of its input N.

// ✅Binary Search RE
int BS(int arr[], int k, int start, int end){
    // Base Case
    if(start > end){
        return -1;
    }

    int mid = start + (end - start)/2;
    if(arr[mid] == k){
        return mid;
    }
    else if(arr[mid] < k){
        return BS(arr, k, mid + 1, end);
    }
    else{
        return BS(arr, k, start, mid - 1);
    }
}


// ✅Febonacci series RE
int fib(int N){
    //Base Case
    if(N==0 || N==1){
        return N;
    }

    return fib(N-1) + fib(N-2);
}