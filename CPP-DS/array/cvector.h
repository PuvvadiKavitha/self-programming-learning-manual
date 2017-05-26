#ifndef C_VECTOR_H_
#define C_VECTOR_H_

#include <iostream>
#include <memory>

namespace cspace {

class CVector {
  public:
    CVector(int capacity);
	~CVector();
  public:
    void PrintVector() const;
    int size() const;
	int capacity() const;
	bool IsEmpty() const;
	int At(int index) const;
	void Push(int item);
  private:
    int DetermineCapacity(int capacity);
  private:
    int size_ { 0 };
    int capacity_ { 0 };
	std::unique_ptr<int[]> data_;
  private:
	static const int kMinInitCapacity = 1;
	static const int kMinCapacity = 16;
	static const int kGrowthFactory = 2;
	static const int kShrinkFactory = 4;
};

}



#endif //C_VECTOR_H_
