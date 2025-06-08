#include<iostream>
#include<cctype>
#include<iomanip>
#include<string>


using namespace std;

class Phone { // 전화 번호를 표현하는 클래스
  string name;
  string telnum;
  string address;
public:
  Phone(string name="", string telnum="", string address="") {
    this->name = name;
    this->telnum = telnum;
    this->address = address;
  }

  friend ostream& operator << (ostream& outs, Phone phone);
  friend istream& operator>>(istream& ins, Phone& phone);
};

ostream& operator << (ostream& outs, Phone phone) {
  outs << "(" << phone.name << "," << phone.telnum <<"," << phone.address << ")";
  return outs;
}

istream& operator>>(istream& ins, Phone& phone) {
  cout << "이름>>";
  getline(ins, phone.name);
  cout << "전화번호>>";
  getline(ins, phone.telnum);
  cout << "주소>>";
  getline(ins, phone.address);
  return ins;
}



int main() {
  Phone boy, girl;
  cin >> boy >> girl;
  cout << boy << endl << girl << endl;
}


