#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

vector<int> parseInput ();
void add (Node* &root, vector<int> nums);
void remove (Node* &root);
void display (Node* cur, int indent);

int main () {
  // variables
  Node* root = new Node();
  bool isRunning = true;

  while (isRunning) {
    // print commands
    cout << "Commands:" << endl;
    cout << "ADD -- add numbers" << endl;
    cout << "REMOVE -- remove numbers" << endl;
    cout << "PRINT -- display tree" << endl;
    cout << "QUIT -- quit the program" << endl << endl;

    // user interaction
    string input;
    getline (cin, input);
    if (input == "QUIT") { isRunning = false; }
    else if (input == "ADD") {
      vector<int> nums = parseInput();
      add (root, nums);
    }
    else if (input == "REMOVE") {
      remove (root);
    }
    else if (input == "PRINT") {
      display (root, 0);
    }
    else { cout << "Bad input!" << endl; }
    
  }

  return 0;
}

vector<int> parseInput () {
  cout << "File or console input? (F/C) ";
  string input;
  getline (cin, input);
  vector<int> nums;

  if (input == "F") {
    string fname;
    cout << "Name of file? ";
    getline (cin, fname);
    ifstream fin (fname);
    int x; cout << "Reading...";
    while (fin >> x) {
      nums.push_back(x);
    }
    fin.close();
    cout << endl << "Done." << endl;
  }
  else if (input == "C") {
    int n, x;
    cout << "How many numbers?" << endl;
    cin >> n; cin.get(); cout << endl << "Reading...";
    for (int i = 0; i < n; i++) {
      cin >> x; nums.push_back(x);
    }
    cin.get();
    cout << endl << "Done." << endl;
  }
  else { cout << "Bad input!" << endl; }

  return;
}



void remove (Node* &root);
// zero child deletion - just remove the node
// one child deletion - connect parent of cur to child of cur, unless cur is
// head, in which the new head is cur
// two child deletion - go to the right, then as left as possible, and move
// that value to cur's place. then use one child deletion on that original node


void display (Node* cur, int indent) {
  if (cur == NULL) return;
  display (cur->getRight(), indent + 1);
  for (int i = 0; i < indent; i++) { cout << "    "; }
  cout << cur->getValue() << endl;
  display (cur->getLeft(), indent + 1);
  return;
}
