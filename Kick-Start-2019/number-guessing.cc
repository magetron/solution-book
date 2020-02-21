#include <iostream>
#include <cstdlib>
#include <cstring>
#define status_length 10

using namespace std;

void binary_search (int a, int b) {
    if (a > b) return;
    int mid = (a + b) / 2;
    cout << mid << endl;
    char status[status_length];
    cin >> status;
    if (strncmp(status, "CORRECT", 7) == 0) return;
    else if (strncmp(status, "TOO_BIG", 7) == 0) binary_search(a, mid - 1);
    else if (strncmp(status, "TOO_SMALL", 9) == 0) binary_search(mid + 1, b); 
    else if (strncmp(status, "WRONG_ANSWER", 12) == 0) exit(0);
}


void do_work() {
    int a, b, n;
    cin >> a >> b;
    cin >> n;
    binary_search(a, b);
}


int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cases;
    cin >> test_cases;
    
    for (int i = 0; i < test_cases; i++) do_work();
    
    return 0;
}
