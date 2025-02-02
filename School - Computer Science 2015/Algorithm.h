/**
 * @file Algorithm.h
 *
 * Declares the euclidiean algorithm and the extended euclidean algorithm.
 */

#pragma once
#include "stdafx.h"

namespace kg
{
	/**
	 * Euclidean algorithm.
	 *
	 * @author Kay
	 * @date 11.12.2015
	 *
	 * @tparam T Generic type parameter.
	 * @param a The T to process.
	 * @param b The T to process.
	 *
	 * @return A T.
	 */

	template<class T>
	T euclidean_algorithm( T a, T b )
	{
		if( a == 0 )
			return b;
		return euclidean_algorithm( b%a, a );
	}

	/**
	 * Extended euclidean algorithm.
	 *
	 * @author Kay
	 * @date 11.12.2015
	 *
	 * @tparam T Generic type parameter.
	 * @param a The T to process.
	 * @param b The T to process.
	 *
	 * @return A std::tuple<T, T, T>;
	 * 		   T0 = mult. inv. a mod b
	 *		   T1 = mult. inv. b mod a
	 *		   T2 = gcd.
	 */

	template<class T>
	std::tuple<T, T, T> extended_euclidean_algorithm( T a, T b )
	{
		T x0 = 1, xn = 1;
		T y0 = 0, yn = 0;
		T x1 = 0;
		T y1 = 1;
		T q;
		T r = a % b;

		while( r > 0 )
		{
			q = a / b;
			xn = x0 - q * x1;
			yn = y0 - q * y1;

			x0 = x1;
			y0 = y1;
			x1 = xn;
			y1 = yn;
			a = b;
			b = r;
			r = a % b;
		}

		return std::make_tuple( xn, yn, b );
	}
}