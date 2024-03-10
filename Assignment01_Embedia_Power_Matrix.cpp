//بسم الله الرحمن الرحيم 
//سمي الله قبل ما تجري الكود
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

long long myPow(long long base, int power) {
    long long result = 1;
    for (int i = 1; i <= power; i++) {
        result *= base;
    }
    return result;
}


int strToInt(const string& str) {
    int num = 0;
    for (char c : str) {
        if (c != '"' && c != '\''&& isdigit(c)) {
            num = num * 10 + (c - '0');
        }
    }
    return num;
}

bool isPower(vector<vector<string>>& arr) {
    bool flag = true;
    for (int i = 1; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            int base = strToInt(arr[i + 1][j]);
            int power = strToInt(arr[i - 1][j]);
            if (strToInt(arr[i][j]) != myPow(base, power)) {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }
    return flag;
}

int main() {
    int n, m;
    cout << "Enter N and M: ";
    cin >> n >> m;
    vector<vector<string>> arr(n, vector<string>(m));

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    if (isPower(arr)) {
        cout << "Embedia Power Matrix" << endl;
    }
    else {
        cout << "Not an Embedia Power Matrix" << endl;
    }
    return 0;
}