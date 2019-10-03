// xll_black.cpp

//!!! Implement XLL.BLACK.PUT(f, sigma, k, t) and XLL.BLACK.CALL(f, sigma, k, t)
//!!! Document both function.
//!!! Test both function. 
//!!! put = 3.988 to three decimal places for f = 100, sigma = 0.2, k = 100, t = 0.25.
//!!! Also test call value for these parameters.
#include "fms_black.h"
#include "../xll12/xll/xll.h"
#include "../xll12/xll/shfb/entities.h"

#ifndef CATEGORY
#define CATEGORY L"XLL"
#endif

using namespace xll;
static AddIn xai_black_put(
	Function(XLL_DOUBLE, L"?xll_black_put", L"XLL.BLACK.PUT")
	.Arg(XLL_DOUBLE, L"f", L"is the price of the underlying asset.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of returns of the underlying asset.")
	.Arg(XLL_DOUBLE, L"k", L"is the strick price.")
	.Arg(XLL_DOUBLE, L"t", L"is the time to maturity which is expressed in years.")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the value of the Black Scholes of a put option.")
	.Documentation(
		L"This function computes the value of a put option by Black Scholes formula."
	)
);
double WINAPI xll_black_put(double f, double sigma, double k, double t) {
#pragma XLLEXPORT
	return  fms::black::put(f, sigma, k, t);
}
#ifdef _DEBUG

test test_black_put([] {
	ensure(abs(xll_black_put(100, 0.2, 100, 0.25) - 3.988) < 0.001);
	});

#endif
static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL.BLACK.CALL")
	.Arg(XLL_DOUBLE, L"f", L"is the price of the underlying asset.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of returns of the underlying asset.")
	.Arg(XLL_DOUBLE, L"k", L"is the strick price.")
	.Arg(XLL_DOUBLE, L"t", L"is the time to maturity which is expressed in years.")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the value of the Black Scholes of a call option.")
	.Documentation(
		L"This function computes the value of a call option by Black Scholes formula."
	)
);
double WINAPI xll_black_call(double f, double sigma, double k, double t) {
#pragma XLLEXPORT
	return  fms::black::call(f, sigma, k, t);
}
#ifdef _DEBUG

test test_black_call([] {
	ensure(abs(xll_black_call(100, 0.2, 100, 0.25) - 3.988) < 1e-3);
	});

#endif

