
#include "wsjcpp_dto.h"

WsjcppDto::WsjcppDto(const std::string &sObjectTypeName) {
    m_sObjectTypeName = sObjectTypeName;
}

// ---------------------------------------------------------------------

std::string WsjcppDto::getObjectTypeName() {
    return m_sObjectTypeName;
}

// ---------------------------------------------------------------------

bool WsjcppDto::fillFromJson(nlohmann::json &jsonData, std::string &sError) {
    return false;
}

// ---------------------------------------------------------------------

nlohmann::json WsjcppDto::toJson() {
    nlohmann::json jsonRet;
    return jsonRet;
}

// ---------------------------------------------------------------------