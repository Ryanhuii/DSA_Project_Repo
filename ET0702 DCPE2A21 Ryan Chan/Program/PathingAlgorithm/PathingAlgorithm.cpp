// PathingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "classes.h"

using namespace std;

// These two functions have been tested, they should be okay
int distance(string n1, string n2, vector<Node> nodes); // function to calculate the distance between two coordinates, rounded down to nearest integer
Node findNode(string s, vector<Node> nodes); // returns the node with the name, s
vector<Job> FindDuplicates(vector<Job> jobs);

int main()
{

	// Creating vectors
	vector<Node> nodes;
	vector<Job> jobs;

	// =============== getting file data =============== 
	// should I turn this whole thing into a function so that main() is smaller an easier to read?...

	// Nodes.csv
	ifstream inputFile;
	inputFile.open("Nodes.csv");

	string line = "";
	getline(inputFile, line);
	line = ""; // basically clear the header line

	cout << "Nodes detected:";
	while (getline(inputFile, line)) {
		string name;
		int x;
		int y;
		string tempString = "";

		stringstream inputString(line);

		getline(inputString, name, ',');

		getline(inputString, tempString, ',');
		x = atoi(tempString.c_str());

		tempString = "";
		getline(inputString, tempString, ',');
		y = atoi(tempString.c_str());

		line = "";

		Node node;
		node.setName(name);
		node.setX(x);
		node.setY(y);

		nodes.push_back(node); // add the node to the vector

	} // end of Nodes.csv file reading
	inputFile.close();

	for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++) {
		cout << endl << (*it).getName() << ", " << (*it).getX() << ", " << (*it).getY();
	}

	// Jobs.csv
	inputFile.open("Jobs.csv");
	line = "";
	getline(inputFile, line);
	line = ""; // clears the header line

	while (getline(inputFile, line)) {
		string from;
		string to;
		string ID;

		stringstream inputString(line);
		getline(inputString, ID, ',');
		getline(inputString, from, ',');
		getline(inputString, to, ',');


		Job job;
		job.ID = ID;
		job.from = from;
		job.to = to;


		jobs.push_back(job);
	}
	inputFile.close();

	cout << endl << "\nJobs detected:";
	for (vector<Job>::iterator it = jobs.begin(); it != jobs.end(); it++) {
		cout << endl << (*it).ID << " , " << (*it).from << " , " << (*it).to;
	}

	// =============== finished getting file data ===============

	cout << endl << distance("B", "D", nodes) << endl;

	jobs = FindDuplicates(jobs);
	for (vector<Job>::iterator it = jobs.begin(); it != jobs.end(); it++) {
		cout << endl << (*it).ID << " , " << (*it).from << " , " << (*it).to;
	}

	return 0;
} // end of main()


Node findNode(string s, vector<Node> nodes) {
	Node n;
	n.setName("error!");
	for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++) {
		if ((*it).getName() == s) {
			n = (*it);
		}
	}
	// Error checking
	if (n.getName() == "error!") {
		cout << "\nNode " << s << " does not exist!\n";
	}
	cout << "\nNode found: " << n.getName() << endl;
	return n;
}

int distance(string n1, string n2, vector<Node> nodes) { // the function findNode is used inside distance() itself
	// Need to find the nodes with the names that are given
	Node a, b;
	a = findNode(n1, nodes);
	b = findNode(n2, nodes);
	double result = pow(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2), 0.5);
	return floor(result);
}

vector<Job> FindDuplicates(vector<Job> old_jobs) {
	vector<Job> jobs = old_jobs;
	for (vector<Job>::iterator it = jobs.begin(); it != jobs.end(); it++) {
		for (vector<Job>::iterator xd = jobs.begin(); xd != jobs.end(); xd++) {
			// this inner for loop has to skip over the outer for loop's selected job
			if ((*it).ID != (*xd).ID) { // must make sure the for loops are not referencing the same job
				if ((*it).from == (*xd).from && (*it).to == (*xd).to) {
					cout << "duplicates found: " << (*it).ID << ", " << (*xd).ID << endl;
					Job new_job;
					new_job.from = (*it).from;
					new_job.to = (*it).to;
					new_job.ID = (*it).ID + "-" + (*xd).ID;
					cout << "new job ID: " << new_job.ID << endl;
					/*jobs.erase(it);
					jobs.erase(xd);*/
					jobs.push_back(new_job);
					break;
				}
			}
		}
	}
	return jobs;
}




