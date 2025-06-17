
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Numerio{
    public:
        double countNeg(double **arr[],int len){
            double s = 0;
            int nn = 0;
            for(int i = 0; i < len; i++) {
                for(int j = 0; j < len; j++) {
                    if (a[i][j] < 0) {
                        s += a[i][j];
                        nn++;
                    }
                }
            }
            double fin_sum = s/nn;
            return fin_sum
        }
}
int main() {
    int n = 0;
    cout << "Insert n, size of array n*n";
    cin >> n;
    if (n <= 10) {
        double **a = new double*[n];
        for(int i = 0; i < n; i++)
            a[i] = new double[n];

        double s = 0;
        srand(time(0));

        int nn = 0;                                   
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                a[i][j] = rand() % 100 - 80;
            }
        }
        Numerio numero;
        double final_sum = numero.countNeg(a,n);
    }else{
        cout<<"Insert size of array less than 10";
    }

    cout << "Final sum of negative numbers is: " << fin_sum;

    for(int i = 0; i < n; i++) {
        delete[] a[i];
    }

    delete[] a;

    return 0;
} 