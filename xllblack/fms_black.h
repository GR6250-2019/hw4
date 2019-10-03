// fms_black.h - Black model
#pragma once
#include "fms_normal.h"

namespace fms::black {

    // f is underlying price
	// sigma is volatility
	// k is strike price
	// t is time to expiration
	// for put  price = k*N(-d2) - f*N(-d1) where N(x) is the standard normal cumulative distribution function
	// for call price = f*N(d1) - k*(n(d2)
	// d1 = (ln(f/k) + (sigma^2)*t/2) / (sigma * sqrt(t))
	// d2 = d1 - sigma *sqrt(t)

	inline auto put(double f, double sigma, double k, double t)
	{

		auto d1 = ((sigma * sqrt(t)) / 2) + (log(k / f) / (sigma * sqrt(t)));
		auto d2 = d1 - (sigma * sqrt(t));

		return k * fms::normal::cdf(-d2) - f * fms::normal::cdf(-d1);

	}

	inline auto call(double f, double sigma, double k, double t)
	{

		auto d1 = ((sigma * sqrt(t)) / 2) + (log(k / f) / (sigma * sqrt(t)));
		auto d2 = d1 - (sigma * sqrt(t));

		return f * fms::normal::cdf(d1) - k * fms::normal::cdf(d2);

	}

} // fms::black