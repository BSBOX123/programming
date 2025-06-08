#pragma once
#include<iostream>

using namespace std;

class UI {
public:
  static int getMainMenu();
  static int getShapeType();
  static int getShapeIndex();
  static void println(string msg);
  static void print(string nsg);
  static void print(int msg);
};