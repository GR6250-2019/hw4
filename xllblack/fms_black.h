// fms_black.h - Black model
#pragma once
#include "fms_normal.h"
using namespace fms::normal;

namespace fms::black {

    //!!! Black put and call code goes here.
    //!!! Use the functions in fms_normal.h
	inline double put(double F, double sigma, double K, double T)
	{
		if (F < 0 || K < 0 || T <0 ) {
			throw std::domain_error("fms::black::put argument : INPUT ERROR");
		}

		double d1 = (log(F / K) + (0.5 * pow(sigma, 2) * T)) / (sigma * sqrt(T));
		double d2 = (log(F / K) - (0.5 * pow(sigma, 2) * T)) / (sigma * sqrt(T));

		double res_put = (K * cdf(-d2) - F * cdf(-d1));

		return res_put;
	}

	inline double call(double F, double sigma, double K, double T)
	{
		if (F < 0 || K < 0 || T < 0) {
			throw std::domain_error("fms::black::call argument : INPUT ERROR");
		}

		double d1 = (log(F / K) + (0.5 * pow(sigma, 2) * T)) / (sigma * sqrt(T));
		double d2 = (log(F / K) - (0.5 * pow(sigma, 2) * T)) / (sigma * sqrt(T));

		double res_call = (F * cdf(d1) - K * cdf(d2));

		return res_call;
	}

} // fms::black
