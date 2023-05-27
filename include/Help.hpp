#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <mutex>
#include <map>
#include <thread>
#include <fstream>

struct Help
{    
  const std::vector<std::string>
  to_words(const std::string& s)
  {
    std::stringstream ss(s);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> tokens(begin, end);
    return tokens;
  }

  const std::map<std::string,size_t>
  into_unique(const std::vector<std::string>& vs)
  {
    std::map<std::string,size_t> unique_words;
    size_t totalWord;
    int vs_size = vs.size();
    for (auto i = 0; i < vs_size; i++)
    {
      totalWord = 1;
      for (auto j = i; j < vs_size; j++)
	if (vs[i] == vs[j])
	  totalWord++;
      unique_words[vs[i]] = totalWord;
    }
    return unique_words;
  }
};
