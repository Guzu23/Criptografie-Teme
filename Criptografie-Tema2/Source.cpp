#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

//Complexitatea algoritmului este O(log_base{num}), sau O(num.length())
int toBase10(const string& num, int base) {
    int val = 0;
    int power = 1;

    for (int i = num.length() - 1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9') {
            val += (num[i] - '0') * power;
        }
        else if (num[i] >= 'A' && num[i] <= 'Z') {
            val += (num[i] - 'A' + 10) * power;
        }
        power = power * base;
    }

    return val;
}

//Complexitatea algoritmului este O(log_base{num})
string fromBase10(int num, int base) {
    string result = "";
    while (num > 0) {
        int digit = num % base;
        if (digit >= 0 && digit <= 9) {
            result += digit + '0';
        }
        else {
            result += digit - 10 + 'A';
        }
        num /= base;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num;
    int b1, b2;


    cout << "Introduceti baza initiala (2-26): ";
    cin >> b1;

    if (b1 < 2 || b1 > 26) {
        cout << "Bazele trebuie sa fie intre 2 si 26." << "\n";
        return 1;
    }


    cout << "Introduceti baza finala (2-26): ";
    cin >> b2;

    if (b2 < 2 || b2 > 26) {
        cout << "Bazele trebuie sa fie intre 2 si 26." << "\n";
        return 1;
    }

    cout << "Introduceti numarul pe care doriti sa il convertiti: ";
    cin >> num;



    int numInBase10 = toBase10(num, b1);
    cout << "Transformarea in baza 10 din baza " << b1 << " este: " << numInBase10 << "\n";
    string convertedNum = fromBase10(numInBase10, b2);

    cout << "Numrul convertit din baza " << b1 << " in baza " << b2 << " este: " << convertedNum << endl;

    return 0;
}