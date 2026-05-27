#include <iostream>
#define MAX 100
using namespace std;

void NhapMang(int a[MAX][MAX], int &x, int &y, const string ten){
    cout << "Nhap so phan tu cua mang x va y " << ten << ": ";
    cin >> x;
    cin >> y;
    while ((x < 1 || x > MAX)||(y < 1 || y > MAX)){
        cout << "So phan tu khong hop le. Nhap lai ma tran > 0 va < 100: ";
        if (x < 1 || x > MAX){
            cout << "Nhap lai so phan tu cua mang " << ten << ": ";
            cin >> x;
        }
        if (y < 1 || y > MAX){
            cout << "Nhap lai so phan tu cua mang " << ten << ": ";
            cin >> y;
        }
    }
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cout << ten << "[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMang(int a[MAX][MAX], int x, int y, const string ten){
    cout << "Mang " << ten << " vua nhap: \n";
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Nhan_AxB(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int Row_a, int Col_a, int Row_b, int Col_b){
    cout << "Nhan 2 ma tran A va B: ";
    if (Col_a != Row_b){
        cout << "Khong the nhan 2 ma tran A va B do so cot cua A khac so dong cua B" << endl;
        return;
    }else{
        for (int i = 0; i < Row_a; i++){
            for (int j = 0; j < Col_b; j++){
                int sum = 0;
                for (int k = 0; k < Col_a; k++){
                    sum += a[i][k] * b[k][j];
                }
                c[i][j] = sum;
            }
        }
        XuatMang(c, Row_a, Col_b, "Tich C (A x B)");
    }
}

int main(){
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], Row_a, Row_b, Col_a, Col_b;
    NhapMang(a, Row_a, Col_a, "A");
    XuatMang(a, Row_a, Col_a, "A");
    NhapMang(b, Row_b, Col_b, "B");
    XuatMang(b, Row_b, Col_b, "B");
    Nhan_AxB(a, b, c, Row_a, Col_a, Row_b, Col_b);
    return 0;
}