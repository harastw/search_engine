#include "ConvertJSON.hpp"
using json = nlohmann::json;
bool ConvertJSON::GetTextDocuments() {
  std::ifstream configFile("config.json"), currentFile;
  std::string new_word;
  json config = json::parse(configFile);
  configFile.close();
  int totalFiles = config["files"].size();
  for (auto i = 0; i < totalFiles; i++) {
    currentFile.open(config["files"][i]);
    while (!currentFile.eof()) {
      new_word << currentFile;
      words.push_back(new_word);
      new_word.clear();
    }
    currentFile.close();
  }
  if (!textDocuments.empty() && !currentFile.is_open() && !configFile.is_open())
    return true;
  return false;
}
bool ConvertJSON::GetResponsesLimit() {
  std::ifstream configFile("config.json");
  json config = json::parse(configFile);
  configFile.close();
  responsesLimit = config["config"]["max_responses"];
  if (!configFile.is_open())
    return true;
  return false;
}
bool ConvertJSON::GetRequests() {
  std::ifstream requestsFile("requests.json");
  json fileData = json::parse(requestsFile);
  requestsFile.close();
  int totalRequests = fileData["requests"].size();
  for (auto i = 0; i < totalRequests; i++) {
    requests.push_back(fileData["requests"][i]);
    resultsChecks.push_back(0);
  }
  if (!requestsFile.is_open())
    return true;
  return false;
}
bool ConvertJSON::PutAnswers() {
  json answers;
  std::ofstream file("myAnswers.json");
  bool check = true;
  for (auto currentRequest = 0; currentRequest < requests.size(); currentRequest++) { // Проверка запросов
    for (auto currentWord = 0; currentWord < textDocuments[currentTextDoc].size(); currentWord++) {
      for (auto currentCharInRequests = 0; currentCharInRequests < requests[currentRequest].size(); currentCharInRequests++) {
	if (requests[currentRequest][currentCharInRequests] != textDocuments[currentTextDoc][currentCharInTextDoc + currentCharInRequests]) {
	  check = false;
	}
	if (check)
	  resultsChecks[currentRequest]++;
	check = true;
      }
    }
  }
  for (auto i = 0; i < requests.size(); i++) {
    answers["answers"][requests[i]]["results"] = resultsChecks[i];
  }
  file << answers;
  file.close();
  if (!file.is_open())
    return true;
  return false;
}
void ConvertJSON::TestGetTextDocuments() {
  assert(GetTextDocuments()); 
}
void ConvertJSON::TestGetResponsesLimit() {
  assert(GetResponsesLimit());
}
void ConvertJSON::TestGetRequests() {
  assert(GetRequests());
}
void ConvertJSON::TestPutAnswers() {
  assert(PutAnswers());
}
