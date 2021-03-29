#pragma once

namespace math {
	const float PI = 3.1415926535F;

	inline float ToDegrees(float radians) {
		return radians * 180.0F / PI;
	}

	template <typename T>
	inline T Abs(T x) {
		return x >= 0 ? x : -x;
	}

	template <typename T>
	inline bool Compare(T x, T y) {
		return (math::Abs<T>(x - y) < 0.001F);
	}
}