#include <iostream>

using namespace std;

int n, s, B, k, i = 0;
int W[36][251];
int a[35]; //вес предметов
void Print(int s, int n) {

    if (W[s][n] == 0) // максимальный рюкзак для параметров (s,n)
        return;        // имеет нулевую ценность
        // поэтому ничего не выводим
    else if (W[s - 1][n] == W[s][n])
        Print(s - 1, n);  // можно составить рюкзак без предмета s
    else {
        Print(s - 1, n - a[s]); // предмет s должен
        cout << W[s][n]<< endl;     // войти в рюкзак
    }
}

int main() {
    cin >> B; //ограничение объема рюкзака по весу
    cin >> k; //количество предметов
    int c[k];   //стоимость
    for (i = 0; i < k; i++) {
        cin >> a[i];
        cin >> c[i];
    }
    for (n = 0; n <= B; n++)       // заполняем нулевой ряд
        W[0][n] = 0;
    for (s = 1; s <= k; s++)       // s - максимальный номер предмета,
    {                       // который можно использовать
        for (n = 0; n <= B; n++)   // n – объем рюкзака
        {
            W[s][n] = W[s - 1][n];
            if (n >= a[s - 1] && (W[s - 1][n - a[s - 1]] + c[s - 1] > W[s][n]))
                W[s][n] = W[s - 1][n - a[s - 1]] + c[s - 1];
        }
    }
    cout << "Array W(s)(n)" << endl;
    for (s = 1; s <= k; s++) {
        for (n = 0; n <= B; n++)
            cout << W[s][n] << ' ';
        cout << endl;
    }
    cout << endl;
    cout << "Rucksack includes these items:" << endl;
    Print(k, B);
    cin.get();
    return 0;
}