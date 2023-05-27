#include <SearchServer.hpp>

const void SearchServer::print_ri(RelativeIndex ri)
{
  std::cout << "ri.doc_id = " << ri.doc_id << "\t"
            << "ri.rank = " << ri.rank << std::endl;
}

const void SearchServer::print_res_for_one_request(res_for_one_request res)
{
  for (auto i = 0; i < (int)res.size(); i++)
    print_ri(res[i]);
  std::cout << std::endl;
}

const std::map<std::string,size_t>
SearchServer::to_unique(std::vector<std::string> requests)
{
  std::map<std::string,size_t> unique_requests;
  int requests_size = requests.size();
  for (auto i = 0; i < requests_size; i++)
  {
    int n = 1;
    for (auto j = i + 1; j < requests_size; j++)
      if (requests[i] == requests[j])
        n++;
    unique_requests[requests[i]] = n;
  }
  return unique_requests;
}
    

const std::map<std::string,size_t>
SearchServer::to_sort_unique_requests(std::map<std::string,size_t>& unique_requests)
{
  std::map<std::string,size_t> sort_unique_requests;
  for (auto it = unique_requests.begin(); it != unique_requests.end(); it++)
  {
    auto it_on_minimum = it;
    for (auto it2 = it; it2 != unique_requests.end(); it2++)
    {
      if (it2->second < it_on_minimum->second)
        it_on_minimum = it2;
    }
      sort_unique_requests[it_on_minimum->first] = it_on_minimum->second;
  }
  return unique_requests;
}

const res_for_one_request
SearchServer::get_res_for_one_request(std::map<std::string,std::vector<Entry>>::iterator it_dict,
                                      int responses_limit,
                                      int total_this_request)
{
  res_for_one_request one_res;
  RelativeIndex new_relative_index;
  int vector_dict_size = it_dict->second.size();
  for (int i = 0; i < vector_dict_size && i < responses_limit; i++)
  {
    float current_count = it_dict->second[i].count;
    new_relative_index.doc_id = it_dict->second[i].doc_id;
    new_relative_index.rank = current_count / total_this_request;
    one_res.push_back(new_relative_index);
  }
  return one_res;
}

const std::vector<res_for_one_request>
SearchServer::search(std::vector<std::string> requests,
                     InvertedIndex inverted_index,
                     int responses_limit)
{
  std::vector<res_for_one_request> res;
  std::map<std::string,size_t> sort_requests = to_unique(requests);
  sort_requests = to_sort_unique_requests(sort_requests);
  std::map<std::string,std::vector<Entry>> dict = inverted_index.get_dict();
  bool is_found;
  res_for_one_request new_res;
  RelativeIndex new_relative_index;
  
  for (auto it_request = sort_requests.begin(); it_request != sort_requests.end(); it_request++)
  {
    int total_this_request = it_request->second;
    is_found = false;
    for (auto it_dict = dict.begin(); it_dict != dict.end(); it_dict++)
    {
      if (it_request->first == it_dict->first)
      {
        new_res = get_res_for_one_request(it_dict,
                                          responses_limit,
                                          total_this_request);
        is_found = true;
      }
    }
    if (!is_found)
    {
      new_relative_index = RelativeIndex(0, -1);
      new_res.push_back(new_relative_index);
    }
    res.push_back(new_res);
    new_res.clear();
  }
  return res;
}
