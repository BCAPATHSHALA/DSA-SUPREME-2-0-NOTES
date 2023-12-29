// 3. Implement C++ STL Unordered Map
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    // Creation of unsorted map
    unordered_map<string, int> umapping;

    // Creation of pairs to map
    pair<string, int> p = make_pair("Umesh", 25);
    pair<string,int> q("Utkars", 24);
    pair<string,int> r;
    r.first = "Aman";
    r.second = 23;

    // Insertion of pairs into map
    umapping.insert(p);
    umapping.insert(q);
    umapping.insert(r);
    umapping["Samar"] = 22;

    // Size of map
    cout << "Map size: " << umapping.size() << endl;

    // Access value of key using at(key) method and square bracket[key]
    cout << "Value of Umesh: " << umapping.at("Umesh") << endl;
    cout << "Value of Umesh: " << umapping["Umesh"] << endl;

    // Way 1: Searching of key using count(key) method: 
    // return 1 when key is found and return -1 when key is not found.
    cout << "Umesh is present: " << umapping.count("Umesh") << endl;
    
    // Way 2: Searching of key using find(key) method: 
    if(umapping.find("Umesh") != umapping.end()){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    
    // Note 1: Jab hum "Using [key]" koi aise key value ko access karte hai jo 
    // actual me map ke andar hai hi nhi hai to uss case me ek new entry create 
    // ho jati hai jo 0 se belong karti hai like
    cout << "Temp is present: " << umapping["Temp"] << endl;
    cout << "Map size: " << umapping.size() << endl;

    return 0;
}

/*
Map size: 4
Value of Umesh: 25
Value of Umesh: 25
Umesh is present: 1
Found
Temp is present: 0
Map size: 5
*/