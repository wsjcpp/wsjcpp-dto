# wsjcpp-dto

[![Build Status](https://api.travis-ci.com/wsjcpp/wsjcpp-dto.svg?branch=master)](https://travis-ci.com/wsjcpp/wsjcpp-dto)

Helper classes for create C++ Data Transfer Object 

## Integrate to your project

Use a `wsjcpp`:

```
$ wsjcpp install https://github.com/wsjcpp/wsjcpp-dto:master
```

Or include this files:

* src.wsjcpp/nlohmann_json/json.hpp
* src/wsjcpp_dto.h
* src/wsjcpp_dto.cpp

## How to use

```
class WsjcppDtoPerson : public WsjcppDto {
    public:
        WsjcppDtoPerson() : WsjcppDto("person", "Person") {
            requireField<WsjcppDtoString>("name", "Name of person");
            optionalField<WsjcppDtoInteger>("age", "Age of person");
        };
};
```
