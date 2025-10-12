#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void addNode(Node* add, Node*& list){ 

    // empty list case 
    if (list == NULL){
      list = add;
      list->next = NULL; 
    }
  
    // got to the end case 
    else if (list->next == NULL){
      list->next = add;
      add->next = NULL;
      return; 
    }
  
    else {
      addNode(add, list->next);
      return; 
    }
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

  /* Add code here */
  // WRITE YOUR CODE HERE 
  // empty case
  // smaller = nullptr, larger = nullptr;
  if (head == NULL){
    smaller = nullptr, larger = nullptr;
    return;
  }

  // take my ptr out of og list aka move head ptr to next pointer 
  Node* curr = head;
  head = head->next;
  curr->next = nullptr;  

  //llpivot(head, smaller, larger, pivot);
  llpivot(head, smaller, larger, pivot);

  if (curr->val > pivot){
    addNode(curr, larger);
  }
  else {
    addNode(curr, smaller);
  } 

}