#include <iostream>
#include <fstream>
#include <functional>
#include <cstdlib> 
#include "heap.h"
using namespace std; 

int main () {

    srand(time(nullptr)); 

    Heap<int> h1; 

    for (int i = 0; i < 10; i++){
        int num = rand () % 100; 
        cout << num << " "; 
        h1.push(num); 
    }

    cout << endl;
    h1.print(); 
    
    h1.pop(); 
    cout << endl;

    cout << "heap" << endl; 
    h1.print(); 
    return 0; 
}