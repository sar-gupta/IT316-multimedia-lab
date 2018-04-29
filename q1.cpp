// WAP to write and display data in a file

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // writing
  ofstream file;
  file.open("file1.txt", ios::out);
  cout << "Enter text: ";
  string a;
  getline(cin, a);
  file << a << endl;
  file.close();

  // reading
  ifstream infile;
  infile.open("file1.txt", ios::in);
  string out;
  getline(infile, out);
  cout << out;
  infile.close();

  return 0;
}