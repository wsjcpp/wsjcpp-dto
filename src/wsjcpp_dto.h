#ifndef WSJCPP_DTO_H
#define WSJCPP_DTO_H

#include <string>

/*! 
 * WsjcppDto - parent class for Data Transfer Objects
 * */

class WsjcppDto {
    public:
        WsjcppDto(const std::string &sObjectTypeName);
        std::string getObjectTypeName();
    private:
        std::string m_sObjectTypeName;
};

#endif // WSJCPP_DTO_H