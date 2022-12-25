// siaod8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include <ctime>
using namespace std;
static unsigned long global_counter = 0;
unsigned long long recAlg(int n, int m) {
    if (n <= 1 || m <= 1) {
        global_counter += 3;//первый if, 2 сравнения и 1 или
        return 1;
    }
    global_counter += 3;//первый if, 2 сравнения и 1 или
    global_counter += 3;//return, в котором 1 сложение и 2 вычитания
    return recAlg(n - 1, m) + recAlg(n, m - 1);
}

unsigned long long dynamicRec(int n, int m, map<vector<int>, unsigned long long>& table) {
    if (table[{n, m}] != 0) {
        global_counter += 1;//первый if, 1 сравнение
    }
    else {
        global_counter += 1;//первый if, 1 сравнение
        if (n <= 1 || m <= 1) {
            global_counter += 3;//второй if, 2 сравнения и 1 или
            table[{n, m}] = 1;
            table[{m, n}] = 1;
            return 1;
        }
        global_counter += 3;//второй if, 2 сравнения и 1 или
        global_counter += 3;//присвоение, в котором 1 сложение и 2 вычитания
        table[{n, m}] = dynamicRec(n - 1, m, table) + dynamicRec(n, m - 1, table);
        table[{m, n}] = table[{n, m}];
    }
    return table[{n, m}];
}
unsigned long long dynamicAlg(int n, int m) {
    map<vector<int>, unsigned long long> table;
    return dynamicRec(n, m, table);
}
int main()
{
    unsigned long timer;
    cout << "There is a field N x M.\nN = ";
    int n, m;
    cin >> n;
    cout << "M = ";
    cin >> m;
    unsigned long long answer;
    timer = clock();
    answer = recAlg(n, m);
    timer = clock() - timer;
    cout << "NORMAL RECURSION ALG:\n" << answer << " ways to get from cell (1,1) to cell (" << n << "," << m << ")\n" << global_counter << " operations were done.\n";
    cout << "time spent: " << timer / 1000.0 << "s\n";
    global_counter = 0;
    timer = clock();
    answer = dynamicAlg(n, m);
    timer = clock() - timer;
    cout << "\nRECURSION ALG WITH MAP:\n" << answer << " ways to get from cell (1,1) to cell (" << n << "," << m << ")\n" << global_counter << " operations were done.\n";
    cout << "time spent: " << timer / 1000.0 << "s\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
