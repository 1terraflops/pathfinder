#include "libmx.h"

void mx_printint(int n) {
	int num = 0;

	if (n < 0) {
        mx_printchar('-');
        n = -n;
    }

	if (n >= 10) {
        mx_printint(n / 10);
    }
    num = '0' + n % 10;
    mx_printchar(num);
}
