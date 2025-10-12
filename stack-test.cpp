#include "stack.h"
#include <iostream>
#include <cstdlib>  // for rand() and srand()
using namespace std;

int main (){
    srand(time(nullptr)); 
    Stack<int> s;

    // creating the list 
    for (size_t i = 0; i < 10; i++){
        s.push_back(rand() % i); 
    }
    s.push_back(10); 

    // checking empty function shoudl return false
    if (s.empty()){
        cout << "empty" << endl; 
    }
    else {
        cout << "not empty" << endl;
    }

    // checking top should be "10"
    cout << "checking top, should be 10" << endl;
    cout << s.top() << endl;

    cout << "checking size should be 11" << endl;
    cout << s.size() << endl; 


    cout << "checking pop should return 10 " << endl; 
    cout << s.top() << endl; 

    for (size_t i = 0; i < s.size(); i++){
        s.pop_back(); 
    }

    cout << "just deleted list, size should throw error" << endl;
    s.size();
    
    return 0; 
}
