#include<iostream>

using namespace std;

class Rect;

class RectManager {

};

class Rect {
  int w, h;
public:
  Rect(int w, int h) : w(w), h(h) {}
  Rect operator+ (Rect); // +연산 내부연산
  Rect& operator++(); // 전위연산자 ++ 중복
  Rect operator++(int x); // 후위연산자 ++ 중복  
  friend bool operator==(Rect op1, Rect op2); //외부 함수를 통한 연산자 구현 -> friend를 이용하여 private 멤버변수 접근
  //friend Rect operator+(Rect op1, Rect op2); // -> 같은 + 연산자를 외부로 중복 구현
  void show();
};

//외부 연산자와 내부 연산자, 둘 다 만들게 되면 서로 우선 순위가 없기때문에 오류가 발생한다.
/*Rect operator+(Rect op1, Rect op2) {
  Rect tmp(op1.w + op2.w, op1.h + op2.h);
  return tmp;
}*/

//전위연산자
Rect& Rect::operator++() {
  w++;
  h++;
  return *this;
}
//후위 연산자
Rect Rect::operator++(int x) {
  Rect tmp = *this;
  w++;
  h++;
  return tmp;
}

void Rect::show() {
  cout << "W: " << w << ", h: " << h << endl;
}

//+연산자 내부 구현
Rect Rect::operator+(Rect op2) {
  Rect tmp(0,0);
  tmp.w = w + op2.w;
  tmp.h = h + op2.h;
  return tmp;
}

bool operator==(Rect op1, Rect op2) {
  if(op1.w == op2.w && op1.h == op2.h) {
    return true;
  } else return false;
}

int main() {
  Rect a(3,4), b(4,5), c(3,4), d(0,0);
  d = a + b;
  d.show();

  if(a==c) {
    cout << "equal" << endl;
  } else {
    cout << "not equal" << endl;
    d = b++; // 후위 연산 : d = b.++(0);
    d.show();
    d = ++b; // 전위 연산 // d = b. ++();
    d.show();
    b.show();
  }
}