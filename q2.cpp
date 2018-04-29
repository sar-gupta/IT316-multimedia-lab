// Run length encoding

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // encoder
  string encoded = "";
  string input;
  cout << "Enter string: ";
  getline(cin, input);
  int len = input.length();
  bool newchar = true;
  int count = 1;
  for (int i = 0; i < len; i++)
  {
    if (newchar)
    {
      encoded += input[i];
      newchar = false;
    }
    if (input[i] == input[i + 1])
    {
      count++;
    }
    else
    {
      newchar = true;
      encoded += to_string(count);
      count = 1;
    }
  }
  cout << "Encoded string is: " << encoded << endl;

  // decoder
  string decoded = "";
  len = encoded.length();
  for (int i = 0; i < len; i += 2)
  {
    int count = (int)encoded[i + 1] - 48;
    while (count--)
    {
      decoded += encoded[i];
    }
  }
  cout << "Decoded string is: " << decoded;
}