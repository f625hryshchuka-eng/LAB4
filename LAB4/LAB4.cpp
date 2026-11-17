#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <stdexcept>
#include "SphereInCube.h"

#ifdef _WIN32
#define NOMINMAX 
#include <windows.h>
#endif

using namespace std;

bool saveToFile(const SphereInCube& obj, const string& filename,
    ios::openmode mode, int setNumber) {
    ofstream fout(filename, mode);
    if (!fout.is_open()) {
        cerr << "Помилка: не вдалося відкрити файл " << filename << "\n";
        return false;
    }
    fout << fixed << setprecision(4);
    fout << "Комплект даних №" << setNumber << "\n";
    obj.print(fout);
    fout << "------------------------------------------------\n";
    fout.close();
    return true;
}

void showFile(const string& filename) {
    ifstream fin(filename);                
    if (!fin.is_open()) {
        cerr << "Помилка: не вдалося відкрити файл " << filename << "\n";
        return;
    }
    string line;
    while (getline(fin, line))
        cout << line << "\n";
    fin.close();
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    const string filename = "result.txt";
    bool firstWrite = true;              
    int setNumber = 0;

    cout << fixed << setprecision(4);
    cout << "Лабораторна робота №4. Множинне успадкування. Сфера, вписана у куб\n";

    while (true) {
        double a;
        cout << "\nВведіть довжину ребра куба a (0 - завершити): ";
        if (!(cin >> a)) {           
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Помилка: потрібно ввести число.\n";
            continue;
        }
        if (a == 0) break;

        ++setNumber;
        try {
            cout << "Створення об'єкта:\n";
            SphereInCube obj(a);

            cout << "\n";
            obj.print(cout);

            cout << "\nУсунення неоднозначності:\n"
                << "  obj.Sphere::volume() = " << obj.Sphere::volume() << "\n"
                << "  obj.Cube::volume()   = " << obj.Cube::volume() << "\n";

            ios::openmode mode = firstWrite ? (ios::out | ios::trunc) : ios::app;
            if (saveToFile(obj, filename, mode, setNumber)) {
                firstWrite = false;
                cout << "\nІнформацію записано у файл " << filename << "\n";
            }
            cout << "\nЗнищення об'єкта:\n";
        }  
        catch (const invalid_argument& e) {
            cout << "Помилка: " << e.what() << ". Об'єкт не створено.\n";
        }
    }

    cout << "\n===== Вміст файлу " << filename << " =====\n";
    showFile(filename);
    return 0;
}
