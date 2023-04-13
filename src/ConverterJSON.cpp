#include "ConverterJSON.h"

using json = nlohmann::json;

std::mutex m;

void oneFile(int i, json config,
	     std::string& target)
{
  std::string fileName = config["files"][i];
  std::ifstream file(fileName);
  std::stringstream buffer;
  buffer << file.rdbuf();
  m.lock();
  target = buffer.str();
  m.unlock();
  file.close();
}

std::vector<std::string> ConverterJSON::GetTextDocuments()
{ // start
  std::vector<std::string> docs;
  std::ifstream configFile("config.json");
  if (!configFile.is_open())
    std::cout << "config file does not open!\n";
  json config = json::parse(configFile); // to json
  configFile.close();
  int totalFiles = config["files"].size();
  std::vector<std::thread> threads;
  threads.resize(totalFiles);
  std::vector<std::string> adapters;
  adapters.resize(totalFiles);
  for (int i = 0; i < totalFiles && i < threads.size(); i++)
    threads[i] = std::thread(oneFile, i, config,
			     std::ref(adapters[i]));
  for (int i = 0; i < totalFiles; i++) {
    threads[i].join();
    docs.push_back(adapters[i]);
  } 
  return docs;
}

int ConverterJSON::GetResponsesLimit()
{
  std::ifstream file("config.json");
  json config = json::parse(file);
  file.close();
  return config["config"]["max_responses"];
}

std::vector<std::string> ConverterJSON::GetRequests()
{
  std::vector<std::string> requests;
  std::ifstream file("requests.json");
  json requestsJSON = json::parse(file);
  file.close();
  int totalRequests = requestsJSON["requests"].size();
  for (auto i = 0; i < totalRequests; i++)
    requests.push_back(requestsJSON["requests"][i]);
  return requests;
}

void ConverterJSON::PutAnswers(std::string answers)
{
  std::ofstream answersFile("answers.json");
  // json config = json::parse(answers);
  answersFile.close();
}
