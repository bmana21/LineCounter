//
// Created by home on 29/06/2024.
//

#include "line_counter.h"

string to_lower_string(const string &str) {
    string result;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            result += tolower(str[i]);
        } else {
            result += str[i];
        }
    }
    return result;
}

string get_file_extension(const string &file_path) {
    if (file_path.find('.') == string::npos) {
        return "";
    }
    string extension;

    for (int i = static_cast<int>(file_path.size()) - 1; i >= 0; i--) {
        if (file_path[i] == '.') {
            break;
        }
        extension = file_path[i] + extension;
    }

    return extension;
}

SourceCodeData count_lines_of_extension(const fs::path &path, const string &extension) {
    SourceCodeData source_code_data(extension, 0, 0);

    if (is_regular_file(path)) {
        auto file_extension = get_file_extension(path.string());
        if (to_lower_string(file_extension) != extension) {
            return {};
        }
        ifstream inFile(path.string());
        return SourceCodeData{
            extension,
            static_cast<int>(count(istreambuf_iterator(inFile), istreambuf_iterator<char>(), '\n')),
            1
        };
    }
    if (is_directory(path)) {
        for (const auto &entry: fs::directory_iterator(path)) {
            SourceCodeData folder_result = count_lines_of_extension(entry.path(), extension);
            source_code_data.set_line_count(source_code_data.get_line_count() + folder_result.get_line_count());
            source_code_data.set_file_count(source_code_data.get_file_count() + folder_result.get_file_count());
        }
        return source_code_data;
    }

    return source_code_data;
}

vector<SourceCodeData> count_lines(const string &path, const vector<string> &file_extensions) {
    vector<SourceCodeData> result;
    for (const auto &extension: file_extensions) {
        result.push_back(count_lines_of_extension(fs::path(path), to_lower_string(extension)));
    }
    return result;
}
