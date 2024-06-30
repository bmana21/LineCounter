//
// Created on 30/06/2024.
//

#ifndef SOURCECODEDATA_H
#define SOURCECODEDATA_H

#include <string>

using namespace std;


class SourceCodeData {
public:
    void set_file_extension(const string &file_extension) {
        this->file_extension = file_extension;
    }

    void set_line_count(const int line_count) {
        this->line_count = line_count;
    }

    void set_file_count(const int file_count) {
        this->file_count = file_count;
    }

    [[nodiscard]] string get_file_extension() const {
        return file_extension;
    }

    [[nodiscard]] int get_line_count() const {
        return line_count;
    }

    [[nodiscard]] int get_file_count() const {
        return file_count;
    }

    SourceCodeData() {
        file_extension = "";
        line_count = 0;
        file_count = 0;
    }

    SourceCodeData(const string &file_extension, const int line_count, const int file_count) {
        this->file_extension = file_extension;
        this->line_count = line_count;
        this->file_count = file_count;
    }

private:
    string file_extension;
    int line_count, file_count;
};


#endif //SOURCECODEDATA_H
