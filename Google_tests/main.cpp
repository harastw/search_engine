#include <gtest/gtest.h>

#include <InvertedIndex.hpp>
#include <SearchServer.hpp>
#include <ConverterJSON.hpp>
#include <string>
#include <vector>

ConverterJSON converter;
InvertedIndex inverted_index;
SearchServer search_server;

int responses_limit;

TEST(test_limit, start)
{ // не превышен ли responses_limit
  int total_answers;
  std::fstream answers_file;
  json answers;

  std::ifstream file;
  file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
  file.open("../config.json");
  json config = json::parse(file);
  file.close();

  responses_limit = config["config"]["max_responses"];

  answers_file.open("../answers.json");
  answers = json::parse(answers_file);
  total_answers = answers["answers"].size();
  
  ASSERT_TRUE(total_answers == responses_limit);
}

TEST(test_paths, start) // проверка доступа к файлам
{
  bool test;
  std::fstream config, answers, requests;
  config.open("../config.json");
  answers.open("../answers.json");
  requests.open("../answers.json");
  test = config.is_open() && answers.is_open() && requests.is_open();
  config.close(), answers.close(), requests.close();
  ASSERT_TRUE(test);
}

TEST(test_inverted_index, start) // проверка порядка в freq_dictionary
{
  bool test = true;

  std::vector<std::string> input_docs_example;
  input_docs_example.push_back("text text");
  input_docs_example.push_back("text bird bird banana");
  input_docs_example.push_back("text banana banana");
  
  inverted_index.update_document_base(input_docs_example);
  auto freq_dictionary = inverted_index.get_dict();

  auto it = freq_dictionary.begin();
  if (it->first != "banana")
    test = false;
  it++;
  if (it->first != "bird")
    test = false;
  it++;
  if (it->first != "text")
    test = false;
  ASSERT_TRUE(test);
}

TEST(test_search, start)
{
  bool test;
  std::vector<std::string> requests;
  requests.push_back("text");
  requests.push_back("milk");
  std::vector<res_for_one_request> res = search_server.search(requests,
                                                              inverted_index,
							      responses_limit);
  if (res[0][0].rank == -1 && res[1][0].rank != -1)
    test = true;
  else
    test = false;
  
  ASSERT_TRUE(test);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
