// code_review.h
#ifndef CODE_REVIEW_H
#define CODE_REVIEW_H

#include <string>
#include <vector>

using namespace std; 

struct ReviewComment {
    string comment;
    int lineNumber;
    string reviewerName;
};

class CodeReview {
public:
    CodeReview(const string& codeFileName);
    void addComment(const ReviewComment& comment);
    void displayComments() const;

private:
    string codeFileName_;
    vector<ReviewComment> comments_;
};

#endif // CODE_REVIEW_H
