#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Book {
  int year;
  string author;
  string title;
public:
  Book(string title, string author, int year)
    : title(title), author(author), year(year) {}
  string getAuthor() {return author;}
  int getYear() { return year; }
  void show();
};

void Book::show() {
  cout << year << "년도," << title << "," << author << endl;
}


class BookManager {
  vector<Book> v;
  void bookIn();
  void searchByAuthor();
  void searchByYear();
public:
  void run();
};

void BookManager::bookIn() {
  string title, author;
  int year;
  cout << "입고할 책 (년도 -1:종료)>>";

  while(true) {
    cout << "출판년도>>";
    cin >> year; cin.ignore();
    if(year == -1) break;
    cout << "책 이름>>";
    getline(cin, title);
    cout << "책 저지>>";
    getline(cin, author);

    Book b(title, author, year);
    v.push_back(b);
  }
  cout << "총 입고된 책 : " << v.size() << endl;
}

void BookManager::searchByAuthor() {
  cout << "검색할 저자>>";
  string author;
  getline(cin, author);

  for(int i=0; i=v.size(); i++) {
    if(v[i].getAuthor() == author)
      v[i].show();
  }
}
void BookManager::searchByYear() {
  cout << "검색할 연도>>";
  int year;
  cin >> year; 

  for_each(v.begin(), v.end(), [year](Book b) {
    if(b.getYear() == year)
      b.show();
  });
}

void BookManager::run() {
  while(true) {
    cout << "1:추가, 2:저자 검색, 3:년도검색, 0:종료>>";
    int menu;
    cin >> menu; cin.ignore();

    if(menu == 0) break;
    switch (menu)
    {
    case 1:
      bookIn();
      break;
    
    case 2:
      searchByAuthor();

    case 3:
      searchByYear();

    default:
      cout << "메뉴선택 오류";
    }
  }
}

int main() {
  BookManager bm;
  bm.run();
}