#include "unit_test_dto_person.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_dto.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestDtoPerson)

UnitTestDtoPerson::UnitTestDtoPerson()
    : WsjcppUnitTestBase("UnitTestDtoPerson") {
}

// ---------------------------------------------------------------------

bool UnitTestDtoPerson::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

class WsjcppDtoPerson : public WsjcppDto {
    public:
        WsjcppDtoPerson() : WsjcppDto("person", "Person") {
            requireField<WsjcppDtoString>("name", "Name of person");
            optionalField<WsjcppDtoInteger>("age", "Age of person");
        };
};

// ---------------------------------------------------------------------

void UnitTestDtoPerson::executeTest() {
    WsjcppDtoPerson p;
    p.setFieldStringValue("name", "John Smith");
    p.setFieldIntegerValue("age", 21);
    std::string sJsonGot = p.toJson().dump();
    std::string sJsonExpected = "{\"age\":21,\"name\":\"John Smith\"}";
    compare("WsjcppDtoPerson", sJsonGot, sJsonExpected);
}

// ---------------------------------------------------------------------

bool UnitTestDtoPerson::doAfterTest() {
    // nothing
    return true;
}
