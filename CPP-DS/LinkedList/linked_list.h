#ifndef LINK_LIST_H_
#define LINK_LIST_H_

#include "node.h"


template<typename T>
class LinkedList {
 public:
  LinkedList();
  ~LinkedList();
  const int Size();
  bool Empty();
  const T& ValueAt(int index);
  void PushFront(const T item);
  void PrintList();
  const T PopFront();
  void PushBack(const T item);
  const T PopBack();
 private:
  Node<T> *head_;

};


#endif //LINK_LIST_H_
