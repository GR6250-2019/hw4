// xll_black.cpp
#include "fms_black.h"
#include "../xll12/xll/xll.h"
#include "../xll12/xll/shfb/entities.h"
#include <stdio.h>
#include <string>

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
	.Arg(XLL_DOUBLE, L"f", L"is the value at which to compute the inverse.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of the log returns of the underlying security")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price")
	.Arg(XLL_DOUBLE, L"t", L"is the matruity date")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the inverse of the cumulative distribution function.")
	.Documentation(
		L"This function computes the inverse of the cumulative distribution function "
		MATH_(int_ SUB_(minus_ infin_) SUP_(L"x") L"e" SUP_(minus_ L"z" sup2_ L"/2") L" dx/" radic_ L"2" pi_)
	)
);

double WINAPI xll_black_put(double f, double sigma, double k, double t) {

#pragma XLLEXPORT
	
	return fms::black::put(f, sigma, k, t);
}
#ifdef _DEBUG


test test_put([] {
	
	ensure(abs(xll_black_put(100, 0.2, 100, 0.25) - 3.988 )< 0.001);
	});

#endif
static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL.BLACK.CALL")
	.Arg(XLL_DOUBLE, L"f", L"is the value at which to compute the inverse.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of the log returns of the underlying security")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price")
	.Arg(XLL_DOUBLE, L"t", L"is the matruity date")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the inverse of the cumulative distribution function.")
	.Documentation(
		L"This function computes the inverse of the cumulative distribution function "
		MATH_(int_ SUB_(minus_ infin_) SUP_(L"x") L"e" SUP_(minus_ L"z" sup2_ L"/2") L" dx/" radic_ L"2" pi_)
	)
);

double WINAPI xll_black_call(double f, double sigma, double k, double t) {

#pragma XLLEXPORT
	
	return fms::black::call(f, sigma, k, t);
}


