#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class GradeManager {
  map<string, int> scoreMap;
  void insert();
  void search();
public:
  void run();
};

void GradeManager::insert() {
  string name;
  int score;
  cout << "이름 점수>> ";
  cin >> name >> score;

  if(scoreMap.find(name) != scoreMap.end()) {
    cout << "중복된 학생 이름!!!" << endl;
    return;
  } else {
    scoreMap[name] = score;
    //scoreMap.insert(make_pair(name, score));
  }
}

void GradeManager::search() {
  string name;
  cout << "검색할 이름: ";
  cin >> name;
  if(scoreMap.find(name) == scoreMap.end()) {
    cout << name << "은 없습니다." << endl;
  } else {
    cout << name << "의 점수: " << scoreMap[name] << endl;
  }
}

void GradeManager::run() {
  int menu;
  cout << " 입력:1, 조회:2, 종료:0>>";
  cin >> menu;
  while (true) 
  {
    switch (menu)
    {
    case 1:
      insert();
      break;
    
    case 2:
      search();
      break;
  
    case 0:
     return;
  
    default:
      cout << "메뉴 선택 오류" << endl;
    }
  }
}


int main() {
  GradeManager gm;
  gm.run();
}
