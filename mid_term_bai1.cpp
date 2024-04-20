#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compareMSSV(string a, string b) {
    string prefixA = a.substr(0, 4);
    string prefixB = b.substr(0, 4);
    if (prefixA == prefixB) {
        return a < b;
    }
    return prefixA < prefixB;
}

int main() {
    string danhsachMSSV[5] = { "", "2301CT1234", "2302CT3456", "2305CT3999", "2304CT0002" };

    cout << "Nhap MSSV: ";
    cin >> danhsachMSSV[0];

    cout << "Danh sach MSSV ban dau:\n";
    for (int i = 0; i < 5; i++) {
        cout << danhsachMSSV[i] << "\n";
    }

    string sortedMSSV[5];
    copy(danhsachMSSV, danhsachMSSV + 5, sortedMSSV);
    sort(sortedMSSV, sortedMSSV + 5, compareMSSV);

    cout << "Danh sach MSSV sau khi sap xep:\n";
    for (int i = 0; i < 5; i++) {
        cout << sortedMSSV[i] << "\n";
    }

    string* ptrArrayMSSV = danhsachMSSV;
    string maxMSSV = *ptrArrayMSSV;
    int index = 0;
    for (int i = 1; i < 5; i++) {
        if (*(ptrArrayMSSV + i) > maxMSSV) {
            maxMSSV = *(ptrArrayMSSV + i);
            index = i;
        }
    }

    cout << "Dia chi cua phan tu co MSSV lon nhat: " << (ptrArrayMSSV + index) << "\n";
    cout << "Phan tu co MSSV lon nhat: " << maxMSSV << "\n";

    return 0;
}
