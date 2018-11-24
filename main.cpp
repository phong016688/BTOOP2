#include <iostream>
#include "Vecto.h"
#include "Matrix.h"
#include "Polynomial.h"

using namespace std;

int main() {
    int chonlop;
    int chontest;
    while (true) {
        cout << "|----------------------------|" << endl
             << "| Hay lua chon lop de Test   |" << endl
             << "| 1: lop Vector              |" << endl
             << "| 2: lop Matrix              |" << endl
             << "| 3: lop Polynomial          |" << endl
             << "| 0: thoat chuong trinh      |" << endl
             << "|----------------------------|" << endl;
        do {
            cout << "hay chon lop muon test" << endl;
            cin >> chonlop;
        } while (chonlop < 0 || chonlop > 3);
        if (chonlop == 0)
            return 0;
        switch (chonlop) {
            case 1: {
                do {
                    cout << "|-----------------------------------|" << endl
                         << "|------------LOP VECTOR-------------|" << endl
                         << "| Hay lua chon toan tu de Test      |" << endl
                         << "| 1: nhap vector(>>)                |" << endl
                         << "| 2: xuat vector(<<)                |" << endl
                         << "| 3: cong hai vector(+)             |" << endl
                         << "| 4: tru hai vector(-)              |" << endl
                         << "| 5: nhan hai vector(*)             |" << endl
                         << "| 6: gan vector(=)                  |" << endl
                         << "| 7: truy xuat phan tu vector([])   |" << endl
                         << "| 8: tinh do dai cua vector(^)      |" << endl
                         << "| 0: quay lai                       |" << endl
                         << "|-----------------------------------|" << endl;
                    Vecto vecto;
                    do {
                        cout << "nhap lua chon: ";
                        cin >> chontest;
                        if (chontest < 0 || chontest > 8)
                            cout << "lua chon khong hop le" << endl;
                    } while (chontest < 0 || chontest > 8);
                    switch (chontest) {
                        case 1: {
                            cin >> vecto;
                            cout << "vector vua nhap la: \n";
                            cout << vecto << endl;
                            break;
                        }
                        case 2: {
							cout << "ban phai nhap vector truoc:\n";
							cin >> vecto;
							cout << "in ra vector :\n";
                            cout << vecto << endl;
                            break;
                        }
                        case 3: {
                            Vecto v1, v2;
                            cout << "nhap vector 1: \n";
                            cin >> v1;
                            cout << "nhap vector 2: \n";
                            cin >> v2;
                            cout << "v1 = " << v1 << endl;
                            cout << "v2 = " << v2 << endl;
                            try {
                                cout << "v1 + v2 = " << (v1 + v2) << endl;
                            } catch (char const *msg) { cout << msg; }
                            break;
                        }
                        case 4: {
                            Vecto v1, v2;
                            cout << "nhap vector 1: \n";
                            cin >> v1;
                            cout << "nhap vector 2(cung so chieu): \n";
                            cin >> v2;
                            cout << "v1 = " << v1 << endl;
                            cout << "v2 = " << v2 << endl;
                            try {
                                cout << "v1 - v2 = " << (v1 - v2) << endl;
                            } catch (char const *msg) { cout << msg; }
                            break;
                        }
                        case 5: {
                            Vecto v1, v2;
                            cout << "nhap vector 1: \n";
                            cin >> v1;
                            cout << "nhap vector 2: \n";
                            cin >> v2;
                            cout << "v1 = " << v1 << endl;
                            cout << "v2 = " << v2 << endl;
                            try {
                                cout << "v1 * v2 = " << (v1 * v2) << endl;
                            } catch (char const *msg) { cout << msg; }
                            break;
                        }
                        case 6: {
                            Vecto v1, v2;
                            cout << "nhap vector 1: \n";
                            cin >> v1;
                            cout << "v1 = " << v1 << endl;
                            v2 = v1;
                            cout << "v2 = v1 =" << v2 << endl;
                            break;
                        }
                        case 7: {
                            Vecto v;
                            int index;
                            cout << "nhap vector: ";
                            cin >> v;
                            cout << "vector vua nhap la: \n";
                            cout << v << endl;
                            do {
                                cout << "nhap vi tri muon truy xuat:";
                                cin >> index;
                                if(index < 0 ||index >= v.getN())
                                    cout << "vi tri khong hop le\n";
                            }while (index < 0 ||index >= v.getN());
                            cout << "gia tri cua vetor v tai vi tri " << index << " la: " ;
                            cout << v[index] << endl;
                            break;
                        }
                        case 8:{
                            Vecto v;
                            cout << "nhap vector: ";
                            cin >> v;
                            cout << "vector vua nhap la: \n";
                            cout << v << endl;
                            cout << "do dai vector do la: " << (v^1) << endl;
                            break;
                        }
                    }
                } while (chontest != 0);
                break;
            }
            case 2: {
                do {
                    cout << "|-------------------------------------|" << endl
                         << "|------------LOP MA TRAN--------------|" << endl
                         << "| Hay lua chon toan tu de Test        |" << endl
                         << "| 1: nhap ma tran(>>)                 |" << endl
                         << "| 2: xuat ma tran(<<)                 |" << endl
                         << "| 3: cong hai ma tran(+)              |" << endl
                         << "| 4: tru hai ma tran(-)               |" << endl
                         << "| 5: nhan hai ma tran(*)              |" << endl
                         << "| 6: gan ma tran(=)                   |" << endl
                         << "| 7: truy xuat phan tu cua ma tran(())|" << endl
                         << "| 8: tinh dinh thuc cua ma tran       |" << endl
                         << "| 0: quay lai                         |" << endl
                         << "|-------------------------------------|" << endl;
                    Matrix matrix;
                    do {
                        cout << "nhap lua chon: ";
                        cin >> chontest;
                        if (chontest < 0 || chontest > 8)
                            cout << "lua chon khong hop le" << endl;
                    } while (chontest < 0 || chontest > 8);
                    switch (chontest) {
                        case 1: {
                            cin >> matrix;
                            cout << " ma tran vua nhap la: \n";
                            cout << matrix << endl;
                            break;
                        }
                        case 2: {
							cout << "ban phai nhap ma tran truoc:\n";
							cin >> matrix;
							cout << "in ra ma tran :\n";
                            cout << matrix << endl;
                            break;
                        }
                        case 3: {
                            Matrix p1, p2, p3;
                            cout << "nhap ma tran 1: \n";
                            cin >> p1;
                            cout << "nhap ma tran 2: \n";
                            cin >> p2;
                            cout << "p1 :\n" << p1 << endl;
                            cout << "p2 :\n" << p2 << endl;
                            try {
                                p3 = p1 + p2;
                            } catch (const char *msg) {
                                cout << msg;
                            }
                            cout << "p1 + p2 :\n" << p3 << endl;
                            break;
                        }
                        case 4: {
                            Matrix p1, p2, p3;
                            cout << "nhap ma tran 1: \n";
                            cin >> p1;
                            cout << "nhap ma tran 2: \n";
                            cin >> p2;
                            cout << "p1 :\n" << p1 << endl;
                            cout << "p2 :\n" << p2 << endl;
                            try {
                                p3 = p1 - p2;
                            } catch (const char *msg) {
                                cout << msg;
                            }
                            cout << "p1 - p2 :\n" << p3 << endl;
                            break;
                        }
                        case 5: {
                            Matrix p1, p2, p3;
                            cout << "nhap ma tran 1: \n";
                            cin >> p1;
                            cout << "nhap ma tran 2: \n";
                            cin >> p2;
                            cout << "p1 :\n" << p1 << endl;
                            cout << "p2 :\n" << p2 << endl;
                            try {
                                p3 = p1 * p2;
                            } catch (const char *msg) {
                                cout << msg;
                            }
                            cout << "p1 * p2 :\n" << p3 << endl;
                            break;
                        }
                        case 6: {
                            Matrix p1, p2;
                            cout << "nhap ma tran 1: \n";
                            cin >> p1;
                            cout << "p1 = " << p1 << endl;
                            p2 = p1;
                            cout << "p2 = p1 =" << p2 << endl;
                            break;
                        }
                        case 7: {
                            Matrix p;
                            int hang, cot;
                            cout << "nhap ma tran: \n";
                            cin >> p;
                            cout << "ma tran hien tai: \n" << p;
                            do {
                                cout << "nhap chi so muon truy cap: \n";
                                cout << "hang :";
                                cin >> hang;
                                cout << "cot: ";
                                cin >> cot;
                                if (hang < 0 || cot < 0 || hang > p.getHang() || cot > p.getCot())
                                    cout << "ban nhap chi so khong hop le \n";
                            } while (hang < 0 || cot < 0 || hang > p.getHang() || cot > p.getCot());
                            cout << "gia tri cua phan tu co chi so (" << hang << "," << cot << ") la: ";
                            try {
                                cout << p(hang -1, cot-1) << endl;
                            } catch (const char *msg) {
                                cout << msg;
                            }
                            break;
                        }
                        case 8: {
                            Matrix p;
                            cout << "nhap ma tran(so hang = so cot): \n";
                            cin >> p;
                            cout << "ma tran hien tai: \n" << p;
                            try {
                                cout << "det(p) = " << (p ^ 1);
                            } catch (const char *msg) {
                                cout << msg;
                            }
                            break;
                        }
                    }
                } while (chontest != 0);
                break;
            }

            case 3: {
                do {
                    cout << "|-------------------------------------|" << endl
                         << "|------------LOP DA THUC--------------|" << endl
                         << "| Hay lua chon toan tu de Test        |" << endl
                         << "| 1: nhap da thuc(>>)                 |" << endl
                         << "| 2: xuat da thuc(<<)                 |" << endl
                         << "| 3: cong hai da thuc(+)              |" << endl
                         << "| 4: tru hai da thuc(-)               |" << endl
                         << "| 5: nhan hai da thuc(*)              |" << endl
                         << "| 6: gan da thuc(=)                   |" << endl
                         << "| 7: truy xuat he so cua da thuc([])  |" << endl
                         << "| 8: tinh gia tri cua da thuc         |" << endl
                         << "| 0: quay lai                         |" << endl
                         << "|-------------------------------------|" << endl;
                    Polynomial polynomial;
                    do {
                        cout << "nhap lua chon: ";
                        cin >> chontest;
                        if (chontest < 0 || chontest > 8)
                            cout << "lua chon khong hop le" << endl;
                    } while (chontest < 0 || chontest > 8);
                    switch (chontest) {
                        case 1: {
                            cin >> polynomial;
                            cout << "Da thuc vua nhap la: \n";
                            cout << polynomial << endl;
                            break;
                        }
                        case 2: {
							cout << "ban phai nhap da thuc truoc:\n";
							cin >> polynomial;
							cout << "in ra da thuc :\n";
                            cout << polynomial << endl;
                            break;
                        }
                        case 3: {
                            Polynomial p1, p2;
                            cout << "nhap da thuc 1: \n";
                            cin >> p1;
                            cout << "nhap da thuc 2: \n";
                            cin >> p2;
                            cout << "p1 = " << p1 << endl;
                            cout << "p2 = " << p2 << endl;
                            cout << "p1 + p2 = " << (p1 + p2) << endl;
                            break;
                        }
                        case 4: {
                            Polynomial p1, p2;
                            cout << "nhap da thuc 1: \n";
                            cin >> p1;
                            cout << "nhap da thuc 2: \n";
                            cin >> p2;
                            cout << "p1 = " << p1 << endl;
                            cout << "p2 = " << p2 << endl;
                            cout << "p1 - p2 = " << (p1 - p2) << endl;
                            break;
                        }
                        case 5: {
                            Polynomial p1, p2;
                            cout << "nhap da thuc 1: \n";
                            cin >> p1;
                            cout << "nhap da thuc 2: \n";
                            cin >> p2;
                            cout << "p1 = " << p1 << endl;
                            cout << "p2 = " << p2 << endl;
                            cout << "p1 * p2 = " << (p1 * p2) << endl;
                            break;
                        }
                        case 6: {
                            Polynomial p1, p2;
                            cout << "nhap da thuc 1: \n";
                            cin >> p1;
                            cout << "p1 = " << p1 << endl;
                            p2 = p1;
                            cout << "p2 = p1 =" << p2 << endl;
                            break;
                        }
                        case 7: {
                            int bac;
                            cout << "nhap da thuc: ";
                            cin >> polynomial;
                            cout << "da thuc hien tai: " << polynomial << endl;
                            do {
                                cout << "nhap bac cua he so ban muon truy xuat: ";
                                cin >> bac;
                                if (bac < 0 || bac >= polynomial.getN())
                                    cout << "so bac khong thuoc da thuc" << endl;
                            } while (bac < 0 || bac >= polynomial.getN());
                            cout << "he so:" << polynomial[bac] << endl;
                            break;
                        }
                        case 8: {
                            double x;
                            cout << "nhap da thuc: ";
                            cin >> polynomial;
                            cout << "da thuc hien tai: " << polynomial << endl;
                            cout << "nhap gai tri x: ";
                            cin >> x;
                            cout << "gia tri da thuc tai x = " << x << " la: " << polynomial(x) << endl;
                            break;
                        }
                    }
                } while (chontest != 0);
                break;
            }

        }
    }
}