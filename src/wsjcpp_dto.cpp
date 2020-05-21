
#include "wsjcpp_dto.h"

#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// WsjcppDefineFieldDto

WsjcppDefineFieldDto::WsjcppDefineFieldDto(
    const std::string &sFieldTypeName,
    const std::string &sFieldName,
    const std::string &sFieldDescription
) {
    m_sFieldTypeName = sFieldTypeName;
    m_sFieldName = sFieldName;
    // validate name - only lowercase and _
    m_sFieldDescription = sFieldDescription;
}

// ---------------------------------------------------------------------

WsjcppDefineFieldDto & WsjcppDefineFieldDto::optional() {
    m_sFieldRestrict = "optional";
    return *this;
}

// ---------------------------------------------------------------------

WsjcppDefineFieldDto & WsjcppDefineFieldDto::required() {
    m_sFieldRestrict = "required";
    return *this;
}

// ---------------------------------------------------------------------

const std::string &WsjcppDefineFieldDto::getFieldTypeName() const {
    return m_sFieldTypeName;
}

// ---------------------------------------------------------------------

const std::string &WsjcppDefineFieldDto::getFieldName() const {
    return m_sFieldName;
}

// ---------------------------------------------------------------------

const std::string &WsjcppDefineFieldDto::getFieldRestrict() const {
    return m_sFieldRestrict;
}

// ---------------------------------------------------------------------

const std::string &WsjcppDefineFieldDto::getFieldDescription() const {
    return m_sFieldDescription;
}

// ---------------------------------------------------------------------
// WsjcppDtoString

WsjcppDtoString::WsjcppDtoString(const std::string &sName, const std::string &sDescription) 
: WsjcppDefineFieldDto("string", sName, sDescription) {

}

// ---------------------------------------------------------------------
// WsjcppDtoBoolean

WsjcppDtoBoolean::WsjcppDtoBoolean(const std::string &sName, const std::string &sDescription) 
: WsjcppDefineFieldDto("boolean", sName, sDescription) {

}

// ---------------------------------------------------------------------
// WsjcppDtoInteger

WsjcppDtoInteger::WsjcppDtoInteger(const std::string &sName, const std::string &sDescription) 
: WsjcppDefineFieldDto("integer", sName, sDescription) {
    
}

// ---------------------------------------------------------------------
// WsjcppDefineDto

WsjcppDefineDto::WsjcppDefineDto(const std::string &sTypeName, const std::string &sDescription) {
    TAG = "DTO-" + sTypeName;
    m_sTypeName = sTypeName;
    m_sDescription = sDescription;
}

// ---------------------------------------------------------------------

const std::string &WsjcppDefineDto::getTypeName() {
    return m_sTypeName;
}

// ---------------------------------------------------------------------

const std::string &WsjcppDefineDto::getDescription() {
    return m_sDescription;
}

// ---------------------------------------------------------------------

bool WsjcppDefineDto::setFieldStringValue(const std::string &sFieldName, const std::string &sFieldValue) {
    WsjcppDefineFieldDto *pField = this->findFieldByName(sFieldName);
    if (pField == nullptr) {
        WsjcppLog::throw_err(TAG, "Object '" + m_sTypeName + "' has not field '" + sFieldName + "'");
        return false;
    }

    // pField->isValid();
    // TODO call validators
    m_jsonReadyObject[sFieldName] = sFieldValue;
    return true;   
}

// ---------------------------------------------------------------------

bool WsjcppDefineDto::setFieldIntegerValue(const std::string &sFieldName, int nValue) {
    WsjcppDefineFieldDto *pField = this->findFieldByName(sFieldName);
    if (pField == nullptr) {
        WsjcppLog::throw_err(TAG, "Object '" + m_sTypeName + "' has not field '" + sFieldName + "'");
        return false;
    }
    // TODO call validators
    m_jsonReadyObject[sFieldName] = nValue;
    return true;   
}

// ---------------------------------------------------------------------

bool WsjcppDefineDto::setFieldBooleanValue(const std::string &sFieldName, bool bValue) {
    WsjcppDefineFieldDto *pField = this->findFieldByName(sFieldName);
    if (pField == nullptr) {
        WsjcppLog::throw_err(TAG, "Object '" + m_sTypeName + "' has not field '" + sFieldName + "'");
        return false;
    }
    // TODO call validators
    m_jsonReadyObject[sFieldName] = bValue;
    return true;
}

// ---------------------------------------------------------------------

bool WsjcppDefineDto::setFieldJsonValue(const std::string &sFieldName, const nlohmann::json &jsonFieldValue) {
    WsjcppDefineFieldDto *pField = this->findFieldByName(sFieldName);
    if (pField == nullptr) {
        WsjcppLog::throw_err(TAG, "Object '" + m_sTypeName + "' has not field '" + sFieldName + "'");
        return false;
    }
    // TODO call validators
    m_jsonReadyObject[sFieldName] = jsonFieldValue;
    return true;   
}

// ---------------------------------------------------------------------

bool WsjcppDefineDto::fillFromJson(nlohmann::json &jsonData, std::string &sError) {
    return false;
}

// ---------------------------------------------------------------------

nlohmann::json WsjcppDefineDto::toJson() {
    return m_jsonReadyObject;
}

// ---------------------------------------------------------------------

WsjcppDefineFieldDto *WsjcppDefineDto::findFieldByName(const std::string &sFieldName) {
    for (int i = 0; i < m_vFields.size(); i++) {
        if (m_vFields[i]->getFieldName() == sFieldName) {
            return m_vFields[i];
        }
    }
    return nullptr;
}


// ---------------------------------------------------------------------