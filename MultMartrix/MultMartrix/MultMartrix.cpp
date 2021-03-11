#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

struct Error {
    std::string message;
};

struct Files {
    std::string fileName1, fileName2;
};

typedef double Matrix3x3[3][3];

bool ReadMatrix3x3(const std::string& fileName, Matrix3x3& matrix, Error& err)
{
    std::ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        err.message = "Could not open file with name " + fileName;
        return false;
    }

    std::string str;
    double num;
    int rows = 0;
    int cols = 0;
    while (!file.eof() && rows < 3) {
        std::getline(file, str);
        std::istringstream iStr(str);
        for (int i = 1; i <= 3; i++) {
            if (iStr.eof()) {
                err.message = "Given matrix is not full. Input file has to contain at least 3 columns";
                return false;
            }
            if (!(iStr >> num)) {
                err.message = "Error in matrix values. You have to give only numeric values.";
                return false;
            }
            matrix[rows][cols] = num;
            cols++;
        }
        rows++;
        cols = 0;
    }

    if (rows < 3) {
        err.message = "Given matrix is not full. Input file has to contain at least 3 rows";
        return false;
    }

    return true;
}

bool ParseArgs(int argc, char* const argv[], Error& err, Files& files)
{
    if (argc != 3) {
        err.message = "Wrong parameters given. Required parameters: <inputMatrixFilename1> <inputMatrixFilename2>";
        return false;
    }
    files.fileName1 = argv[1];
    files.fileName2 = argv[2];
    return true;
}

void MultMatrix3x3(const Matrix3x3& m1, const Matrix3x3& m2, Matrix3x3& res)
{
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            double sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += m1[k][j] * m2[j][i];
            }
            res[k][i] = sum;
        }
    }
}

void WriteOutMatrix3x3(const Matrix3x3& m)
{
    std::cout.precision(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[])
{
    Error err;
    Files files;
    if (!ParseArgs(argc, argv, err, files)) {
        std::cout << err.message << std::endl;
        return 1;
    }

    Matrix3x3 matrix1;
    if (!ReadMatrix3x3(files.fileName1, matrix1, err)) {
        std::cout << err.message << std::endl;
        return 1;
    }

    Matrix3x3 matrix2;
    if (!ReadMatrix3x3(files.fileName2, matrix2, err)) {
        std::cout << err.message << std::endl;
        return 1;
    }

    Matrix3x3 result;
    MultMatrix3x3(matrix1, matrix2, result);

    WriteOutMatrix3x3(result);
}
