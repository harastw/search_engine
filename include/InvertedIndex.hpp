#pragma once

#include <Help.hpp>

struct Entry
{
  size_t doc_id, count;
  bool operator ==(const Entry& other) const {
    return (doc_id == other.doc_id &&
	    count == other.count);
  }
};

class InvertedIndex
{
 public:
  void update_document_base(std::vector<std::string> input_docs);
  std::map<std::string,std::vector<Entry>> get_dict();
 private:
  std::map<std::string,std::vector<Entry>> freq_dictionary;
};
