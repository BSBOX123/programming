#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<int>& v) {
  for(int i=0; i < v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;
}

double getAvg(vector<int>& v) {
  int sum = 0;
  for(auto it = v.begin(); it != v.end(); it++) {
    sum += *it;
  }
  return(double)sum / v.size();
}

int main() {
  vector<int> v;
  while(true) {
    cout << "정수 (종료:0)>>";
    int num;
    cin >> num;
    if(num == 0) break;
    v.push_back(num);
    //printVector(v);

    for_each(v.begin(), v.end(), [](int n){cout << n << ' ';});
    cout << endl;

    //cout << "평균: " << getAvg(v) << endl;

    int sum = 0;
    for_each(v.begin(), v.end(), [&sum](int n) {sum += n;});
    cout << "평균:" << (double)sum / v.size() << endl;
  }
}