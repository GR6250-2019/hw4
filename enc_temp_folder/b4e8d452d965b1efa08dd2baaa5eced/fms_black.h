// fms_black.h - Black model
#pragma once
#include "fms_normal.h"
#include <math.h>
#include <stdexcept>
#include <utility>
namespace fms::black {

    //!!! Black put and call code goes here.
    //!!! Use the functions in fms_normal.h

	//calculate the put option
	inline double put(double f, double sigma, double k, double t) {
		/*double cumulant_s = pow(sigma, 2) * t / 2;
		double s = sigma * sqrt(t);
		double z = (cumulant_s + log(k / f)) / s;*/
		//double z = fms::black::getZ(f, sigma, k, t);
		//double PHI_z = fms::normal::cdf(z);
		//double phi_z = fms::normal::pdf(z);
		//here we assume n = 4
		//TODO not sure of the bell polynomial part being all zero here
		//double bell_hermite = (z / 2 + (pow(z, 3) - 3 * z) / 8);
		
		//double kPSI_z = PHI_z - phi_z * bell_hermite;
		//double kPSI_z = k*PHI_z;

		//double newZ = z / sigma;
		//double PHI_newZ = fms::normal::cdf(newZ);
		//double phi_newZ = fms::normal::pdf(newZ);

		////double bell_hermite_pt2 = pow(newZ, 3) / 6;
		////double fPSI_star_newZ = f * (PHI_newZ - phi_newZ * bell_hermite_pt2);
		//double fPSI_star_newZ = f * (PHI_newZ);
		//return kPSI_z - fPSI_star_newZ;

		double d1 = (log(f / k) + (pow(sigma, 2) / 2) * (t)) / (sigma * sqrt(t));
		double d2 = (log(f / k) + (-pow(sigma, 2) / 2) * (t)) / (sigma * sqrt(t));
		double put_price = fms::normal::cdf(-d2) * k - f * fms::normal::cdf(-d1);
		return put_price;
	}

	////calculate the z value
	//double getZ(double f,double sigma, double k, double t) {
	//	double cumulant_s = pow(sigma, 2) * t / 2;
	//	double s = sigma * sqrt(t);
	//	double z = (cumulant_s + log( k / f)) / s;
	//	return z;
	//}

	inline double call(double f, double sigma, double k, double t) {
		double d1 = (log(f / k) + (pow(sigma, 2) / 2) * (t)) / (sigma * sqrt(t));
		double d2 = (log(f / k) + (-pow(sigma, 2) / 2) * (t)) /( sigma * sqrt(t));
		double call_price = fms::normal::cdf(d1) * f - k * fms::normal::cdf(d2);
		return call_price;
	}
} // fms::black