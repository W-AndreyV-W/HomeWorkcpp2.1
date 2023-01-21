#include <iostream>
#include <fstream>
#include <locale.h>


int main() {
    int sizarr1 = 0, sizarr2 = 0;
    int* arr1;
    int* arr2;
    setlocale(LC_ALL, "Russian");
    std::ifstream filein("in.txt");
    if (filein.is_open()) {
        filein >> sizarr1;
        arr1 = new int[sizarr1]();
        filein >> arr1[sizarr1 - 1];
        for (int i = 0; i < sizarr1 - 1; i++) {
            filein >> arr1[i];
        }
        filein >> sizarr2;
        arr2 = new int[sizarr2]();
        for (int i = 1; i < sizarr2; i++) {
            filein >> arr2[i];
        }
        filein >> arr2[0];
        filein.close();
    } else {
        std::cout << "Не получилось открыть файл - in.txt!" << std::endl;
        return 1;
    }
    std::ofstream fileout("out.txt");
    if (fileout.is_open()) {
        fileout << sizarr2;
        fileout << "\n";
        for (int i = 0; i < sizarr2; i++) {
            fileout << arr2[i];
            fileout << " ";
        }
        fileout << "\n";
        fileout << sizarr1;
        fileout << "\n";
        for (int i = 0; i < sizarr1; i++) {
            fileout << arr1[i];
            fileout << " ";
        }
        fileout << std::endl;
        fileout.close();
    } else {
        std::cout << "Не получилось открыть файл - out.txt!" << std::endl;
    }
    delete[] arr1;
    arr1 = nullptr;
    delete[] arr2;
    arr2 = nullptr;
}