#ifndef WSJCPP_DTO_H
#define WSJCPP_DTO_H

#include <string>
#include <json.hpp>

/*! 
 * WsjcppDto - parent class for Data Transfer Objects
 * */

class WsjcppDto {
    public:
        WsjcppDto(const std::string &sObjectTypeName);
        std::string getObjectTypeName();
        bool fillFromJson(nlohmann::json &jsonData, std::string &sError);
        nlohmann::json toJson();

    private:
        std::string m_sObjectTypeName;
};

#endif // WSJCPP_DTO_H