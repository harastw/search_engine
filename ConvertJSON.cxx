#include "ConvertJSON.hpp"

using json = nlohmann::json;

bool ConvertJSON::GetTextDocuments() {
  std::ifstream configFile("config.json");
  std::string newWord;
  std::vector<std::string> wordsFromCurrentFile;
  json config = json::parse(configFile); // to json
  configFile.close();
  
  totalFiles = config["files"].size();
  
  std::ifstream fromFileToString;
  for (auto i = 0; i < totalFiles; i++) {
    std::string nameOfCurrentFile = config["files"][i];
    fromFileToString.open(nameOfCurrentFile); // open current file
    if (fromFileToString.is_open()) {
      while(!fromFileToString.eof()) {
	fromFileToString >> newWord;
	if (newWord != "" && newWord != " ")
	  wordsFromCurrentFile.push_back(newWord);
	newWord.clear();
      }
      fromFileToString.close();
    } else {
      std::cout << "current \"open file\" operation is failed" << std::endl;
    }
    allWords[i] = wordsFromCurrentFile;
    wordsFromCurrentFile.clear();
  }
  
  for (auto it = allWords.begin(); it != allWords.end(); it++) {
    std::cout << it->first << " file:" << std::endl;
    for (auto i = 0; i < it->second.size(); i++) {
      std::cout << it->second[i] << " ";
    }
    std::cout << std::endl;
  }
  
  if (configFile.is_open())
    return false;
  return true;
}

void ConvertJSON::CheckWordsInDoc(std::map<int,std::vector<std::string>>::iterator it) {
  Entry entry;
  entry.first = it->first, entry.second;
  
  for (int i = 0; i < it->second.size(); i++) {
    entry.second = 0;
    for (int j = i + 1; j < it->second.size(); j++) {
      if (it->second[j] == it->second[i]) {
	entry.second++;
	it->second.erase(it->second.begin() + j);// delete current word
	j--;
      }
    }
    uniqueWords[it->second[i]].push_back(entry);
  }
}

bool ConvertJSON::ToUnique() {
  for (auto it = allWords.begin(); it != allWords.end(); it++) { // docs   
    CheckWordsInDoc(it);
  }
  
  for (auto it = uniqueWords.begin(); it != uniqueWords.end(); it++) {
    std::cout << it->first << ":" << it->second[0].first << ","
	      << it->second[0].second << std::endl;
  }
  
  Entry newEntry;
  for (auto it = uniqueWords.begin(); it != uniqueWords.end(); it++) {
    auto it2 = it;
    it2++;
    for (; it2 != uniqueWords.end(); it2++) {
      if (it->first == it2->first) {
	newEntry.first = it2->second[0].first;
	newEntry.second = it2->second[0].second;
	it->second.push_back(newEntry);
	uniqueWords.erase(it2);
	it2--;
      }
    }
  }
  
  for (auto it = uniqueWords.begin(); it != uniqueWords.end(); it++) {
    std::cout << it->first << std::endl;
    for (auto i = 0; i < it->second.size(); i++) {
      std::cout << it->second[i].first << " " << it->second[i].second << std::endl;
    }
    std::cout << std::endl;
  }
  
  return true;
}

bool ConvertJSON::GetResponsesLimit() {
  std::ifstream file("config.json");
  json config = json::parse(file);
  file.close();
  responsesLimit = config["config"]["max_responses"];
  
  if (file.is_open())
    return false;
  return true;
}

bool ConvertJSON::GetRequests() {
  std::ifstream file("requests.json");
  json requestsJSON = json::parse(file);
  file.close();
  int totalRequests = requestsJSON["requests"].size();
  for (auto i = 0; i < totalRequests; i++)
    requests.push_back(requestsJSON["requests"][i]);
  
  if (file.is_open())
    return false;
  return true;
}

bool ConvertJSON::PutAnswers() {
  json answers, jsonPair, relevance;
  
  bool result;
  for (auto i = 0; i < requests.size(); i++) {
    std::string currentRequest = "request" + std::to_string(i);
    result = false;
    for (auto it = uniqueWords.begin(); it != uniqueWords.end(); it++) {
      if (requests[i] == it->first)
	if (!responsesLimit) {
	  return true;
	} else {
	  answers["answers"][currentRequest]["result"] = true;
	  if (it->second.size() > 1) {
	    for (int j = 0; j < it->second.size(); j++) {
	      jsonPair["docid"] = it->second[j].first;
	      jsonPair["rank"] = it->second[j].second;
	      relevance.push_back(jsonPair);
	    }
	    answers["answers"][currentRequest]["relevance"] = relevance;
	    relevance.clear();
	  } else {
	    answers["answers"][currentRequest]["docid"] = it->second[0].first;
	    answers["answers"][currentRequest]["entry"] = it->second[0].second;
	  }
	}
      result = true;
      break;
    }
    if (!result)
      answers["answers"][currentRequest]["result"] = false;
  }
  std::ofstream answersFile("answers.json");
  answersFile << answers;
  answersFile.close();
  return true;
}
