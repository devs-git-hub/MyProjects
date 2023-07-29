// code_review.cpp
#include "code_review.h"
#include <iostream>

using namespace std; 

CodeReview::CodeReview(const string& codeFileName) : codeFileName_(codeFileName) {}

void CodeReview::addComment(const ReviewComment& comment) {
    comments_.push_back(comment);
}

void CodeReview::displayComments() const {
    cout << "Code Review for \"" << codeFileName_ << "\":\n";
    for (const auto& comment : comments_) {
        cout << "Reviewer: " << comment.reviewerName << ", Line " << comment.lineNumber << ": " << comment.comment << '\n';
    }
}
