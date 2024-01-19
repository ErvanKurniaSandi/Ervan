#include<iostream>
#include<cstdlib>
using namespace std;

char angka[10] = {'0','1','2','3','4','5','6','7','8','9'};
int cetak_hasil();
void papan_permainan();

int main() {
    int pemain = 1, i, pilih;
    char simbol;

    do {
        papan_permainan();
        pemain = (pemain % 2) ? 1 : 2;
        cout << "Pemain " << pemain << ", Masukan angka : ";
        cin >> pilih;
        simbol = (pemain == 1) ? 'X' : 'O';

        if (pilih >= 1 && pilih <= 9 && angka[pilih] == '0' + pilih) {
            angka[pilih] = simbol;
        } else {
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            pemain--;
            cin.ignore();
            cin.get();
        }

        i = cetak_hasil();
        pemain++;
    } while (i == -1);

    papan_permainan();

    if (i == 1)
        cout << "==>\aPemain " << (pemain == 1 ? 2 : 1) << " win";
    else
        cout << "==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}

int cetak_hasil() {
    for (int j = 1; j <= 7; j += 3) {
        if (angka[j] == angka[j + 1] && angka[j + 1] == angka[j + 2])
            return 1;
    }

    for (int j = 1; j <= 3; j++) {
        if (angka[j] == angka[j + 3] && angka[j + 3] == angka[j + 6])
            return 1;
    }

    if (angka[1] == angka[5] && angka[5] == angka[9])
        return 1;
    if (angka[3] == angka[5] && angka[5] == angka[7])
        return 1;

    for (int j = 1; j <= 9; j++) {
        if (angka[j] == '0' + j)
            return -1;
    }

    return 0;
}

void papan_permainan() {
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Pemain 1 (X) - Pemain 2 (O)" << endl << endl;
    cout << endl;
    cout << "|     |      |      |" << endl;
    cout << "|  " << angka[1] << "  |  " << angka[2] << "   |  " << angka[3] << "   |" << endl;
    cout << "|_____|______|______|" << endl;
    cout << "|     |      |      |" << endl;
    cout << "| "  << angka[4] << "   |  " << angka[5] << "   |  " << angka[6] << "   |" << endl;
    cout << "|_____|______|______|" << endl;
    cout << "|     |      |      |" << endl;
    cout << "| "  << angka[7] << "   |  " << angka[8] << "   |  " << angka[9] << "   |" << endl;
    cout << "|     |      |      |" << endl;
}
