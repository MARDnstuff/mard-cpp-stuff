#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define L 50
using namespace std;

// Nombre de la Empresa -ARIZONA-
double TSaldo_P = 0.0;
double TSaldo_A = 0.0;
double TSaldo_C = 0.0;

void VeerTOTAL() {
    double TX = 0.0;
    TX = TSaldo_A + TSaldo_C + TSaldo_P;
    cout << "\n\t GASTO TOTAL DE LA EMPRESA: " << TX;
}

class ArEmpleado {
    private:
        char *Name;
        int Edad;
        char *Direcc;

    public:
        ArEmpleado(); // constructor
        void LeerData();
        void VeerData();
};

ArEmpleado::ArEmpleado() {
    Name = new char(L);
    Edad = 0;
    Direcc = new char(L);
}

void ArEmpleado::LeerData() {
    cout << "\n\t Introduzca los datos requridos ";
    cout << "\n\t Nombre: ";
    cin.getline(Name, 50, '\n');
    cout << "\n\t Edad: ";
    cin >> Edad;
    fflush(stdin);
    cout << "\n\t Direccion: ";
    cin.getline(Direcc, 50, '\n');
}

void ArEmpleado::VeerData() {
    cout << "\n\t EMPRESA: -ARIZONA- ";
    cout << "\n\t NOMBRE: " << Name;
    cout << "\n\t EDAD: " << Edad;
    cout << "\n\t DIRECCION: " << Direcc;
}

class Profesor_A : ArEmpleado {
    private:
        char *NomCargo;
        double Salario;

    public:
        Profesor_A(); // constructor
        void LeerProfe();
        void VeerPofe();
        void TotalSaldo_P();
} P[5];

Profesor_A ::Profesor_A() {
    NomCargo = new char(L);
    Salario = 0.0;
}

void Profesor_A ::LeerProfe() {
    ArEmpleado::LeerData();
    cout << "\n\t Puesto: ";
    cin.getline(NomCargo, 50, '\n');
    cout << "\n\t Salario: ";
    cin >> Salario;
}

void Profesor_A ::VeerPofe()
{
    ArEmpleado::VeerData();
    cout << "\n\t PUESTO: " << NomCargo;
    cout << "\n\t SALARIO: " << Salario;
}
void Profesor_A::TotalSaldo_P() {
    TSaldo_P += Salario;
}

class Admin_B : ArEmpleado {
    private:
        char *NomCargo;
        double Salario;

    public:
        Admin_B(); // constructor
        void LeerAdmin();
        void VeerAdim();
        void TotalSaldo_A();
} A[2];

Admin_B::Admin_B() {
    NomCargo = new char(L);
    Salario = 0.0;
}

void Admin_B::LeerAdmin() {
    ArEmpleado::LeerData();
    cout << "\n\t Puesto: ";
    cin.getline(NomCargo, 50, '\n');
    cout << "\n\t Salario: ";
    cin >> Salario;
}

void Admin_B ::VeerAdim() {
    ArEmpleado::VeerData();
    cout << "\n\t PUESTO: " << NomCargo;
    cout << "\n\t SALARIO: " << Salario;
}

void Admin_B::TotalSaldo_A() {
    TSaldo_A += Salario;
}

class BECA_C : ArEmpleado {
    private:
        char *NomCargo;
        double Salario;

    public:
        BECA_C(); // constructor
        void LeerBECA();
        void VeerBECA();
        void TotalSaldo_B();
} X[3];

BECA_C::BECA_C() {
    NomCargo = new char(L);
    Salario = 0.0;
}

void BECA_C::LeerBECA() {
    ArEmpleado::LeerData();
    cout << "\n\t Puesto: ";
    cin.getline(NomCargo, 50, '\n');
    cout << "\n\t Salario: ";
    cin >> Salario;
}

void BECA_C::VeerBECA() {
    ArEmpleado::VeerData();
    cout << "\n\t PUESTO: " << NomCargo;
    cout << "\n\t SALARIO: " << Salario;
}

void BECA_C::TotalSaldo_B() {
    TSaldo_C += Salario;
}

int main() {
    for (int i = 0; i < 5; i++){
        P[i].LeerProfe();
        P[i].VeerPofe();
        P[i].TotalSaldo_P();
        fflush(stdin);
    }

    cout << "\n\t Total Gasto Profesores: " << TSaldo_P;

    for (int j = 0; j < 2; j++) {
        A[j].LeerAdmin();
        A[j].VeerAdim();
        A[j].TotalSaldo_A();
        fflush(stdin);
    }

    cout << "\n\t Total Gasto Administrativos: " << TSaldo_A;
    
    for (int k = 0; k < 3; k++) {
        X[k].LeerBECA();
        X[k].VeerBECA();
        X[k].TotalSaldo_B();
        fflush(stdin);
    }
    
    cout << "\n\t Total Gasto Becarios:  " << TSaldo_C;
    VeerTOTAL();
    return 0;
}
