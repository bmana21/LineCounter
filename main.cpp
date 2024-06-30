#include <iostream>
#include <ranges>
#include <set>

#include "file_extension.h"
#include "line_counter.h"
#include "SourceCodeData.h"

using namespace std;

bool get_file_extensions(int const argc, char **argv, set<string> &file_extensions_set) {
    for (int i = 2; i < argc; i++) {
        auto it = FILE_EXTESIONS.find(argv[i]);

        if (it == FILE_EXTESIONS.end()) {
            cerr << "Language " << argv[i] << " not found" << endl;
            cerr << "Available languages are: " << endl;
            for (const auto &lang: views::keys(FILE_EXTESIONS)) {
                cerr << lang << endl;
            }
            return false;
        }

        for (const auto &ext: it->second) {
            file_extensions_set.insert(ext);
        }
    }
    return true;
}

int main(int const argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Not enough arguments provided" << endl;
        cerr << "Usage: LineCounter folder lagnuage1 language2 language3 ..." << endl;
        return 1;
    }
    string path = argv[1];
    set<string> file_extensions_set;

    if (!get_file_extensions(argc, argv, file_extensions_set))
        return 1;

    const vector file_extensions(file_extensions_set.begin(), file_extensions_set.end());

    cout << "Listing source code data" << endl << endl;

    int total_lines = 0, total_files  = 0;

    for (const auto &data: count_lines(path, file_extensions)) {
        if (data.get_line_count() + data.get_file_count() == 0) {
            continue;
        }

        cout << "File extension: ." << data.get_file_extension() << endl;
        cout << "Number of files: " << data.get_file_count() << endl;
        cout << "Number of lines: " << data.get_line_count() << endl << endl;

        total_files += data.get_file_count();
        total_lines += data.get_line_count();
    }

    cout << "Total number of files: " << total_files << endl;
    cout << "Total number of lines: " << total_lines << endl;

    return 0;
}
