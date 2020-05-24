#ifndef WSJCPP_DTO_H
#define WSJCPP_DTO_H

#include <string>
#include <vector>
#include <json.hpp>

// ---------------------------------------------------------------------
// WsjcppDefineFieldDto
    
class WsjcppDefineFieldDto {
    public:
        WsjcppDefineFieldDto(
            const std::string &sFieldTypeName,
            const std::string &sFieldName,
            const std::string &sFieldDescription
        );
        WsjcppDefineFieldDto();
        WsjcppDefineFieldDto & optional();
        WsjcppDefineFieldDto & required();
        
        const std::string &getFieldTypeName() const;
        const std::string &getFieldName() const;
        const std::string &getFieldRestrict() const;
        const std::string &getFieldDescription() const;

        bool isRequired();

        // WsjcppMemberDto &addValidator(WsjcppValidatorStringBase *pValidatorStringBase);
        // const std::vector<WsjcppValidatorStringBase *> &listOfValidators();

    private:
        std::string m_sFieldTypeName;
        std::string m_sFieldName;
        std::string m_sFieldRestrict;
        std::string m_sFieldDescription;

        // std::vector<WsjcppValidatorStringBase *> m_vValidatorsString;
};

// ---------------------------------------------------------------------
// WsjcppDtoString

class WsjcppDtoString : public WsjcppDefineFieldDto {
    public:
        WsjcppDtoString(const std::string &sName, const std::string &sDescription);
};

// ---------------------------------------------------------------------
// WsjcppDtoInteger

class WsjcppDtoInteger : public WsjcppDefineFieldDto {
    public:
        WsjcppDtoInteger(const std::string &sName, const std::string &sDescription);
};

// ---------------------------------------------------------------------
// WsjcppDtoBoolean

class WsjcppDtoBoolean : public WsjcppDefineFieldDto {
    public:
        WsjcppDtoBoolean(const std::string &sName, const std::string &sDescription);
};

// ---------------------------------------------------------------------
// WsjcppDto - parent class for Data Transfer Objects

class WsjcppDto {
    public:
        WsjcppDto(const std::string &sTypeName, const std::string &sDescription);
        const std::string &getTypeName();
        const std::string &getDescription();

        template<typename T>
        T &requireField(const std::string &sName, const std::string &sDescription) {
            T *pField = new T(sName, sDescription);
            pField->required();
            m_vFields.push_back(pField);
            WsjcppDefineFieldDto *pAddedField = m_vFields[m_vFields.size()-1];
            return *((T *)pAddedField);
        }

        template<typename T>
        T &optionalField(const std::string &sName, const std::string &sDescription) {
            T *pField = new T(sName, sDescription);
            pField->optional();
            m_vFields.push_back(pField);
            WsjcppDefineFieldDto *pAddedField = m_vFields[m_vFields.size()-1];
            return *((T *)pAddedField);
        }

// TODO check duplicates
    /*CmdInputDef pStringDef(sName, sDescription);
    pStringDef.string_().required();
    m_vInputs.push_back(pStringDef);
    return m_vInputs[m_vInputs.size()-1];*/

        /*WsjcppMemberDto &requireStringMember(const std::string &sName, const std::string &sDescription);
        WsjcppMemberDto &optionalStringMember(const std::string &sName, const std::string &sDescription);
        WsjcppMemberDto &requireIntegerMember(const std::string &sName, const std::string &sDescription);
        WsjcppMemberDto &optionalIntegerMember(const std::string &sName, const std::string &sDescription);
        WsjcppMemberDto &requireBooleanMember(const std::string &sName, const std::string &sDescription);
        WsjcppMemberDto &optionalBooleanMember(const std::string &sName, const std::string &sDescription);
*/
        bool setFieldStringValue(const std::string &sFieldName, const std::string &sValue);
        bool setFieldIntegerValue(const std::string &sFieldName, int nValue);
        bool setFieldBooleanValue(const std::string &sFieldName, bool bValue);
        bool setFieldJsonValue(const std::string &sFieldName, const nlohmann::json &jsonValue);

        bool fillFromJson(nlohmann::json &jsonData, std::string &sError);
        nlohmann::json toJson();

    private:
        std::string TAG;
        std::string m_sTypeName;
        std::string m_sDescription;
        
        std::vector<WsjcppDefineFieldDto *> m_vFields;
        nlohmann::json m_jsonReadyObject;

        WsjcppDefineFieldDto *findFieldByName(const std::string &sFieldName);
};

#endif // WSJCPP_DTO_H