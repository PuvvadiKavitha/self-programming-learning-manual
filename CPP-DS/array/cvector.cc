#include "cvector.h"

#include <memory>

namespace cspace {

CVector::CVector(int capacity) : size_(0) {
  int really_capacity = DetermineCapacity(capacity);

  capacity_ = really_capacity;
  data_ = std::unique_ptr<int[]>(new int[really_capacity]);
}


CVector::~CVector() {


}


int CVector::DetermineCapacity(int capacity) {
 if (capacity < kMinInitCapacity) {
   exit(EXIT_FAILURE);
 } else if (capacity < kMinCapacity) {
   return kMinCapacity;
 } else {
   int really_capacity = kMinInitCapacity;
   
   while (really_capacity < capacity)
	   really_capacity *= kGrowthFactory;
   
   return really_capacity;
 }
}


void CVector::PrintVector() const {
  std::cout << "size = " << size_ << std::endl;
  std::cout << "capacity = " << capacity_ << std::endl;
  std::cout << "data: ";
  for (int i = 0; i < size_; i++)
	  std::cout << data_[i] << " ";
  std::cout << std::endl;
}


int CVector::size() const {
  return size_;
}

int CVector::capacity() const {
  return capacity_;
}

bool CVector::IsEmpty() const {
  return !size();
}

int CVector::At(int index) const {
  if ((index < 0) || (index > (size() - 1)))
	  exit(EXIT_FAILURE);

  return data_[index];
}

void CVector::Push(int item) {
  data_[size()] = item;
  size_++;
}







}
