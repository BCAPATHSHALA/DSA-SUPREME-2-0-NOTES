// ✅MCQs on pointers practice

#include<iostream>
using namespace std;

// ✅MCQ 01: What will be the output ?
int main(){
    float f= 10.5;
    float p= 2.5;
    float* ptr = &f;
    (*ptr) ++;
    *ptr = p;
    cout << *ptr << " " << f <<" "<< P;
    return 0;
}

// ✅MCQ 02: What will be the output ?
int main(){
    int a = 7;
    int b = 17;
    int *c = &b;
    *c = 7;
    cout << a << " " << b << endl;
    return 0;
}

// ✅MCQ 03: What will be the output ?
int main(){
    int *ptr = 0;
    int a = 10;
    *ptr = a;
    cout << *ptr << endl;
    return 0;
}

// ✅MCQ 04: Which of the following gives the memory address of variable 'b' pointed by pointer 'a' i.e.
int main(){
    int b = 10;
    int *a = &b;
    return 0;
}

// ✅MCQ 05: What will be the output ?
int main(){ 
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl;
    return 0;
}

// ✅MCQ 06: What will be the output ?
int main(){ 
    int a = 7;
    int *c = &a;
    c = c + 1;
    cout << a << " " << *c << endl;
    return 0;
}

// ✅MCQ 07: Assume the memory address of variable 'a' is 400 (and an integer takes 4 bytes), what will be the output -
int main(){ 
    int a = 7;
    int *c = &a;
    c = c + 3;
    cout<<c<< endl;
    return 0;
}

// ✅MCQ 08: Assume memory address of variable 'a' is: 200 and a double variable is of size 8 bytes, what will be the output -
int main(){     
    double a = 10.54;
    double *d = &a;
    d = d + 1;
    cout << d << endl;
    return 0;
}

// ✅MCQ 09: Assume integer takes 4 bytes and integer pointer 8 bytes, what will be the output -
int main(){     
    int a[5];
    int *c;
    cout<< sizeof(a) << " " << sizeof(c) << endl;
    return 0;
}

// ✅MCQ 10: what will be the output?
int main(){     
    int a[] = {1, 2, 3, 4};
    cout << *(a) << " " << *(a+1);
    return 0;
}

// ✅MCQ 11: Assume that address of Oth index of array 'a' is : 200. What is the output - 
int main(){     
    int a[3] = {1, 2, 3};
    cout << *(a + 2);
    return 0;
}

// ✅MCQ 12: what will be the output?
int main(){     
    int a[] = {1, 2, 3, 4};
    int *p = a++;
    cout << *p << endl;
    return 0;
}

// ✅MCQ 13: what will be the output?
int main(){
    int arr[] = {4, 5, 6, 7};
    int *p = (arr + 1);
    cout << *arr + 9;
    return 0;
}

// ✅MCQ 14: Assume address of 0th index of array 'b' is 200. What is the output -
int main(){
    char b[] = "xyz";
    char *c = &b [0];
    cout << c << endl;
    return 0;
}

// ✅MCQ 15: what will be the output?
int main(){
    char s[]= "hello";
    char *p = s;
    cout << s [0] << " "<< p[0];
    return 0;
}

// ✅MCQ 16: what will be the output?
int main(){
    char arr [20];
    int i;
    for (i = 0; i<10; i++) {
        *(arr + i) = 65 + i;
    }
    *(arr + i) = '\0';
    cout << arr;
    return 0;
}

// ✅MCQ 17: what will be the output?
int main(){
    char *ptr;
    char Str[] = "abcdefg";
    ptr = Str;
    ptr += 5;
    cout << ptr;
    return 0;
}

// ✅MCQ 18: what will be the output?
int main(){
    int numbers[5];
    int *p;
    p = numbers;
    *p = 10;
    p = &numbers[2];
    *p = 20;
    p--;
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p+4) = 50;
    for (int n=0; n<5; n++) {
        cout << numbers[n] << ",";
    }
    return 0;
}

// ✅MCQ 19: what will be the output?
int main(){
    char st[] = "ABCD";
    for (int i = 0; st[i] != '\0'; i++) {
        cout<< st[i] << *(st) + i << *(i+st) << i[st];
    }
    return 0;
}

// ✅MCQ 20: what will be the output?
int main(){
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    cout<< *ptr2 <<" ";
    cout<< ptr2 - ptr1;
    return 0;
}

// ✅MCQ 21: what will be the output?
void changeSign(int *p){
    *p = (*p) * -1;
}
int main(){
    int a = 10;
    changeSign(&a)
    cout << a << endl;
    return 0;
}

// ✅MCQ 22: what will be the output?
void fun(int a[]){
    cout << a[0] << endl;
}
int main(){
    int a[] = {1, 2, 3, 4};
    fun(a + 1)
    cout << a[0] << endl;
    return 0;
}

// ✅MCQ 23: what will be the output?
void square(int *p){
    int a = 10;
    p = &a;
    *p = (*p) * (*p);
}
int main() {
    int a = 10;
    square(&a);
    cout << a << endl;
    return 0;
}

// ✅MCQ 24: what will be the output?
void Q(int z){
    z += z;
    cout<< z << " ";
}
void P(int *y){
    int x = *y + 2;
    Q(x);
    *y = x - 1;
    cout<< x <<" ";
}
int main(){
    int x = 5;
    P(&x);
    cout<<x;
    return 0;
}

// ✅MCQ 25: what will be the output?
int main(){
    int a = 10;
    int *p = &a;
    int **q = &p;
    int b = 20;
    *q = &b;
    (*p)++;
    cout << a << " "<< b << endl;
}

// ✅MCQ 26: what will be the output?
int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}
int main() {
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    cout << f(c, b, a);
    return 0;
}

// ✅MCQ 27: what will be the output?
int main(){
    int ***r, **q, *p, i = 8;
    p = &i;
    (*p)++;
    q = &p;
    (**q)++;
    r = &q;
    cout<< *p << " " <<**q << " " <<***r;
    return 0;
}

// ✅MCQ 28: what will be the output?
void increment(int **p) {
    (**p)++;
}
int main() {
    int num= 10;
    int *ptr = &num;
    increment (&ptr);
    cout << num << endl;
    return 0;
}