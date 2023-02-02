#pragma once
#include <string>
using namespace std;

class Node {
private:
    string name;
    int x;
    int y;
public:
    string getName();
    int getX();
    int getY();
    void setName(string s);
    void setX(int x);
    void setY(int y);
};

class Job { // I'm leaving all parameters private because it's so much easier
public:
    string from;
    string to;
    string ID;
};