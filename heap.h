#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;


  void print(); 

private:

  int m_; 
  PComparator c_; 
  /// Add whatever helper functions and data members you need below
  std::vector<T> data; 
  void heapify(int loc); 
  void swap(int loc1, int loc2); 
  void TrickleUp(int loc);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), c_(c) {} 


template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap!"); 

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0]; 
}

// derived from class slides 
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  data.push_back(item);
  TrickleUp(data.size() - 1); 
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return data.size(); 
}

// derived from class slides 
template <typename T, typename PComparator>
void Heap<T,PComparator>::TrickleUp(int loc ) {
  int parent = (loc - 1) / 2; 
  if (loc == 0) {return;}
  while (parent >= 0 && ( c_(data[loc], data[parent]) ) ){
    swap (loc, parent);
    loc = parent; 
    parent = (loc-1)/2 ;
  }
}

template <typename T, typename PComparator>
// returns true if heap is empty 
bool Heap<T,PComparator>::empty() const{
  return (data.size() == 0); 
}



// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap!"); 
  }

  data[0] = data.back();
  data.pop_back(); 
  heapify(0); 

}

// derived from class slides  and my class ntoes 
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int loc){

  if (loc == data.size() - 1) {return;}
  int smaller = 2*loc + 1; 
  if (data.size() -1  < smaller) {return; }
  // if right child exists 
  if (data.size() - 1 >= 2*loc + 2 ) {
    int right = 2*loc + 2; 
    if ( c_(data[right], data[smaller]) ) {
      smaller = right; 
    }
  }

  if ( c_(data[loc], data[smaller]) == false  ) {

    swap(loc, smaller); 
    heapify(smaller); 

  }
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(int loc1, int loc2){

  T temp = data[loc1]; 
  data[loc1] = data[loc2]; 
  data[loc2] = temp; 
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::print() {

  for (size_t i = 0; i < heap.size() - 1; i++){
    std::cout << data[i] << " "; 
  }
}


#endif
