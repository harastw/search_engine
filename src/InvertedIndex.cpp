#include <InvertedIndex.hpp>

void update_in_thread(std::string s,
                      std::map<std::string,size_t>& uniqueWords)
{
  Help help;
  std::vector<std::string> words = help.to_words(s);
  uniqueWords = help.into_unique(words);
} 

void
InvertedIndex::update_document_base(const std::vector<std::string>& input_docs)
{
  std::vector<std::map<std::string,size_t>> unique_words_v;
  unique_words_v.resize(input_docs.size());
  std::vector<std::thread> threads;
  threads.resize(input_docs.size());
  int threads_size = threads.size();
  for (auto i = 0; i < threads_size; i++)
  threads[i] = std::thread(update_in_thread, input_docs[i],
               std::ref(unique_words_v[i]));
  for (auto i = 0; i < threads_size; i++)
    threads[i].join();

  int unique_words_size = unique_words_v.size();
  for (auto i = 0; i < unique_words_size; i++)
  {
    std::vector<Entry> new_entry_v;
    auto current_words = unique_words_v[i];
    for (auto j = current_words.begin(); j != current_words.end(); j++)
    {
      auto current_word = j->first;
      auto count_current_word = j->second;
      Entry new_entry;
      new_entry.doc_id = i;
      new_entry.count = count_current_word;
      new_entry_v.push_back(new_entry);
      freq_dictionary[current_word] = new_entry_v;

      for (auto k = i + 1; k < unique_words_size; k++)
      {
        auto current_words2 = unique_words_v[k];
        count_current_word = 0;
        for (auto l = current_words2.begin(); l != current_words2.end(); l++)
        {
          auto currentWord2 = l->first;
          if (current_word == currentWord2)
            count_current_word++;
        }
        new_entry.doc_id = k;
        new_entry.count = count_current_word;
        freq_dictionary[current_word].push_back(new_entry);
      }
      new_entry_v.clear();
    }
  }
}

std::map<std::string,std::vector<Entry>> InvertedIndex::get_dict() const
{
  return freq_dictionary;
}
