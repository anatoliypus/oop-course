#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <windows.h>

#define INPUT_FILENAME "vocabulary.txt"

typedef std::unordered_map<std::string, std::string> Dictionary;
struct Error {
    std::string message;
};

bool ReadDictionary(Dictionary& dict, std::string inputFile, Error& err);
std::string StrToLowerCase(std::string str);
std::string ModifyKey(std::string& key);
bool ProcessExit(std::string& str, int newTranslationsCounter, Dictionary& dict);
void GetNewTranslation(Dictionary& dict, std::string& keyword, int& newTranslationsCounter);
void ProcessKeyword(Dictionary& dict, std::string& keyword, int& newTranslationsCounter);
void Conversation(Dictionary& dict);
void DelayBeforeClose();
