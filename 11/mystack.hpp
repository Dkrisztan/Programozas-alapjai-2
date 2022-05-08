#include "vektor.hpp"
#include <vector>

template <class T, class Container = std::vector<T>> 
class MyStack {
  Container data;
public:
  bool empty() const { 
    return data.size() == 0; 
  }

  T& top() {
    if (empty()) throw std::out_of_range("MyStack.top(): empty");
    return data.back();
  }

  void push(const T& t) {
    data.push_back(t);
  }

  void pop() {
    if (empty()) throw std::out_of_range("MyStack.pop(): empty");
    data.pop_back();
  }
};