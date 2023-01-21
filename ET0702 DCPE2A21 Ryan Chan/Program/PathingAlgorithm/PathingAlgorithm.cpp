// PathingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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

string Node::getName() {return name;}

int Node::getX() {return x;}

int Node::getY() {return y;}

void Node::setName(string s) {name = s;}

void Node::setX(int i) { x = i; }

void Node::setY(int i) { y = i; }

void main()
{
    ifstream inputFile;
    inputFile.open("Nodes.csv");

    string line = "";
    getline(inputFile, line);
    line = ""; // basically clear the header line

    while (getline(inputFile, line)) {
        string name;
        int x;
        int y;
        string tempString="";

        stringstream inputString(line);

        getline(inputString, name, ',');

        getline(inputString, tempString, ',');
        x = atoi(tempString.c_str());

        tempString = "";
        getline(inputString, tempString, ',');
        y = atoi(tempString.c_str());

        cout << name << ", " << x << ", " << y << endl;

        line = "";
    }

    cout << "Hello world!";

}

