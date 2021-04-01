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

bool ReadDictionary(Dictionary& dict, std::string inputFile, Error& err);
bool ParseArgs(int argc, char* argv[], std::string& path);
std::string StrToLowerCase(std::string str);
std::string ModifyKey(std::string& key);
bool ProcessExit(std::string& str, int newTranslationsCounter, Dictionary& dict, std::string& dictPath);
void GetNewTranslation(Dictionary& dict, std::string& keyword, int& newTranslationsCounter);
void ProcessKeyword(Dictionary& dict, std::string& keyword, int& newTranslationsCounter);
void Conversation(Dictionary& dict, std::string& dictPath);
void DelayBeforeClose();
void ProcessInputFile(std::string fileName);
