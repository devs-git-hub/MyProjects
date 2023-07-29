// user.cpp
#include "user.h"

using namespace std; 

User::User(const string& username, UserRole role) : username_(username), role_(role) {}

const string& User::getUsername() const {
    return username_;
}

UserRole User::getRole() const {
    return role_;
}

bool User::hasPermission(UserRole requiredRole) const {
    return static_cast<int>(role_) >= static_cast<int>(requiredRole);
}
