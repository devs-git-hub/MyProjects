// user.h
#ifndef USER_H
#define USER_H

#include <string>

using namespace std; 

enum class UserRole {
    Developer,
    Reviewer,
    Administrator
};

class User {
public:
    User(const string& username, UserRole role);
    const string& getUsername() const;
    UserRole getRole() const;
    bool hasPermission(UserRole requiredRole) const;

private:
    string username_;
    UserRole role_;
};

#endif // USER_H
