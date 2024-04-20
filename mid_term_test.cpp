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
    string danhsachMSSV[100];
    int soluong;
    cout << "Nhap so luong SV: ";
    cin >> soluong;
    for (int i = 0; i < soluong; i++) {
        cout << "Nhap MSSV cho sinh vien thu " << (i + 1) << ": ";
        cin >> danhsachMSSV[i];
    }

    cout << "Danh sach MSSV ban dau:\n";
    for (int i = 0; i < soluong; i++) {
        cout << danhsachMSSV[i] << ", ";
    }
    cout << endl;
    string sortedMSSV[100];
    copy(danhsachMSSV, danhsachMSSV + soluong, sortedMSSV);
    sort(sortedMSSV, sortedMSSV + soluong, compareMSSV);

    cout << "Danh sach MSSV sau khi sap xep:\n";
    for (int i = 0; i < soluong; i++) {
        cout<< sortedMSSV[i] << ", ";
    }
    cout << endl;
    string* ptrArrayMSSV = danhsachMSSV;
    string maxMSSV = *ptrArrayMSSV;
    int index = 0;
    for (int i = 1; i < soluong; i++) {
        if (*(ptrArrayMSSV + i) > maxMSSV) {
            maxMSSV = *(ptrArrayMSSV + i);
            index = i;
        }
    }

    cout << "Dia chi cua phan tu co MSSV lon nhat: " << (ptrArrayMSSV + index) << "\n";
    cout << "Phan tu co MSSV lon nhat: " << maxMSSV << "\n";

    return 0;
}
