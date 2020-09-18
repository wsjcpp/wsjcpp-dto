# wsjcpp-dto

[![Build Status](https://api.travis-ci.com/wsjcpp/wsjcpp-dto.svg?branch=master)](https://travis-ci.com/wsjcpp/wsjcpp-dto) [![Total alerts](https://img.shields.io/lgtm/alerts/g/wsjcpp/wsjcpp-dto.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-dto/alerts/) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/wsjcpp/wsjcpp-dto.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-dto/context:cpp)

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
