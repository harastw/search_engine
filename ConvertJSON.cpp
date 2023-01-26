#include "ConvertJSON.hpp"

using json = nlohmann::json;

void ConvertJSON::LoadUnique() {
  std::vector<std::string> fullUniqueWords;
  if (allWords.size() != 0)
    if (allWords[0].data.size() != 0)
      fullUniqueWords.push_back(allWords[0].data[0].data);

  for (int i = 0; i < allWords.size(); i++) {
    for (int j = 0; j < allWords[i].data.size(); j++) {             
      for (int k = 0; k < allWords.size(); k++) {
	for (int n = 0; n < allWords[i].data.size(); n++) {
	  if (i == k)
	    continue;
	  if (allWords[i].data[j].data == allWords[k].data[n].data)
	    allWords[i].data[j].isUniqueAcrossFiles = false;
	}
      }      
    }
  }
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
      newFileWords.data.push_back(newWord); 
      newWord.data.clear();
    }
    newFileWords.data.pop_back();
    for (int j = 0; j < newFileWords.data.size(); j++) {
      for (int k = 0; k < j; k++) {
	if (newFileWords.data[k].data == newFileWords.data[j].data) {
	  newFileWords.data.erase(newFileWords.data.begin()+k);
	  k--;
	  newFileWords.data[j].entry++;
	}
      }
    }
    
    allWords.push_back(newFileWords);
    newFileWords.data.clear();
    std::cout << "work with " << config["files"][i] << " complete!" << std::endl;
    file.close();
  }
  for(int i = 0; i < allWords.size(); i++)
    for (int j = 0; j < allWords[i].data.size(); j++)
      std::cout << "i = " << i << "; j = " << j << "; word - " << allWords[i].data[j].data
		<< " with " << allWords[i].data[j].entry << " entry" << std::endl;
  
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
  std::ofstream fileAnswers("myAnswers.json");
  int founds;
  for (int i = 0; i < requests.size(); i++) {
    for (int j = 0; j < allWords.size(); j++) {
      for (int k = 0; k < allWords[j].data.size(); k++) {
	if (requests[i] == allWords[j].data[k].data) {
	  if (allWords[j].data[k].isUniqueAcrossFiles == false)
	    answers["answers"]["request" + std::to_string(i)]["result"] = true;
	  else
	    answers["answers"]["request" + std::to_string(i)]["relevanse"]["docid"] = j;
	}
      }
    }
  }

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
