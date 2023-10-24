// 📂 Padding Concept

/*
1. What is the empty class size?
Ans: Size 1 byte (This is smallest addressable size)
Lekin 1 byte kyun hota hai? 
Ans: Compiler assigns 1 byte size for an empty class because of isse class ki existence pta chalti hai ki ek empty class bnayi gy hai.
lets assume empty class ka size agar 0 hota to iska mtlb simple hai ki koi bhi class bnayi hi nhi gayi hai.

2. What is the non empty class size?
We can find non empty class size using padding concept and
padding concept follows some rules to find the size of non empty class
Step 01: Select biggest data type size
Step 02: Align sum of data types in the boundary of biggest data type size
Note: When we find the size of non empty class, then sabse pahle bade data type size ke nearest multiple memory par le aao
*/

#include<iostream>
using namespace std;

// Non Empty Class
class Student
{
    int a;
    int b;
    bool;
};

int main(){

    cout<< sizeof(Student) << endl;
    return 0;
}