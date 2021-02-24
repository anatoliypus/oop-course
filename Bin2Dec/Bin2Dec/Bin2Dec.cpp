#include <iostream>
#include <string>

struct Error {
  std::string message;
};

bool ConvertStrToInt(const std::string& str, size_t& res, Error& err) {
  try {
    size_t pos;
    res = std::stoi(str, &pos);
    if (std::to_string(res).length() != str.length()) {
      err.message = "Wrong characters in input number";
      return false;
    }
    return true;
  } catch (const std::exception&) {
    err.message = "Wrong input number";
    return false;
  }
};

bool ParseArgs(int argc, char* argv[], std::string& res, Error& err) {
  if (argc != 2) {
    err.message = "Wrong command line parameters given";
    return false;
  }
  res = argv[1];
  return true;
}

bool ConvertBinToDec(size_t num, size_t& res, Error& err) {
  res = 0;
  short int digit;
  size_t ratio = 1;
  while (num > 0) {
    digit = num % 10;
    num = num / 10;
    if (digit != 1 && digit != 0) {
      err.message = "Given number is not binary";
      return false;
    }
    res += digit * ratio;
    ratio *= 2;
  }
  return true;
}

int main(int argc, char* argv[]) {
  Error err;

  // получение аргумента командной строки
  std::string str_num;
  if (!ParseArgs(argc, argv, str_num, err)) {
    std::cout << err.message;
    return 1;
  }

  // перевод аргумента в число
  size_t num;
  if (!ConvertStrToInt(str_num, num, err)) {
    std::cout << err.message;
    return 1;
  }

  // конвертация
  size_t res;
  if (!ConvertBinToDec(num, res, err)) {
    std::cout << err.message;
    return 1;
  }

  std::cout << res << std::endl;
  return 0;
}
