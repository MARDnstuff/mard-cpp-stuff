#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define L 50
using namespace std;

class Matrix {
        int MX1[L][L];
        int n; // renglones
        int m; // columnas
    public:
        Matrix();
        void LeerMX();
        void VeerMX();
        void SumaMx(Matrix); // TBD
        void MultiMx(Matrix); // TBD
} a;

Matrix::Matrix() {
    for (int i = 0, t = 0; i <= L; i++) {
        MX1[t][i] = 0;
    }
    n = 1;
    m = 1;
}

void Matrix::LeerMX() {
    cout << "\n\t Dame tama�o de renglones= ";
    cin >> n;
    cout << "\n\t Dame tama�o de columnas=  ";
    cin >> m;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "\n\t M<" << i << "," << j << "> : ";
            cin >> MX1[i][j];
            fflush(stdin);
        }
    }

}

void Matrix::VeerMX() {

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "|" << MX1[i][j];
        }
        cout << "|\n";
    }
}

int main() {

    a.LeerMX();
    a.VeerMX();

    return 0;
}
