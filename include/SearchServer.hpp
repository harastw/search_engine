#pragma once

#include <InvertedIndex.hpp>

struct RelativeIndex
{
  RelativeIndex(size_t _doc_id, float _rank)
  {
    doc_id = _doc_id;
    rank = _rank;
  }
  RelativeIndex() = default;
  size_t doc_id;
  float rank;
  bool operator ==(const RelativeIndex& other) const {
    return (doc_id == other.doc_id && rank == other.rank);
  }
};

typedef std::vector<RelativeIndex> res_for_one_request;

struct SearchServer
{
  std::map<std::string,size_t> to_sort_unique_requests(std::map<std::string,size_t>& unique_requests);
  std::map<std::string,size_t> to_unique(std::vector<std::string> requests);
  void print_ri(RelativeIndex ri);
  void print_res_for_one_request(res_for_one_request res);
  res_for_one_request get_res_for_one_request(std::map<std::string,std::vector<Entry>>::iterator it_dict,
					      int responses_limit,
					      int total_this_request);
  std::vector<res_for_one_request> search(std::vector<std::string> requests,
					  InvertedIndex inverted_index,
					  int responses_limit);
private:
  std::vector<res_for_one_request> res;
};
