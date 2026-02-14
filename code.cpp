#include <iostream>
#include <iomanip>
using namespace std;

void takeInput(int* ptr1, int*ptr2, int n){
    cout << "Enter the values of x: " << endl;
    for (int i=0; i<n; i++) {
        cout << i+1 << ":";
        cin >> *(ptr1+i);
    };
    cout << "Enter the values of y: " << endl;
    for (int i=0; i<n; i++) {
        cout << i+1 << ":";
        cin >> *(ptr2+i);
    };
};

void calculatetable(int* ptr1, int* ptr2, int* ptr3, int*ptr4, int* ptr5, int n){
    for (int i=0; i<n; i++) {
        *(ptr3+i) = *(ptr1+i)*(*ptr1+i);
        *(ptr4+i) = *(ptr2+i)*(*ptr2+i);
        *(ptr5+i) = (*(ptr1+i))*(*(ptr2+i));
    }
}

int main() {
    int no;
    cout << "Enter no of obervations: ";
    cin >> no;

    int x[no], y[no];
    int xsquare[no], ysquare[no];
    int xy[no];
    int sumx=0, sumy=0, sumxy=0, sumxsq=0, sumysq=0;
    takeInput(&x[0], &y[0], no);
    calculatetable(&x[0], &y[0], &xsquare[0], &ysquare[0], &xy[0], no);

    cout << left << setw(10) << "x" << left << setw(10) << "y" << left << setw(10) << "xy" << left << setw(10) << "x^2" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i=0; i<no; i++) {
        cout << left << setw(10) << x[i] << left << setw(10) << y[i] << left << setw(10) << xy[i] << left << setw(10) << xsquare[i] << endl;
    }
    cout << "-------------------------------------------"<< endl;
    for (int i=0; i<no; i++) {
        sumx+=x[i];
        sumy+=y[i];
        sumxy+=xy[i];
        sumxsq+=xsquare[i];
        sumysq+=ysquare[i];
    }
    cout << left << setw(10) << sumx << left << setw(10) << sumy << left << setw(10) << sumxy << left << setw(10) << sumxsq << endl;
    return 0;
}