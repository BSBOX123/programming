#include<iostream>
#include<cctype>
#include<fstream> // toupper()

using namespace std;

int main() {
  string inputFile = ""; // 알맞은 맥북 링크 찾기
  string outputFile = ""; // "

  ifstream fin(inputFile);

  if(!fin) {
    cout << inputFile << "열기 실패" << endl;
    return 0;
  }

  ofstream fout(outputFile);
  if(!fout) {
    cout << outputFile << "열기 실패" << endl;
    return 0;
  }
  cout << "파일 읽기 시작..." << endl;

  int ch;
  while ( (ch = fin.get()) != EOF )
  {
    fout.put( toupper(ch));
  }
  cout << "파일 읽기 끝" << endl;
  fout.close();
  fin.close();
  
}