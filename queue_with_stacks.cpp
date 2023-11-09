// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <cassert>
#include <stack>
#include <iostream>

using namespace std;

/************** begin assignment **************/
// Queue insertion and deletion follows first-in, first-out semantics; stack
// insertion and deletion is last-in, first-out. How would you implement a queue
// with the help of two stacks?
//
// Of course, implementing a queue with stacks is not efficient, but it is a
// good exercise to get familiar with data structures and templates ;).
// When coding in real life use the C++ queue implementation:
// https://www.geeksforgeeks.org/queue-cpp-stl/
// Or if a problem requires it, use the priority queue implementation of std:
// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

// simple queue implementation with two stacks
template <typename T> class Queue {
private:
  // these are the only class variables you need to implement the queue.
  stack<T> enq, deq;

public:

  void enqueue(T x) {
       while(!deq.empty())
       {
        enq.push(deq.top());
        deq.pop();
       }
       deq.push(x);
       while(!enq.empty())
       {
       deq.push(enq.top());
       enq.pop();
       }
  }


  T dequeue() {
    T t = deq.top();
    deq.pop();
    return t;
  }

  // convenience functions
  // TODO: implement size
  size_t size() { return deq.size(); }
  // TODO: implement empty
  bool empty() { return (deq.size()==0); }
};
/*************** end assignment ***************/

int main() {
  {
    Queue<int> my_queue;
    assert(my_queue.size() == 0);
    assert(my_queue.empty());
    my_queue.enqueue(1);
    my_queue.enqueue(2);
    my_queue.enqueue(3);
    assert(my_queue.size() == 3);
    assert(!my_queue.empty());
    assert(my_queue.dequeue() == 1);
    assert(my_queue.dequeue() == 2);
    my_queue.enqueue(7);
    assert(my_queue.size() == 2);
    assert(my_queue.dequeue() == 3);
    assert(my_queue.dequeue() == 7);
    assert(my_queue.size() == 0);
    assert(my_queue.empty());
  }
 
  cout << "all tests passed" << endl;
}
