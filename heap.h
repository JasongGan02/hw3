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
  Heap(int m=2, PComparator c = PComparator()) : m(m), c(c) {}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

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
  bool empty() const { return heap.empty(); }

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const { return heap.size(); }

private:
  std::vector<T> heap;
  int m;
  PComparator c;




};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Heap underflow");
  }
  return heap.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Heap underflow");
  }
  std::swap(heap[0], heap[heap.size()-1]);
  heap.pop_back();
  
  size_t parent = 0;
  size_t leftChild = m * parent + 1;
  while (leftChild < this->size())
  {
    size_t chosenChild = leftChild;
    for (size_t i = 1; i < m && leftChild + i < this->size(); ++i)
    {
      if (c(heap[leftChild + i], heap[chosenChild]))
      {
        chosenChild = leftChild + i;
      }
    }
    if (c(heap[chosenChild], heap[parent])) 
    {
      std::swap(heap[parent], heap[chosenChild]);
      parent = chosenChild; // Move down the tree.
      leftChild = m * parent + 1;
    } 
    else 
    {
      // The parent is smaller than all its children, so the heap property is satisfied.
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  heap.push_back(item);
  size_t curIndex = heap.size()-1;

  while (curIndex > 0)
  {
    size_t headIndex = (curIndex - 1) / m;  
    if (c(heap[curIndex], heap[headIndex]))
    {
      std::swap(heap[curIndex], heap[headIndex]);
      curIndex = headIndex;
    }
    else
    {
      break;
    }
  }
}



#endif

