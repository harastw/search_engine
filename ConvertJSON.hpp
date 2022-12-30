#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <streambuf>

#include "json.hpp"

class ConvertJSON {
public:
ConvertJSON() = default;
 
void GetTextDocuments();
void GetResponsesLimit();
void GetRequests();
void putAnswers();

private:
  int responsesLimit;
  std::vector<std::string> requests, textDocuments;
  std::vector<int> resultsChecks;
};
