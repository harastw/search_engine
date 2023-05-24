#pragma once

#include <nlohmann/json.hpp>
#include <SearchServer.hpp>

class ConverterJSON {
public:
  std::vector<std::string> get_text_documents();
  int get_responses_limit();
  std::vector<std::string> get_requests();
  void put_answers(std::vector<res_for_one_request> res);
};
