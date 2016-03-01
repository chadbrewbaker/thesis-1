typedef double double_32 __attribute__((aligned(32)));

void fct(double_32 *__restrict r,
	const double_32 *__restrict a,
	const double_32 *__restrict b,
	double f)
{
	for (unsigned i = 0; i < 128; ++i)
		r[i] = a[i] * f + b[i];
}
