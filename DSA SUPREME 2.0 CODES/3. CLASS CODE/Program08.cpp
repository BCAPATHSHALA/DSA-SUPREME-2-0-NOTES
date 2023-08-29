// Check valid triangle or not
#include<iostream>
using namespace std;

int main(){
    int a,b,c;

    cout << "Enter side a = ";
    cin >> a;
    cout << "Enter side b = ";
    cin >> b;
    cout << "Enter side c = ";
    cin >> c;

    if(a+b > c && a+c > b && b+c > a){
        cout << "Valid triangle" << endl;
    }
    else{
        cout << "Invalid triangle" << endl;
    }
    return 0;
}

/*
OUTPUT:
Enter side a = 3
Enter side b = 4
Enter side c = 5
Valid triangle

Enter side a = 0
Enter side b = 2
Enter side c = 1
Invalid triangle
*/