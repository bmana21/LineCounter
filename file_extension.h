//
// Created on 29/06/2024.
//

#ifndef FILE_EXTENSION_H
#define FILE_EXTENSION_H

#include <string>
#include <vector>
#include <map>

using namespace std;

const map<string, vector<string> > FILE_EXTESIONS = {
    {"java", vector<string>{"java"}},
    {"kotlin", vector<string>{"kt"}},
    {"sql", vector<string>{"sql"}},
    {"c++", vector<string>{"cpp", "cxx", "h", "hpp", "hxx", "cc"}},
    {"cpp", vector<string>{"cpp", "cxx", "h", "hpp", "hxx", "cc"}},
    {"c#", vector<string>{"cs"}},
    {"c", vector<string>{"c", "h"}},
    {"python", vector<string>{"py"}},
    {"rust", vector<string>{"rs"}},
    {"javascript", vector<string>{"js"}},
    {"typescript", vector<string>{"ts"}},
    {"php", vector<string>{"php"}},
    {"go", vector<string>{"go"}},
    {"swift", vector<string>{"swift"}},
    {"xml", vector<string>{"xml"}},
    {"html", vector<string>{"html"}},
    {"css", vector<string>{"css"}},
    {"assembly", vector<string>{"asm", "s", "nasm", "a"}},
    {"perl", vector<string>{"pl"}},
};


#endif
