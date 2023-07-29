// main.cpp
#include <iostream>
#include "code_file.cpp"
#include "code_review.cpp"
#include "collaboration_platform.cpp"
#include "user.cpp"

int main() {
    // For simplicity, hardcoding a single user with a specific role (You can modify this part for user authentication)
    User currentUser("JohnDoe", UserRole::Reviewer);

    std::string filename;
    std::cout << "Enter the name of the code file to upload: ";
    std::cin >> filename;

    CodeFile codeFile(filename);
    if (codeFile.readContents()) {
        std::cout << "Code file \"" << codeFile.getFileName() << "\" uploaded successfully.\n";
        std::cout << "Code Content:\n";
        std::cout << codeFile.getFileContent() << std::endl;

        CollaborationPlatform platform(filename, currentUser);

        // Allow user to write review comments
        std::string commentText;
        int lineNumber;
        std::cout << "Enter the line number to comment on: ";
        std::cin >> lineNumber;
        std::cin.ignore(); // Ignore the newline character left in the input buffer

        std::cout << "Write your comment: ";
        std::getline(std::cin, commentText);

        ReviewComment userComment = { commentText, lineNumber, currentUser.getUsername() };
        platform.addCommentToReview(userComment, currentUser);

        // Display all code review comments
        platform.displayAllComments();
    } else {
        std::cout << "Error: Unable to read the code file.\n";
    }

    return 0;
}
