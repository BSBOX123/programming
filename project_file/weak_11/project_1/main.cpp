#include<iostream>
#include<cctype> //조작자, setw
#include<iomanip> // isprint()

using namespace std;

int main() {
  for(int i=0; i<4; i++)
    cout << setw(4) << "dec" << setw(5) << "hexa" << setw(5) << "char";
  cout << endl;

  for(int i=0; i<4; i++)
    cout << setw(4) << "---" << setw(5) << "----" << setw(5) << "----";
  cout << endl;

  for(int i=0; i<128; i++) {
    cout << setw(4) << dec << i << setw(5) << hex << i << setw(5) << (isprint(i)? (char)i : '.');  
    if(i%4 == 3) cout << endl;
  }

}

