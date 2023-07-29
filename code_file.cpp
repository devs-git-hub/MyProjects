// code_file.cpp
#include "code_file.h"

#include <fstream>

using namespace std; 

CodeFile::CodeFile(const string& filename) : filename_(filename) {}

bool CodeFile::readContents() {
    ifstream file(filename_);
    if (!file) {
        return false; // Error reading the file
    }

    string line;
    while (getline(file, line)) {
        content_ += line + '\n';
    }

    file.close();
    return true;
}

const string& CodeFile::getFileName() const {
    return filename_;
}

const string& CodeFile::getFileContent() const {
    return content_;
}
