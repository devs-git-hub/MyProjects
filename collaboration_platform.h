// collaboration_platform.h
#ifndef COLLABORATION_PLATFORM_H
#define COLLABORATION_PLATFORM_H

#include "code_review.h"
#include "user.h"
#include <vector>

using namespace std; 

class CollaborationPlatform {
public:
    CollaborationPlatform(const string& codeFileName, const User& currentUser);
    void addCommentToReview(const ReviewComment& comment, const User& user);
    void displayAllComments() const;

private:
    string codeFileName_;
    CodeReview codeReview_;
    vector<User> users_;
};

#endif // COLLABORATION_PLATFORM_H
