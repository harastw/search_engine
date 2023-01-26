#pragma once

#include "WordsInFile.hpp"

class ConvertJSON {
public:
  void LoadUnique();
  bool GetTextDocuments();
  bool GetResponsesLimit();
  bool GetRequests();
  bool PutAnswers();
  
  void TestGetTextDocuments();
  void TestGetResponsesLimit();
  void TestGetRequests();
  void TestPutAnswers();
private:
  int totalFiles, responsesLimit;
  std::vector<std::string> requests;
  std::ifstream file;
  std::vector<WordsInFile> allWords;
};
