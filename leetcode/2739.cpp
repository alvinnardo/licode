#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int distanceTraveled(int mainTank, int additionalTank) {
    int sum = 0;
    while (mainTank > 0) {

        if (mainTank >= 5) {
            sum += 5;
            mainTank -= 5;
            if (additionalTank > 0) {
                additionalTank--;
                mainTank++;
            }
        } else {
            sum += mainTank;
            mainTank = 0;
        }
    }

    return sum * 10;
}
int main(void) {
    // 60
    cout << distanceTraveled(5, 10) << endl;
    // 1
    cout << distanceTraveled(1, 2) << endl;

    return 0;
}
