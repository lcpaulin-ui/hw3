#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>
#include "llrec.h"
using namespace std;

Node* create_rand(Node*& head, int size); 
void dealloc(Node*& head); 
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot); 


int main () {

    Node* h = NULL; 
    h = create_rand(h, 10); 
    Node* smaller = NULL; 
    Node* larger = NULL;

    llpivot(h, smaller, larger, 15);

    Node* curr = smaller; 
    std::cout << "smaller list: " << std::endl; 
    while(curr != NULL){
        std::cout << curr->val << " "; 
        curr = curr->next; 
    }
    std::cout << endl;

    Node* sec_curr = larger; 
    std::cout << "larger list: " << std::endl; 
    while(sec_curr != NULL){
        std::cout << sec_curr->val << " "; 
        sec_curr = sec_curr->next; 
    }
    std::cout << endl; 

}



Node* create_rand (Node*& head, int size) {

    srand(time(nullptr)); 
    int val = rand() % 50; 
    head = new Node(val, NULL); 
    Node* curr = head; 
    for (int i = 0; i < size; i++){
        int val = rand() % 50; 
        std::cout << "added: " << val << " " << std::endl; 
       curr->next = new Node(val, NULL);
       curr = curr->next; 
    }

    return head; 
}

void dealloc(Node*& head) {

    if (head == NULL){
        return;
    }

    Node* curr = head; 
    while (curr != NULL){
        Node* temp = curr;
        curr = curr->next;
        delete temp; 
    }

}