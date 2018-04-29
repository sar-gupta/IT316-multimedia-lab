// Arithmetic encoding

#include <bits/stdc++.h>
using namespace std;

int main()
{
  char arr[26];
  float freq[26];
  map<char, float> range_from, range_to;
  int size;
  cout << "Enter the size: " << endl;
  cin >> size;
  cout << "Enter the array elements (char <space> probability): " << endl;
  for (int i = 0; i < size; i++)
    cin >> arr[i] >> freq[i];
  float prev = 0.0;
  for (int i = 0; i < size; i++)
  {
    range_from[arr[i]] = prev;
    range_to[arr[i]] = range_from[arr[i]] + freq[i];
    prev = range_to[arr[i]];
  }
  float low_val = 0.0, high_val = 1.0, diff = 1.0;
  char c;
  cout << "Enter the string to encode: " << endl;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    c = s[i];
    high_val = low_val + diff * range_to[c];
    low_val = low_val + diff * range_from[c];
    diff = high_val - low_val;
  }
  cout << low_val;
  return 0;
}