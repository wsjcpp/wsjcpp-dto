#include <string.h>
#include <iostream>
#include <algorithm>
#include <wsjcpp_core.h>
#include <wsjcpp_dto.h>

class WsjcppDtoPerson : public WsjcppDto {
    public:
        WsjcppDtoPerson() : WsjcppDto("person", "Person") {
            // requireField<WsjcppDtoString>("name", "Name of person");
            requireField<WsjcppDtoString>("name", "Name of person");
            optionalField<WsjcppDtoInteger>("age", "Age of person");
        };
};

class WsjcppDtoUserProfile : public WsjcppDto {
    public:
        WsjcppDtoUserProfile() : WsjcppDto("user_profile", "User Profile") {
            // requireField<WsjcppDtoString>("name", "Name of person");
            requireField<WsjcppDtoInteger>("userid", "User Id");
            requireField<WsjcppDtoString>("", "Current Page");
            // requireField<WsjcppDtoPerson>("person", "Total");
            // TODO array
            // requireField<WsjcppDtoString>("name", "Name of person");
            // optionalField<WsjcppDtoPerson>("age", "Age of person");
        };
};

class WsjcppDtoPersonsPage : public WsjcppDto {
    public:
        WsjcppDtoPersonsPage() : WsjcppDto("persons_page", "Persons page") {
            // requireField<WsjcppDtoString>("name", "Name of person");
            requireField<WsjcppDtoInteger>("page", "Current Page");
            requireField<WsjcppDtoInteger>("onpage", "Nomebr per page");
            requireField<WsjcppDtoInteger>("total", "Total");
            // TODO array
            // requireField<WsjcppDtoString>("name", "Name of person");
            // optionalField<WsjcppDtoPerson>("age", "Age of person");
        };
};

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_APP_NAME);
    std::string appVersion = std::string(WSJCPP_APP_VERSION);
    if (!WsjcppCore::dirExists(".logs")) {
        WsjcppCore::makeDir(".logs");
    }
    WsjcppLog::setPrefixLogFile("wsjcpp");
    WsjcppLog::setLogDirectory(".logs");
    // TODO your code here

    WsjcppDtoPerson p;
    p.setFieldStringValue("name", "value");
    p.setFieldIntegerValue("age", 1);
    std::cout << p.toJson().dump() << std::endl;
    return 0;
}

