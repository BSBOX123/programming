#include "UI.h"

int UI::getMainMenu() {
  cout << "삽입:1, 삭제:2, 모두보기:3, 삭제:4>>";
  int menu;
  cin >> menu;
  return menu;
}
int UI::getShapeType() {
  cout << "선:1, 원:2, 사각형:3>>";
  int shapeType;
  return shapeType;
}
int UI::getShapeIndex() {
  cout<< "삭제할 도형 인덱스";
  int shapeIndex;
  cin >> shapeIndex;
  return shapeIndex;
}
void UI::println(string msg) {
  cout << msg << endl;
}
void UI::print(string msg) {
  cout << msg;
}
void UI::print(int msg) {
  cout << msg;
}