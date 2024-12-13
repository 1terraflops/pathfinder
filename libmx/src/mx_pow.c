double mx_pow(double n, unsigned int pow) {
	double result = 1;
	if (pow == 0)
		return 1;
	else if (n == 0)
		return 0;
	else {
		for (unsigned int i = 0; i < pow; ++i)
			result *= n;
	}
	return result;
}
