#include "in.h"

// 3.1.1
void lambda_expression_capture() {
    auto ptr = 1;

    auto add = [v1 = 1, v2 = 2](int a, int b) -> int { return v1 + v2; };

    cout << add(1, 2) << endl;
}
