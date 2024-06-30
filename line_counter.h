//
// Created on 29/06/2024.
//

#ifndef LINE_COUNTER_H
#define LINE_COUNTER_H

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "SourceCodeData.h"

using namespace std;
namespace fs = filesystem;

string to_lower_string(const string &str);

SourceCodeData count_lines_of_extension(const fs::path &path, const string &extension);

vector<SourceCodeData> count_lines(const string &path, const vector<string> &file_extensions);

#endif //LINE_COUNTER_H
