#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <thread>
#include <mutex>
#include <nlohmann/json.hpp>

class ConverterJSON {
public:
  std::vector<std::string> GetTextDocuments();
  int GetResponsesLimit();
  std::vector<std::string> GetRequests();
  void PutAnswers(std::string answers);
};
