#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include <nlohmann/json.hpp>

#define Entry std::pair<int,int> // docid, amount entry's

class ConvertJSON {
public:  
  void CheckWordsInDoc(std::map<int,std::vector<std::string>>::iterator it);
  bool ToUnique();
  bool GetTextDocuments();
  bool GetResponsesLimit();
  bool GetRequests();
  bool PutAnswers();
private:
  int totalFiles, responsesLimit;
  std::vector<std::string> requests;
  std::map<std::string, std::vector<Entry>> uniqueWords;
  std::map<int, std::vector<std::string>> allWords;
};
