// xll_black.cpp

#include "fms_black.h"
#include "../xll12/xll/xll.h"
#include "../xll12/xll/shfb/entities.h"

#ifndef CATEGORY
#define CATEGORY L"XLL"
#endif

using namespace xll;

//!!! Implement XLL.BLACK.PUT(f, sigma, k, t) and XLL.BLACK.CALL(f, sigma, k, t)
//!!! Document both function.
//!!! Test both function. 
//!!! put = 3.988 to three decimal places for f = 100, sigma = 0.2, k = 100, t = 0.25.
//!!! Also test call value for these parameters.

static AddIn xai_black_put(
	Function(XLL_DOUBLE, L"?xll_black_put", L"XLL.BLACK.PUT")
	.Arg(XLL_DOUBLE, L"F", L"is the discounted future price.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of underlying assets.")
	.Arg(XLL_DOUBLE, L"K", L"is the strike price.")
	.Arg(XLL_DOUBLE, L"T", L"is the time to maturity.")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the value of the price for European put option.")
	.Documentation(
		L"This function computes the price for European put option of maturity T on"
		L"a futures contract with strike price K and delivery date T"
		//MATH_(L"e" SUP_(minus_ L"z" sup2_ L"/2") L"/" radic_ L"2" pi_)
	)
);

double WINAPI xll_black_put(double F, double sigma, double K, double T)
{
#pragma XLLEXPORT
	//ensure(T >= 0);

	double p = std::numeric_limits<double>::quiet_NaN();

	try {
		p = fms::black::put(F, sigma, K, T);
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return p;
}


#ifdef _DEBUG

test test_black_put([] {
	//abs(xll_black_put(100, 0.2, 100, 0.25) - 3.988) < 1e-3
	ensure(std::round(xll_black_put(100, 0.2, 100, 0.25) * 1000.0) / 1000.0 == 3.988);

	});

#endif

static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL.BLACK.CALL")
	.Arg(XLL_DOUBLE, L"F", L"is the discounted future price.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of underlying assets.")
	.Arg(XLL_DOUBLE, L"K", L"is the strike price.")
	.Arg(XLL_DOUBLE, L"T", L"is the time to maturity.")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the value of the price for European call option.")
	.Documentation(
		L"This function computes the price for European call option of maturity T on"
		L"a futures contract with strike price K and delivery date T"
		//MATH_(L"e" SUP_(minus_ L"z" sup2_ L"/2") L"/" radic_ L"2" pi_)
	)
);

double WINAPI xll_black_call(double F, double sigma, double K, double T)
{
#pragma XLLEXPORT
	//ensure(T >= 0);
	double p = std::numeric_limits<double>::quiet_NaN();

	try {
		p = fms::black::call(F, sigma, K, T);
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return p;
}


#ifdef _DEBUG

test test_black_call([] {
	//abs(xll_black_call(100, 0.2, 100, 0.25) - 3.988) < 1e-3

  	ensure(std::round(xll_black_call(100, 0.2, 100, 0.25) * 1000.0) / 1000.0 == 3.988);

	});

#endif


