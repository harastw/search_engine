#include <ConverterJSON.hpp>
#include <InvertedIndex.hpp>
#include <SearchServer.hpp>
#include <exception>

int main()
{
  ConverterJSON converter;
  InvertedIndex inverted_index;
  SearchServer search_server;
  std::vector<std::string> texts, requests;
  int responses_limit;
  
  try
  {
    texts = converter.get_text_documents();
  }
  catch(const std::exception& ex1)
  {
    std::cout << "нет доступа к текстам" << std::endl;
    return 1;
  }
  try
  {
    responses_limit = converter.get_responses_limit();
  }
  catch(const std::exception& ex2)
  {
    std::cout << "нет доступа к лимиту ответов" << std::endl;
  }
  try
  {
    requests = converter.get_requests();
  }
  catch(const std::exception& ex3)
  {
    std::cout << "нет доступа к запросам" << std::endl;
  }
  inverted_index.update_document_base(texts);
  auto res = search_server.search(requests, inverted_index,
				  responses_limit);
  try
  {
    converter.put_answers(res);
  }
  catch(const std::exception& ex4)
  {
    std::cout << "нет доступа на запись" << std::endl;
  }

  std::cout << "программа успешно отработала"
	    << std::endl;
  return 0;
}
