#include "ConvertJSON.hpp"

using json = nlohmann::json;

void ConvertJSON::CheckWordsInDoc(int docid) {
  Entry entry;
  entry.first = docid;
  entry.second = 0;
  std::vector<Entry> newEntryVector;
  newEntryVector.push_back(entry);
  for (int i = 0; i < allWords[docid].size(); i++) {
    std::string currentWord = allWords[docid][i];
    uniqueWords[currentWord] = newEntryVector; // new unique word
    for (int j = i; j < allWords[docid].size(); j++) {
      if (allWords[docid][j] == allWords[docid][i] && i != j) {
	allWords[docid].erase(allWords[docid].begin() + j);// delete current word
	uniqueWords[currentWord][0].second++;
	j--;
      }
    }
  }
}

bool ConvertJSON::InvertedIndex() {
  for (int i = 0; i < allWords.size(); i++) { // docs   
    CheckWordsInDoc(i);
  }
  std::map<std::string, std::vector<Entry>>::iterator it;
  for (int i = 0; i < uniqueWords.size(); i++) {
    for (int j = i; j < uniqueWords.size(); j++) {
      if (uniqueWords[i]->first == uniqueWords[j]->first) {
	uniqueWords[i]->second.push_back(uniqueWords[j]->second[0]);
	uniqueWords.erase(uniqueWords.begin() + j);
	j--;
      }
    }
  }
  return true;
}

bool ConvertJSON::GetTextDocuments() { // start
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
    while(!fromFileToString.eof()) {
      fromFileToString >> newWord;
      wordsFromCurrentFile.push_back(newWord);
      newWord.clear();
    }
    allWords[i] = wordsFromCurrentFile;
    wordsFromCurrentFile.clear();
  }
  
  if (configFile.is_open())
    return false;
  return true;
}

void printAllWords() {
  for (auto el : allWords) {
    for (auto el2 : el) {
      std::cout << el2 << " ";
    }
    std::endl;
  }
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
  return true;
}
