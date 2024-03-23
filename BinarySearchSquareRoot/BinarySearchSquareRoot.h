// BinarySearchSquareRoot.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <cmath>

static double truncate(double d, double precision)
{
	return static_cast<int>(d / precision) * precision;
}

static float bssqrt(double d)
{
	const double precision = 0.0001;

	double left = 0.0, right = d;

	while (true)
	{
		double mid = left + (right - left) / 2;
		double midsquared = mid * mid;
		if (std::abs(midsquared - d) <= precision)
		{
			// found answer within +- precision,
			// now throw away everything after "level of precision"
			auto val = mid * (1.0 / precision);
			auto rounded = std::round(val);
			auto m = rounded * precision;
			return (float)m;
			return static_cast<int>(m / precision) * precision;

		}
		else if (midsquared > d)
		{
			right = mid;
		}
		else if (midsquared < d)
		{
			left = mid;
		}
	}

	// unreachable
	return -1.0;
}
