#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "json.hpp"

namespace utils{
    std::string parse (nlohmann::json json_parse, int maxsize);
}