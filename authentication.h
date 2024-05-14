#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <map>

class Authentication {
public:
    Authentication();
    bool login(const std::string& username, const std::string& password);
private:
    std::map<std::string, std::string> userPasswords;
};

#endif
