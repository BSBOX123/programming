#include<iostream>
#include<string>

using namespace std;

class Stack {
  int size;
  int* data;
  int tos;
public:
  Stack(int size = 10);
  ~Stack();
  Stack& operator<<(int n);
  Stack& operator>>(int& n);
  bool operator!();
};

Stack::Stack(int size) {
  this->size = size;
  data = new int[size];
  tos = 0;
}
Stack::~Stack() {
  if(data)
    delete[] data;
}

//push, <<
Stack& Stack::operator<<(int n) {
  //stack full?
  if(tos == size) {
    return *this;
  }
  data[tos++] = n;
  return *this;
}
//pop, >>
Stack& Stack::operator>>(int& n) {
  // stack empty?
  if(tos == 0)
    return *this;
  n = data[--tos];
  return *this;
}
// not
bool Stack::operator!() {
  if(tos == 0) 
    return true;
  else 
    return false;
}

int main() {
  Stack stack; // 생성자에 인자를 주면 그 크기의 스택을 만들고 없을 경우 기본 크기는 10
  stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시
  while(true) {
    if(!stack) break; // 스택 empty
    int x;
    stack >> x; // 스택의 탑에 있는 정수 팝
    cout << x << ' ';
  }
  cout << endl;
  Stack myStack(3);
  myStack << 1 << 3 << 5 << 7 << 9;
  int a,b,c,d;
  myStack >> a >> b >> c >> d;
  cout << a << "," << b << "," << c << "," << d << endl;
}