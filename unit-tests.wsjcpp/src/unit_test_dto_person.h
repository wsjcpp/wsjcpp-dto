#ifndef UNIT_TEST_DTO_PERSON_H
#define UNIT_TEST_DTO_PERSON_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestDtoPerson : public WsjcppUnitTestBase {
    public:
        UnitTestDtoPerson();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_DTO_PERSON_H

