#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 3, 6, 2, 9};

    // Search an element 6
    auto it = find(v.begin(), v.end(), 6);

    // Print index
    cout << it
  
    return 0;
}