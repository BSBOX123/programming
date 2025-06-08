#include<iostream>

using namespace std;

class BaseArray {
  private:
    int capacity; // 동적 할당된 메모리 용량
    int *mem;
  protected:
    BaseArray(int capacity=100) {
      this->capacity = capacity; mem = new int [capacity];
    }
    ~BaseArray() { delete [] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
  int tos;
public:
  MyStack(int capacity);
  int pop();
  void push(int n);
  int length();
  int capacity();
};

MyStack::MyStack(int capacity) : BaseArray(capacity) {
  tos = 0;
}
void MyStack::push(int n) {
  if(tos == capacity()) return;
  put(tos++, n);
}
int MyStack::pop() {
  if(tos==0) return -1;
  return get(--tos);
}
int MyStack::length() {
  return tos;
}
int MyStack::capacity() {
  return getCapacity();
}

int main() {
  MyStack mStack(100);
  int n;
  cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
  
  for(int i=0; i<5; i++) {
    cin >> n;
    mStack.push(n); // 스택에 푸시
  }

  cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
  cout << "스택의 모든 원소를 팝하여 출력한다>> ";

  while(mStack.length() != 0) {
    cout << mStack.pop() << ' '; // 스택에서 팝
  }

  cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}