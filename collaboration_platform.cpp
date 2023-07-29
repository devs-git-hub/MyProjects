// collaboration_platform.cpp
#include "collaboration_platform.h"
#include <iostream>

using namespace std; // 

CollaborationPlatform::CollaborationPlatform(const string& codeFileName, const User& currentUser)
    : codeFileName_(codeFileName), codeReview_(codeFileName), users_{currentUser} {}

void CollaborationPlatform::addCommentToReview(const ReviewComment& comment, const User& user) {
    if (user.hasPermission(UserRole::Reviewer)) {
        codeReview_.addComment(comment);
    } else {
        cout << "Error: User " << user.getUsername() << " does not have permission to add comments.\n";
    }
}

void CollaborationPlatform::displayAllComments() const {
    codeReview_.displayComments();
}
