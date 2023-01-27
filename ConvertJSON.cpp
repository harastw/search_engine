#include "ConvertJSON.hpp"

using json = nlohmann::json;

void ConvertJSON::LoadUnique() {
  std::vector<std::string> fullUniqueWords;
  if (allWords.size() != 0)
    if (allWords[0].data.size() != 0)
      fullUniqueWords.push_back(allWords[0].data[0].data);
  
  for (int i = 0; i < allWords.size(); i++) 
    for (int j = 0; j < allWords[i].data.size(); j++)            
      for (int k = 0; k < allWords.size(); k++)
	for (int n = 0; n < allWords[k].data.size(); n++) {
	  if (i == k)
	    continue;
	  if (allWords[i].data[j].data == allWords[k].data[n].data)
	    allWords[i].data[j].isUniqueAcrossFiles = false;
	}      
  
  for(int i = 0; i < allWords.size(); i++)
    for (int j = 0; j < allWords[i].data.size(); j++)
      std::cout << "i = " << i << "; j = " << j << "; word - " << allWords[i].data[j].data
		<< " with " << allWords[i].data[j].entry << " entry" << "; unique - "
		<< allWords[i].data[j].isUniqueAcrossFiles << std::endl;
}

bool ConvertJSON::GetTextDocuments() {
  std::ifstream configFile("config.json");
  json config = json::parse(configFile);
  configFile.close();
  
  Word newWord;
  WordsInFile newFileWords;
  
  totalFiles = config["files"].size();
  for (auto i = 0; i < totalFiles; i++) {
    newFileWords.fileName = config["files"][i];
    file.open(newFileWords.fileName);
    while(!file.eof()) {
      file >> newWord.data;
      newWord.entry = 0;
      newWord.docid = i;
      newFileWords.data.push_back(newWord); 
      newWord.data.clear();
    }
    newFileWords.data.pop_back();
    for (int j = 0; j < newFileWords.data.size(); j++) {
      for (int k = 0; k < j; k++) {
	if (newFileWords.data[k].data == newFileWords.data[j].data) {
	  newFileWords.data.erase(newFileWords.data.begin()+k);     
	  newFileWords.data[j].entry++;
	}
      }
    }
    
    allWords.push_back(newFileWords);
    newFileWords.data.clear();
    file.close();
  }
  
  if (configFile.is_open())
    return false;
  return true;
}

bool ConvertJSON::GetResponsesLimit() {
  file.open("config.json");
  json config = json::parse(file);
  file.close();
  responsesLimit = config["config"]["max_responses"];
  
  if (file.is_open())
    return false;
  return true;
}

bool ConvertJSON::GetRequests() {
  file.open("requests.json");
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
  json answers;
  std::vector<Word> protoAnswers;
  std::vector<int> requestsID;
  std::ofstream fileAnswers("myAnswers.json");
  std::vector<std::string> equalWords;
  bool check;
  for (auto i = 0; i < requests.size(); i++) {
    check = false;
    for (auto j = 0; j < allWords.size(); j++) {
      for (auto k = 0; k < allWords[j].data.size(); k++) {
	if (requests[i] == allWords[j].data[k].data) {
	  check = true;
	  protoAnswers.push_back(allWords[j].data[k]);
	  requestsID.push_back(i);
	}
      }
    }
    if (!check)
      answers["answers"]["request" + std::to_string(i)]["result"] = false;
  }
  for (auto i = 0; i < protoAnswers.size(); i++) {
    if (protoAnswers[i].isUniqueAcrossFiles) {
      answers["answers"]["request" + std::to_string(requestsID[i])]["result"] = true;
      answers["answers"]["request" + std::to_string(requestsID[i])]["docid"] = protoAnswers[i].docid;
    }
    else {
      equalWords.push_back(protoAnswers[i].data);
      for (auto j = i + 1; j < protoAnswers.size(); j++) {
	if (protoAnswers[i].data == protoAnswers[j].data) {
	  equalWords.push_back(protoAnswers[j].data);
	}
      }
      answers["answers"]["request" + std::to_string(i)]["result"] = true;
      for (auto j : equalWords) {
	answers["answers"]["request" + std::to_string(i)]["relevanse"]["docid"] = protoAnswers[i].docid;
      }
      equalWords.clear();
    }
  }	    
  
  std::cout << answers;
  fileAnswers << answers;
  fileAnswers.close();
  if (!fileAnswers.is_open())
    return true;
  return false;
}

void ConvertJSON::TestGetTextDocuments()  {assert(GetTextDocuments());}
void ConvertJSON::TestGetResponsesLimit() {assert(GetResponsesLimit());}
void ConvertJSON::TestGetRequests()       {assert(GetRequests());}
void ConvertJSON::TestPutAnswers()        {assert(PutAnswers());}
