//
// Created by maorgo on 24/06/2023.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H
#include <stdexcept>
#include <string>

using namespace std;

class Exception: public runtime_error{
public:
    Exception(const string& what) :
            runtime_error(what){}
    virtual ~Exception() {}
};

class DeckFileNotFound : public Exception {
public:
    DeckFileNotFound() :
            Exception(string("Deck file not found")){}
};
class DeckFileFormatError : public Exception {
public:
    DeckFileFormatError(int lineNumber) : Exception(string("Deck File Error: File format error in line ")
                                                    + std::to_string(lineNumber)){}
};
class DeckFileInvalidSize : public Exception {
public:
    DeckFileInvalidSize() :
            Exception(string("Deck File Error: Deck size is invalid")){}
};



#endif //EX4_EXCEPTION_H
