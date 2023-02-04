#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

#include <nlohmann/json.hpp>

struct Word {
  std::string data;
  int entry = 0, docid;
  bool isUniqueAcrossFiles = true;
};
