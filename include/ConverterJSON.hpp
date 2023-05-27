#pragma once

#include <nlohmann/json.hpp>
#include <SearchServer.hpp>

using json = nlohmann::json;

class ConverterJSON {
public:
  const std::vector<std::string> get_text_documents();
  const int get_responses_limit();
  const std::vector<std::string> get_requests();
  const void put_answers(std::vector<res_for_one_request> res);
};
