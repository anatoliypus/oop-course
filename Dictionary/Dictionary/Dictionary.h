#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <windows.h>

#define DEFAULT_FILENAME "../vocabulary.txt"

typedef std::unordered_map<std::string, std::string> Dictionary;
struct Error {
    std::string message;
};

bool ReadDictionary(Dictionary& dict, const std::string& inputFile, Error& err);
bool ParseArgs(int argc, char* argv[], std::string& path);
std::string StrToLowerCase(std::string str);
std::string ModifyKey(const std::string& key);
bool ProcessExit(const std::string& str, int newTranslationsCounter, Dictionary& dict, const std::string& dictPath);
void GetNewTranslation(Dictionary& dict, const std::string& keyword, int& newTranslationsCounter);
void ProcessKeyword(Dictionary& dict, const std::string& keyword, int& newTranslationsCounter);
void Conversation(Dictionary& dict, const std::string& dictPath);
void DelayBeforeClose();
void ProcessInputFile(const std::string& fileName);
