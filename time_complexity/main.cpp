#include<iostream>
using namespace std;

#define REP(i, a, b) for (int i=a; i<=b; i++)

void printArray(int* inputs, int size) {
    REP(i, 0, size - 1) {
        std::cout << inputs[i] << " ";
    }

    cout << "\n";

}

int algorithm1(int* inputs, int size) {

    int best = 0;

    REP(a, 0, size-1){
        REP(b, a, size-1){
            int sum = 0;
            REP(k, a, b){
                sum += inputs[k];
            }
            best = max(best, sum);
        }
    }

    return best;

}

int algorithm2(int* inputs, int size) {

    int best = 0;

    REP(a, 0, size-1){

        int sum=0;
        REP(b, a, size-1){
            sum+=inputs[b];
            best = max(best, sum);
        }
    }

    return best;
}

int kadane_algorithm(int* inputs, int size) {

    int best = 0, sum = 0;

    REP(a, 0, size-1){
        sum = max(inputs[a], sum+inputs[a]);
        best = max(best, sum);
    }

    return best;

}

int main() {
    int inputs[] = {-1, 2, 4, -3, 5, 2, -5, 2};
    int size = sizeof(inputs) / sizeof(int);

    printArray(inputs, size);

    int resultAlgo1 = algorithm1(inputs, size);

    cout << "Result of Algorithm 1 is: " << resultAlgo1 << "\n";

    int resultAlgo2 = algorithm2(inputs, size);

    cout << "Result of Algorithm 2 is: " << resultAlgo2 << "\n";

    int resultAlgo3 = kadane_algorithm(inputs, size);

    cout << "Result of Algorithm 3 is: " << resultAlgo3 << "\n";

}