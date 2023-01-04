#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <streambuf>
#include <cassert>

#include "json.hpp"

class ConvertJSON {
public:
ConvertJSON() = default;
 
bool GetTextDocuments();
bool GetResponsesLimit();
bool GetRequests();
bool PutAnswers();

void TestGetTextDocuments();
void TestGetResponsesLimit();
void TestGetRequests();
void TestPutAnswers();
  
private:
  int responsesLimit;
  std::vector<std::string> requests, words;
  std::vector<int> resultsChecks;
};
