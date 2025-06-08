#include<iostream>
#include<string>
using namespace std;

class Point {
  int x,y;
public:
  Point(int x=0, int y=0) : x(x), y(y) {}
  void set(int x, int y);
  void showPoint();
};

void Point::set(int x, int y) {
  this->x = x;
  this->y = y;
}
void Point::showPoint() {
  cout << "(" << x << "," << y << ")" << endl;
}


class ColorPoint : public Point {
  string color;
public:
  void setColor(string color);
  void showColorPoint();
};

void ColorPoint::setColor(string color) {
  this->color = color;
}

void ColorPoint::showColorPoint() {
  showPoint();
  cout << color << endl;
}

int main() {
  Point a(10, 20);
  a.showPoint();
  ColorPoint c;
  c.set(20, 30);
  c.showPoint();
  c.setColor("빨간색");
  c.showColorPoint();

  ColorPoint* cp = &c;
  cp -> showColorPoint();
  Point* p = cp; // up casting
  p -> showPoint();
  p -> set(300, 400);
  //p -> showColorPoint(); <- 이건 안됨
  cp = (ColorPoint*)p; // down casting 
  cp -> set(123, 123);
  cp -> showPoint();
  cp -> setColor("파란색");
  cp -> showColorPoint();
}