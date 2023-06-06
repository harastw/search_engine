#include <SearchServer.hpp>
#include <ConverterJSON.hpp>
#include <Help.hpp>
#include <mutex>

using json = nlohmann::json;

std::mutex m;

void one_file(int i, json config, std::string& target)
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

std::vector<std::string> ConverterJSON::get_text_documents() const
{
  std::vector<std::string> docs;
  std::ifstream config_file;
  config_file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
  config_file.open("../config.json");
  if (!config_file.is_open())
    std::cout << "config file does not open!\n";
  json config = json::parse(config_file); // to json
  config_file.close();
  int total_files = config["files"].size();
  std::vector<std::thread> threads;
  threads.resize(total_files);
  std::vector<std::string> adapters;
  adapters.resize(total_files);
  for (auto i = 0; i < total_files; i++)
    threads[i] = std::thread(one_file, i, config,
                 std::ref(adapters[i]));
  for (int i = 0; i < total_files; i++)
  {
    threads[i].join();
    docs.push_back(adapters[i]);
  }
  return docs;
}

int ConverterJSON::get_responses_limit() const
{
  std::ifstream file;
  file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
  file.open("../config.json");
  json config = json::parse(file);
  file.close();
  return config["config"]["max_responses"];
}

std::vector<std::string> ConverterJSON::get_requests() const
{
  std::vector<std::string> requests;
  std::ifstream file;
  file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
  file.open("../requests.json");
  json requestsJSON = json::parse(file);
  file.close();
  int total_requests = requestsJSON["requests"].size();
  Help help;
  for (auto i = 0; i < total_requests; i++)
  {
    auto words_in_request = help.to_words(requestsJSON["requests"][i]);
    for (auto el : words_in_request)
      requests.push_back(el);
  }
  return requests;
}

void ConverterJSON::put_answers(std::vector<res_for_one_request> res) const
{
  json answers, answer_on_request, el_of_answer;
  for (auto i = 0; i < (int)res.size(); i++)
  {
    std::string current_request = "request" + std::to_string(i);
    if (res[i].size() == 1 && res[i][0].rank == -1)
      answer_on_request[current_request]["result"] = false;
    else if (res[i].size() == 1)
    {
      answer_on_request[current_request]["result"] = true;
      answer_on_request[current_request]["docid"] = res[i][0].doc_id;
      answer_on_request[current_request]["rank"] = res[i][0].rank;
    }
    else
    {
      answer_on_request[current_request]["result"] = true;
      for (auto j = 0; j < (int)res[i].size(); j++)
      {
        el_of_answer["docid"] = res[i][j].doc_id;
        el_of_answer["rank"] = res[i][j].rank;
        answer_on_request[current_request]["relevance"].push_back(el_of_answer);
        el_of_answer.clear();
      }
    }
    answers["answers"].push_back(answer_on_request);
    answer_on_request.clear();
  }
  std::ofstream answers_file("../answers.json");
  answers_file << answers;
  answers_file.close();
}
