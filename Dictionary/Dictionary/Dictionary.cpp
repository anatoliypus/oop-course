#include "Dictionary.h"

bool ParseArgs(int argc, char* argv[], std::string& path)
{
    if (argc != 2) {
        return false;
    }
    path = argv[1];
    return true;
}

void ProcessInputFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file.good()) {
        std::ofstream newFile(fileName);
        newFile.close();
    }
}

bool ReadDictionary(Dictionary& dict, const std::string& inputFile, Error& err)
{
    std::ifstream input(inputFile);
    if (!input.is_open()) {
        err.message = "Failed to open dictionary file";
        return false;
    }

    std::string str, key, value;
    while (!input.eof()) {
        std::getline(input, str);
        if (str.empty()) {
            continue;
        }
        std::istringstream iStr(str);
        char ch;
        while (ch = iStr.get()) {
            key.push_back(ch);
            if (ch == ']') {
                break;
            }
        }
        std::string newWord;
        while (iStr >> newWord) {
            value += newWord;
            if (!iStr.eof()) {
                value += " ";
            }
        }
        if (value.empty()) {
            err.message = "Wrong dictionary file syntax";
            return false;
        }
        dict.emplace(key, value);
        value.clear();
        key.clear();
    }
    input.close();
    return true;
}

std::string StrToLowerCase(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](char ch) {
        return std::tolower(ch);
    });
    return str;
}

std::string ModifyKey(const std::string& key)
{
    return '[' + StrToLowerCase(key) + ']';
}

bool ProcessExit(const std::string& str, int newTranslationsCounter, Dictionary& dict, const std::string& dictPath)
{
    if (str == "...") {
        if (newTranslationsCounter) {
            std::cout << "В словарь было добавлено " << newTranslationsCounter << " новых переводов. Если хотите их сохранить, введите Y или y.\n";
            std::string inputStr;
            std::getline(std::cin, inputStr);
            if (inputStr == "y" || inputStr == "Y") {
                std::ofstream out(dictPath);
                std::for_each(dict.begin(), dict.end(), [&out, dict](std::pair<const std::string, std::string> el) {
                    std::string outStr = el.first + " " + el.second + "\n";
                    out << outStr;
                });
                out.flush();
                std::cout
                    << "Изменения сохранены. До свидания. \n";
            } else {
                std::cout << "Выход без сохранения новых переводов. До свидания. \n";
            }
        } else {
            std::cout << "До свидания \n";
        }
        return true;
    } else {
        return false;
    }
}

void GetNewTranslation(Dictionary& dict, const std::string& keyword, int& newTranslationsCounter)
{
    std::cout << "Неизвестное слово\" " << keyword << "\". Введите перевод или пустую строку для отказа." << std::endl;
    std::string inputStr;
    std::getline(std::cin, inputStr);
    if (!inputStr.empty()) {
        dict.insert({ ModifyKey(keyword), inputStr });
        newTranslationsCounter++;
        std::cout << "Слово \"" << keyword << "\" сохранено в словаре как \"" << inputStr << "\".\n";
    } else {
        std::cout << "Слово \"" << keyword << "\" проигнорировано" << std::endl;
    }
}

void ProcessKeyword(Dictionary& dict, const std::string& keyword, int& newTranslationsCounter)
{
    try {
        std::string value;
        std::cout << ModifyKey(keyword) << std::endl;
        value = dict.at(ModifyKey(keyword));
        std::cout << value << std::endl;
    } catch (std::exception&) {
        GetNewTranslation(dict, keyword, newTranslationsCounter);
    }
}

void Conversation(Dictionary& dict, const std::string& dictPath)
{
    std::cout << "Добро пожаловать в мини-словарь! Чтобы получить перевод, введите любое слово или фразу. Для выхода введите ..." << std::endl;
    std::string str;
    int newTranslationsCounter = 0;

    while (true) {
        std::getline(std::cin, str);
        if (ProcessExit(str, newTranslationsCounter, dict, dictPath)) {
            break;
        }
        ProcessKeyword(dict, str, newTranslationsCounter);
    }
}

void DelayBeforeClose()
{
    std::string str;
    std::cout << "Нажмите любую клавишу для выхода...";
    std::getline(std::cin, str);
}
