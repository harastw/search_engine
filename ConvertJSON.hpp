#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <nlohmann/json.hpp>
#define Entry std::pair<int,int> // docid, amount entry's
using namespace std;

class ConvertJSON {
public:
  void printAllWords();
  void CheckWordsInDoc(int docid);
  bool InvertedIndex();
  bool GetTextDocuments();
  bool GetResponsesLimit();
  bool GetRequests();
  bool PutAnswers();
private:
  int totalFiles, responsesLimit;
  vector<string> requests;
  map<string, vector<Entry>> uniqueWords; // word, vector docid
  map<int, vector<string>> allWords; // docid, all words
};
