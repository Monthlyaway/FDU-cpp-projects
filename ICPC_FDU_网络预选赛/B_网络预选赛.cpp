#include <iostream>

using namespace std;

int main(void) {
	unsigned long  teams;
	unsigned long eachBig, eachSmall;
	unsigned long  priceOfBig, priceOfSmall;
	unsigned long  haveBig, haveSmall;
	unsigned long  cost;

	cin >> teams >> haveBig >> haveSmall >> eachBig
		>> eachSmall >> priceOfBig >> priceOfSmall;

	int needBig, needSmall;
	if (haveBig >= teams * eachBig) {
		// 大支架够了
		needBig = 0;
		haveSmall += haveBig - teams * eachBig;
		needSmall = haveSmall >= teams * eachSmall ?
			0 : teams * eachSmall - haveSmall;
	}
	else {
		// 大支架不够
		needBig = teams * eachBig - haveBig;
		needSmall = teams * eachSmall - haveSmall;
	}

	cost = needBig * priceOfBig + needSmall * priceOfSmall;
	cout << cost;

	return 0;
}