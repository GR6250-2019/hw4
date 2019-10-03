// xll_black.cpp

#include "fms_black.h"
#include "../xll12/xll/xll.h"

#ifndef CATEGORY
#define CATEGORY L"XLL"
#endif

using namespace xll;
using namespace fms;

static AddIn xai_black_put(
	Function(XLL_DOUBLE, L"?xll_black_put", L"XLL.BLACK.PUT")
	.Arg(XLL_DOUBLE, L"f", L"current price.")
	.Arg(XLL_DOUBLE, L"sigma", L"implied volatility.")
	.Arg(XLL_DOUBLE, L"k", L"strike price.")
	.Arg(XLL_DOUBLE, L"t", L"years until expiration.")
	.Category(CATEGORY)
	.FunctionHelp(L"takes in put option stats and returns the put value.")
);
double WINAPI xll_black_put(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT

		double result = std::numeric_limits<double>::quiet_NaN();

		try {
			result = fms::black::put(f, sigma, k, t);
		}
		catch (const std::exception& ex) {
			XLL_ERROR(ex.what());
		}

		return result;

}

#ifdef _DEBUG

test test_black_put([] {
	ensure(trunc(100. * xll_black_put(100, 0.2, 100, 0.25)) == 398)
	// test value matches to 2 decimal places
	});

#endif

static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL.BLACK.CALL")
	.Arg(XLL_DOUBLE, L"f", L"forward value.")
	.Arg(XLL_DOUBLE, L"sigma", L"implied volatility.")
	.Arg(XLL_DOUBLE, L"k", L"strike price.")
	.Arg(XLL_DOUBLE, L"t", L"years until expiration.")
	.Category(CATEGORY)
	.FunctionHelp(L"takes in call option stats and returns the call value.")
);
double WINAPI xll_black_call(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT
	double result = std::numeric_limits<double>::quiet_NaN();

	try {
		result = fms::black::call(f, sigma, k, t);
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return result;

}

#ifdef _DEBUG

test test_black_call([] {
	ensure(trunc(100. * xll_black_call(100, 0.2, 100, 0.25)) == 398)
		// test that call returns correct values
	});

#endif