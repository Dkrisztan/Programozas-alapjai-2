/**
 * HeteroStore class
 */

#ifndef HETEROSTORE_HPP
#define HETEROSTORE_HPP

#include <iostream>
#include <stdexcept>

template <typename T, size_t s = 100, typename e = std::out_of_range> 
class HeteroStore {
  size_t n; 
  T* data[s];
public:
  HeteroStore() :n(0) { }
  
  size_t size() { return n; }
  size_t capacity() { return s; }

  void add(T* p) {
    if(n < s) {
      data[n++] = p;
    } else {
      delete p;
      throw e("Mar nem fer be");
    }
  }

  template <typename F>
  void traverse(F func) {
    for (size_t i = 0; i < n; i++) {
      func(data[i]);
    }
  }

  void clear() {
    for(size_t i = 0; i < n; i++) {
      delete data[i];
    }
    n = 0;
  }

  ~HeteroStore() { this->clear(); }

};


#endif