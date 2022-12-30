#include "ConvertJSON.hpp"

using json = nlohmann::json;

void ConvertJSON::GetTextDocuments() {
  std::ifstream configFile("config.json"), currentFile;
  json config = json::parse(configFile);
  configFile.close();
  
  int totalFiles = config["files"].size();
  for (auto i = 0; i < totalFiles; i++) {
    currentFile.open(config["files"][i]);
    std::string str((std::istreambuf_iterator<char>(currentFile)),
                 std::istreambuf_iterator<char>());

    textDocuments.push_back(str);
    str.clear();
    currentFile.close();
  }
}

void ConvertJSON::GetResponsesLimit() {
  std::ifstream configFile("config.json");
  json config = json::parse(configFile);
  configFile.close();
  
  responsesLimit = config["config"]["max_responses"];
}

void ConvertJSON::GetRequests() {
  std::ifstream requestsFile("requests.json");
  json fileData = json::parse(requestsFile);
  requestsFile.close();
  
  int totalRequests = fileData["requests"].size();
  for (auto i = 0; i < totalRequests; i++) {
    requests.push_back(fileData["requests"][i]);
    resultsChecks.push_back(0);
  }
}

void ConvertJSON::putAnswers() {
  json answers;
  std::ofstream file("myAnswers.json");
  bool check = true;
  
  for (auto cR = 0; cR < requests.size(); cR++) { // Проверка запросов
    for (auto cTD = 0; cTD < textDocuments.size(); cTD++) { // Проверка документов
      for (auto cChInTD = 0; cChInTD < textDocuments[cTD].size(); cChInTD++) { // Проверка каждого символова
	for (auto cChInR = 0; cChInR < requests[cR].size(); cChInR++) {
	  if (requests[cR][cChInR] != textDocuments[cTD][cChInTD + cChInR]) {
	    check = false;
	  }
	}
	if (check)
	  resultsChecks[cR]++;
	check = true;
      }
    }
  }
  for (auto i = 0; i < requests.size(); i++) {
    answers["answers"][requests[i]]["results"] = resultsChecks[i];
  }
  file << answers;
  file.close();
}
