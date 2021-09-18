#include "parse_json.hpp"
namespace utils{
    /** 
     * Return a comma separated value from a parsed json
     * @param json_parse json to be parsed
     * @param maxsize maximum size of string parsed
     * @return parsed value
     */
    std::string parse (nlohmann::json json_parse, int maxsize){
        std::stringstream parsed;

        int size = 0;
        for (auto& el : json_parse.items()){
            parsed << el.value() << ",";
        }

        std::string response = parsed.str();

        int count = response.size();
        while (count >= maxsize){
            response.pop_back();
            count--;
        }

        while (response[count] != ','){
            response[count] = '#';
            count--;
        }
        response[count] = '#';

        if (response.back() == ',') response.pop_back();

        return response;
    }
}