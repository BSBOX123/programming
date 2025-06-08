#include "GraphicEditor.h"
#include "UI.h"
#include "Rect.h"
#include "Line.h"
#include "Circle.h"

GraphicEditor::GraphicEditor() {
  pStart = nullptr;
  pLast = nullptr;
}
GraphicEditor::~GraphicEditor() {
  Shape* p = pStart;
  while( p != nullptr ) {
    Shape* next = p->getNext();
    delete p;
    p = next;
  }
}
void GraphicEditor::edit() {
  int shapeType = UI::getShapeType();
  switch (shapeType)
  {
  case LINE:
    add(new Line()); break;
  case RECT:
    add(new Rect()); break;
  case CIRCLE:
    add(new Circle()); break;
  default:
    UI::println("도형 선택 오류");
  }
}
void GraphicEditor::add(Shape* p) {
  if(pStart == nullptr) {
    pStart = p;
    pLast = p;
  }
  else {
    pLast->add(p);
    pLast = p;
  }
}
void GraphicEditor::remove() {
  int shapeIndex = UI::getShapeIndex();
  remove(shapeIndex);
}
void GraphicEditor::remove(int shapeIndex) {
  if(pLast == nullptr) {
    UI::println("도형없음");
    return;
  }// 도형이 없음
  int i = 0;
  Shape* p = pStart;
  Shape* beforeP = pStart;

  while (i < shapeIndex){
    i++;
    beforeP = p;
    p = p->getNext();
    if( p == nullptr ) {
      UI::println("인덱스 오류");
      return;
    }
  }
  Shape* pNext = beforeP->add(p->getNext());
  delete p;
  //삭제한 도형이 첫 도형인 경우
  if(p == pStart) {
    pStart = pNext;
  }
  //삭제한 도형이 마지막 도형인 경우
  if(p==pLast) {
    //처음이자 마지막인 경우
      if(pStart == nullptr) {
        pLast = nullptr;
      } else {
        pLast = beforeP;
      }
  }

  void GraphicEditor::paint() {
    Shape* p = pStart;
    if (p == nullptr) {
      UI::println("도형이 없음");
      return;
    } 
    int i = 0;
    while (p != nullptr) 
    {
      UI::print(i);
      UI::print(" : ");
      p->paint();
      p = p->getNext();
      i++;
    }
  }

  void GraphicEditor::run() {
    UI::println("그래픽에디터");
    while (true) {
      int menu = UI::getMainMenu();
      switch (menu)
      {
      case EDIT:
        edit();
        break;
      
      case REMOVE:
        remove();
        break;
        
      case PAINT:
        paint();
        break;

      case EXIT:
        return;
      
      default:
        UI::println("메뉴 입력 오류");
      }
    }
  }
}