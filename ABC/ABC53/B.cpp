#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int s = str.find('A');
    int e = str.rfind('Z');

    cout << e - s + 1 << endl;

    return 0;
}