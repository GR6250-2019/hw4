// fms_black.h - Black model
#pragma once
#include "fms_normal.h"
#include <math.h>
#include <stdexcept>
#include <utility>
namespace fms::black {

    //!!! Black put and call code goes here.
    //!!! Use the functions in fms_normal.h

	//calculate the put option price
	inline double put(double f, double sigma, double k, double t) {
		double d1 = (log(f / k) + (pow(sigma, 2) / 2) * (t)) / (sigma * sqrt(t));
		double d2 = (log(f / k) + (-pow(sigma, 2) / 2) * (t)) / (sigma * sqrt(t));
		double put_price = fms::normal::cdf(-d2) * k - f * fms::normal::cdf(-d1);
		return put_price;
	}

	//calculate the call option price
	inline double call(double f, double sigma, double k, double t) {
		double d1 = (log(f / k) + (pow(sigma, 2) / 2) * (t)) / (sigma * sqrt(t));
		double d2 = (log(f / k) + (-pow(sigma, 2) / 2) * (t)) /( sigma * sqrt(t));
		double call_price = fms::normal::cdf(d1) * f - k * fms::normal::cdf(d2);
		return call_price;
	}
} // fms::black