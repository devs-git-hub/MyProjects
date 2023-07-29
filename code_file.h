// code_file.h
#ifndef CODE_FILE_H
#define CODE_FILE_H

#include <string>
#include <vector>

using namespace std; 

class CodeFile {
public:
    CodeFile(const string& filename);
    bool readContents(); // Read contents of the file
    const string& getFileName() const;
    const string& getFileContent() const;

private:
    string filename_;
    string content_;
};

#endif // CODE_FILE_H
