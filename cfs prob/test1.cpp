#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int w = rand() % 10000 + 1;
    cout << w << endl;
    return 0;
}