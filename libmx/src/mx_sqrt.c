#include "libmx.h"

int mx_sqrt(int x) {
    for (int i = 0; mx_pow(i, 2) <= x; ++i) {
    	if (mx_pow(i, 2) == x)
    		return i;
    }
    return 0;
}
