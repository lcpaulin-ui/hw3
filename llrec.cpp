#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void addNode(Node*& add, Node*& list){ 

    // empty list case 
    if (list == nullptr){
      list = add;
      list->next = nullptr; 
    }
  
    // got to the end case 
    else if (list->next == nullptr){
      list->next = add;
      add->next = nullptr;
      return; 
    }
  
    else {
      addNode(add, list->next);
    }
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

  /* Add code here */
  // WRITE YOUR CODE HERE 
  // empty case
  if (head == nullptr){
    return;
  }

  // take my ptr out of og list aka move head ptr to next pointer 
  Node* curr = head;
  head = head->next; 

  if (curr->val > pivot){
    addNode(curr, larger);
  }
  else {
    addNode(curr, smaller);
  }

  return llpivot(head, smaller, larger, pivot);

}