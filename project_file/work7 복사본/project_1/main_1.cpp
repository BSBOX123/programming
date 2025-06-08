#include<iostream>
#include<string>

using namespace std;

class Book {
  string title;
  int price;
  int pages;
public:
  Book(string title="", int price=0, int pages=0) {
    this->title = title; this->price = price; this->pages = pages;
  }
  void show() {
    cout << title << ' ' << price << "원 " <<pages << " 페이지" << endl;
  }

  //+=,-= 멤버 함수 구현
  //Book& operator+=(int op2);//연산자 중복
  //Book& operator-=(int op2);

  //+=,-= 외부 함수 구현을 위한 friend 선언
  friend Book& operator+=(Book& op1, int op2);
  friend Book& operator-=(Book& op1, int op2);



  //not 멤버 함수
  bool operator!();
  //friend bool operator!();




  // <연산자 멤버 함수
  //bool operator<(Book op2);

  // < 연산자 외부 함수
  friend bool operator<(string op1, Book& op2);



  string getTitle() { return title; }
};

/*
//+=, -= Book 멤버 함수 구현
Book& Book::operator+=(int op2) {
	price = price + op2; // 
	return *this; // 합한 결과 리턴
}
Book& Book::operator-=(int op2) {
	price = price - op2; // 
	return *this; // 합한 결과 리턴
} */

//+=, -= 외부 함수 구현
Book& operator+=(Book& op1, int op2) {
  op1.price += op2;
  return op1;
}
Book& operator-=(Book& op1, int op2) {
  op1.price -= op2;
  return op1;
}






//not 멤버 변수
bool Book::operator!() {
  if(price == 0) return true;
  else return false;
}
//not 외부 함수
//bool operator!()



/*
//책 제목 크기(<) 비교멤버 함수
bool Book::operator<(Book op2) {
  if(title < op2.title) return true;
  else return false;
} */

// 책 제목 크기(<) 비교 외부 함수
bool operator<(string op1, Book& op2) {
  if(op1 < op2.title)
    return true;
  else 
    return false;
} 



int main() {
  Book a("청춘", 20000, 300), b("미래", 30000, 500);
  a += 500; // 책 a의 가격 500원 증가
  b -= 500; // 책 b의 가격 500원 감소
  a.show();
  b.show();
  Book book("벼룩시장", 0, 50); // 가격은 0
  if(!book) cout << "공짜다" << endl;

  string b1;
  cout << "책 이름을 입력하세요>>";
  getline(cin, b1);
  if(b1 < a) {
    cout << a.getTitle() << "이" << b1 << "보다 뒤 있ㅜㅏ" << endl;
  }
}