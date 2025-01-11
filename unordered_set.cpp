#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main(){
    unordered_set<string> stringSet;

    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("C++");
    stringSet.insert("is");
    stringSet.insert("fast");

    string key = "slow";

    if(stringSet.find(key) == stringSet.end())
        cout << key << " not found" << endl << endl;
    else 
        cout << "Found " << key << endl;

    key = "c++";
    if(stringSet.find(key) == stringSet.end())
        cout << key << " not found" << endl << endl;
    else 
        cout << "Found " << key << endl;
}