#include<iostream>
using namespace std;

int main(){
    int n=6;
    int target=10;
    int arr[]={2,4,6,8,10,12};

    bool flag=false;

    for(int i=0; i<n; i++){
        if(target==arr[i]){
            flag=true;
            break;
        }
    }
    
    // Apply condition to print target is found or not
    if(flag==true){
        cout<<target<<" found";
    }else{
        cout<<target<<" not found";
    }
    return 0;
}

/*
OUTPUT:
10 found
*/