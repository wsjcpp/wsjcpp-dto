
#include "wsjcpp_dto.h"



WsjcppDto::WsjcppDto(const std::string &sObjectTypeName) {
    m_sObjectTypeName = sObjectTypeName;
}

// ---------------------------------------------------------------------

std::string WsjcppDto::getObjectTypeName() {
    return m_sObjectTypeName;
}

// ---------------------------------------------------------------------