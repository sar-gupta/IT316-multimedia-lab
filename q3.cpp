// Static huffman coding

#include <bits/stdc++.h>
using namespace std;

int main()
{
  string input;
  cout << "Enter text (without spaces): ";
  cin >> input; // doesn't support spaces
  priority_queue<pair<int, vector<char> >, vector<pair<int, vector<char> > >, greater<pair<int, vector<char> > > > pq;
  map<char, string> codes;
  vector<int> frequency(52, 0);
  int len = input.length();
  for (int i = 0; i < len; i++)
  {
    if (isupper(input[i]))
    {
      frequency[(int)input[i] - 65]++;
    }
    else
    {
      frequency[(int)input[i] - 71]++;
    }
  }
  for (int i = 0; i < 26; i++)
  {
    if (frequency[i] != 0)
    {
      vector<char> x;
      x.push_back(char(i + 65));
      pq.push(make_pair(frequency[i], x));
    }
  }
  for (int i = 26; i < 52; i++)
  {
    if (frequency[i] != 0)
    {
      vector<char> x;
      x.push_back(char(i + 71));
      pq.push(make_pair(frequency[i], x));
    }
  }
  while (!pq.empty())
  {
    pair<int, vector<char> > min1 = pq.top();
    pq.pop();
    if(pq.empty()) {
      break;
    }
    pair<int, vector<char> > min2 = pq.top();
    pq.pop();
    for (int i = 0; i < min1.second.size(); i++)
    {
      if (codes.find(min1.second[i]) == codes.end())
      {
        codes.insert(make_pair(min1.second[i], ""));
      }
      codes.find(min1.second[i])->second = "1" + codes.find(min1.second[i])->second;
    }
    for (int i = 0; i < min2.second.size(); i++)
    {
      if (codes.find(min2.second[i]) == codes.end())
      {
        codes.insert(make_pair(min2.second[i], ""));
      }
      codes.find(min2.second[i])->second = "0" + codes.find(min2.second[i])->second;
    }
    vector<char> temp;
    for(int i=0;i<min1.second.size();i++)
    {
      temp.push_back(min1.second[i]);
    }
    for(int i=0;i<min2.second.size();i++)
    {
      temp.push_back(min2.second[i]);
    }
    pq.push(make_pair(min1.first+min2.first, temp));
  }
  for(auto i = codes.begin();i!=codes.end();i++)
  {
    cout << i->first << " => " << i->second << '\n';
  }

  cout<<"Encoded string is: ";
  for(int i=0;i<input.size();i++)
  {
    cout<<codes.find(input[i])->second;
  }

}