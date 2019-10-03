// fms_black.h - Black model
#pragma once
#include "fms_normal.h"

namespace fms::black {
	//!!! Black put and call code goes here.
	//!!! Use the functions in fms_normal.h
	inline double put(double f, double sigma, double k, double t) {
		double nominator = log(f / k) + (t * sigma * sigma / 2);
		double denominator = sigma * sqrt(t);
		double d1 = nominator / denominator;
		double d2 = d1 - (sigma * sqrt(t));
		double p = (k * fms::normal::cdf(-d2)) - (f * fms::normal::cdf(-d1));
		return p;
	}
	inline double call(double f, double sigma, double k, double t) {
		double nominator = log(f / k) + (t * sigma * sigma / 2);
		double denominator = sigma * sqrt(t);
		double d1 = nominator / denominator;
		double d2 = d1 - (sigma * sqrt(t));
		double c = (f * fms::normal::cdf(d1)) - (k * fms::normal::cdf(d2));
		return c;
	}
} // fms::black