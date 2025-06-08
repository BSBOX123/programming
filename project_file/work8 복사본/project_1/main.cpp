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

class MyQueue : public BaseArray {
  int head; // 새로운 값이 들어갈 위치
  int tail; // 값을 가져올 위치
  int size; 
public:
  MyQueue(int capacity);
  void enqueue(int n);
  int dequeue();
  int length();
  int capacity();
};

MyQueue::MyQueue(int capacity) : BaseArray(capacity) {
  head = 0; // 새로운 값이 들어갈 위치
  tail = -1;// 값을 가져올 위치
  size = 0;
}
void MyQueue::enqueue(int n) {
  //quene full?
  if(size == capacity())
    return;
  put(head++, n);
  size++;
  head = head % capacity();
}
  
int MyQueue::dequeue() {
  //queue empty
  if (size == 0) return -1;
  size--;
  tail++;
  tail = tail % capacity();
  return get(tail);
}
  
int MyQueue::capacity() {
  return getCapacity();
}
int MyQueue::length() {
  return size;
}

int main() {
  MyQueue mQ(100);
  int n;
  
  cout << "큐에 삽입할 5개의 정수를 입력하라>> ";

  for(int i=0; i<5; i++) {
    cin >> n;
    mQ.enqueue(n); // 큐에 삽입
  }

  cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
  cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";

  while(mQ.length() != 0) {
    cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
  }

  cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}