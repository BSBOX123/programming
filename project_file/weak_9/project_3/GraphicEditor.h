#pragma once
#include<iostream>
#include "Shape.h"

using namespace std;

class GraphicEditor {
  enum {LINE=1, CIRCLE=2, RECT=3};
  enum {EDIT=1, REMOVE=2, PAINT=3, EXIT=4};

  Shape* pStart;
  Shape* pLast;

  void add(Shape* p);

protected:
  void paint(); //모두보기
  void edit(); //삽입
  void remove(); // 삭제
  void remove(int shapeIndex);

public:
  GraphicEditor();
  ~GraphicEditor();
  void run();
};