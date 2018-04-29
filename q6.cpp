// LZW coding

#include<bits/stdc++.h>
using namespace std;

int main() {
  // dictionary starts after 0-255 ASCII characters
  string input;
  int temp_num = 256;
  cout<<"Enter string: ";
  getline(cin, input);
  map<string, int> dictionary;
  
  vector<int> output;
  string curr = "";
  bool already = false;
  for(int i=0;i<input.length();i++) {
    if(i == input.length()-1 && !already) {
      output.push_back((int)input[i]);
      break;
    }
    curr += input[i];
    char next = input[i+1];
    string check = curr+next;
    if(!dictionary[check]) {
      dictionary[check] = temp_num++;        
      if(curr.length() == 1) {
        output.push_back((int)curr[0]);
      }
      else {
        output.push_back(dictionary[curr]);
      }
      curr = "";
    }
    if(curr!="") {
      // already in dictionary
      already = true;
    }
    else {
      already = false;
    }
  }
  for(int i=0;i<output.size();i++) {
    cout<<output[i]<<" ";
  }
}