#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Words {
  ifstream fin;
  vector<string> wordVector;
  bool exist(string word);
  void search(string word);
public:
  Words();
  ~Words();
  void run();
};

Words::Words() {
  fin.open("words.txt");
  if(!fin) {
    cout << "words.txt 열기 실패" << endl;
    exit(0);
  }

  string word;
  while(getline(fin, word)) {
    wordVector.push_back(word);
  }
  cout << wordVector.size() << "개 단어 로딩!" << endl;
}

Words::~Words() {
  fin.clear();
}

void Words::search(string word) {
  int lenght = word.length();
  for(int i=0; i<wordVector.size(); i++) {
    if(wordVector[i].length() == lenght) {
      if(wordVector[i] == word)
        continue;

      for(int j=0; j<lenght; j++) {
        string orig = word;
        string dic_word = wordVector[i];
        orig[j] = dic_word[j] = '*';

        if(orig == dic_word) {
          cout << wordVector[i] << endl;
          break;
        }
      }
    }
  }
}

bool Words::exist(string word) {
  for(int i=0; i<wordVector.size(); i++)
    if(wordVector[i] == word)
      return true;
  return false;
}

void Words::run() {
  while(true) {
    cout << "단어>>";
    string word;
    getline(cin, word);

    if(word == "exit") return;
    if(!exist(word))
      cout << word << "는 사전에 없음." << endl;
    search(word);
  }
}



int main() {
   Words w;
   w.run();
}