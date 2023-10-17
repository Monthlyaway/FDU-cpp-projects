#include <iostream>
#include <cmath>

using namespace std;

int fun(int n) {
	int result;
	if (n == 1) {
		result = 1;
	}
	else{
		result = 2 * fun(n / 2) + n;
	}
	cout << n << "\t\t" << result << endl;
	return result;
}

int main(void) {
	int n = 1;


	fun(pow(2, 20));

	/*
     * Table of values:
     *
     *   1               1
     *   2               4
     *   4              12
     *   8              32
     *  16              80
     *  32             192
     *  64             448
     * 128            1024
     * 256            2304
     * 512            5120
     * 1024          11264
     * 2048          24576
     * 4096          53248
     * 8192         114688
     * 16384        245760
     * 32768        524288
     * 65536       1114112
     * 131072      2359296
     * 262144      4980736
     * 524288     10485760
     * 1048576    22020096
     */


	return 0;
}