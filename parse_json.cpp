#include <iostream>
#include <string>
#include <sstream>
#include "json.hpp"
#define MAXSIZE 26

namespace utils{
    /** 
     * Return a comma separated value from a parsed json
     * @param json_parse json to be parsed
     * @return parsed value
     */
    std::string parse (nlohmann::json json_parse){
        std::stringstream parsed;

        int size = 0;
        for (auto& el : json_parse.items()){
            parsed << el.value() << ",";
        }

        std::string response = parsed.str();

        int i = response.size();
        while (i >= MAXSIZE){
            response.pop_back();
            i--;

            if (i == MAXSIZE){
                while (response[i] != ','){
                    response[i] = '#';
                    i--;
                }
                response[i] = '#';
            }
        }

        if (response.back() == ',') response.pop_back();

        for (int i = size; i >= 26; i--){
            response.pop_back();
        }

        return response;
    }
}

int main (void){
    nlohmann::json json_parse{
    {"pi", 3.141},
    {"value", 42.99},
    {"bateria", 76.9283},
    {"pressao", 1.283},
    {"temperatura", 18.9823},
    {"humidade", 32.1298}
    };

    std::string teste;
    teste = utils::parse(json_parse);

    for(char letra : teste){
        std::cout << letra;
    }
}