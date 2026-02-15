#include <iostream>
#include <iomanip>
using namespace std;

void takeInput(float* ptr1, float*ptr2, int n){
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

void calculatetable(float* ptr1, float* ptr2, double* ptr3, double*ptr4, double* ptr5, int n){
    for (int i=0; i<n; i++) {
        *(ptr3+i) = (*(ptr1+i))*(*(ptr1+i));
        *(ptr4+i) = *(ptr2+i)*(*ptr2+i);
        *(ptr5+i) = (*(ptr1+i))*(*(ptr2+i));
    }
}

void display(float* ptr1, float*ptr2, double* ptr3, double* ptr4, int n){
    cout << left << setw(10) << "x" << left << setw(10) << "y" << left << setw(10) << "xy" << left << setw(10) << "x^2" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i=0; i<n; i++) {
        cout << left << setw(10) << *(ptr1+i) << left << setw(10) << *(ptr2+i) << left << setw(10) << *(ptr3+i) << left << setw(10) << *(ptr4+i) << endl;
    }
    cout << "-------------------------------------------"<< endl;
}

int main() {
    int no;
    cout << "Enter no of obervations: ";
    cin >> no;

    float x[no], y[no];
    double xsquare[no], ysquare[no];
    double xy[no];
    double sumx=0, sumy=0, sumxy=0, sumxsq=0, sumysq=0;
    double a, b;

    takeInput(&x[0], &y[0], no);
    calculatetable(&x[0], &y[0], &xsquare[0], &ysquare[0], &xy[0], no);
    display(&x[0], &y[0], &xy[0], &xsquare[0], no);

    for (int i=0; i<no; i++) {
        sumx+=x[i];
        sumy+=y[i];
        sumxy+=xy[i];
        sumxsq+=xsquare[i];
        sumysq+=ysquare[i];
    }

    a = (sumx*sumxy-sumy*sumxsq)/(sumx*sumx-no*sumxsq);
    b= (sumy-a*no)/sumx;
    cout << left << setw(10) << sumx << left << setw(10) << sumy << left << setw(10) << sumxy << left << setw(10) << sumxsq << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}