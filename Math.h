#pragma once

#include <cmath>

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

	template <typename T> 
	struct Vector2 {
		T x;
		T y;

		Vector2() = default;
		Vector2(T x, T y) : x(x), y(y) { }

		static T Distance(Vector2<T> &v1, Vector2<T> &v2) {
			Vector2<T> v3 = v1 - v2;
			return v3.Length();
		}

		T Length() {
			return sqrt(pow(x, 2) + pow(y, 2));
		}

		T LengthSquared() {
			return pow(x, 2) + pow(y, 2);
		}

		void Normalize() {
			if (math::Compare<T>(x, 0) || math::Compare<T>(y, 0)) {
				return;
			}
			T length = Length();
			x /= length;
			y /= length;
		}

		Vector2<T> RotationToForward(T rotation) {
			return Vector2<T>(cos(rotation), -sin(rotation));
		}

		T ForwardToRotation(const Vector2<T> &forward) {
			return atan2(-forward.y, forward.x);
		}

		T Dot(const Vector2<T> &v1, const Vector2<T> &v2) {
			return v1.x * v2.x + v1.y * v2.y;
		}

		T AngleBetween(const Vector2<T> &v1, const Vector2<T> &v2) {
			return acos(Dot(v1, v2));
		}

		Vector2<T> operator-(const Vector2<T> &v) {
			return Vector2<T>(x - v.x, y - v.y);
		}

		Vector2<T> operator+(const Vector2<T> &v) {
			return Vector2<T>(x + v.x, y + v.y);
		}

		Vector2<T> operator*(const T m) {
			x *= m;
			y *= m;
		}
	};

	template <typename T> 
	struct Vector3 {
		T x;
		T y;
		T z;

		Vector3() = default;
		Vector3(T x, T y, T z) : x(x), y(y), z(z) { }

		static T Distance(Vector3<T> &v1, Vector3<T> &v2) {
			Vector3<T> v3 = v1 - v2;
			return v3.Length();
		}

		T Length() {
			return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		}

		T LengthSquared() {
			return pow(x, 2) + pow(y, 2) + pow(z, 2);
		}

		void Normalize() {
			if (math::Compare<T>(x, 0) || math::Compare<T>(y, 0) || math::Compare<T>(z, 0)) {
				return;
			}
			T length = Length();
			x /= length;
			y /= length;
			z /= length;
		}

		T Dot(const Vector3<T> &v1, const Vector3<T> &v2) {
			return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		}

		T AngleBetween(const Vector3<T> &v1, const Vector3<T> &v2) {
			return acos(Dot(v1, v2));
		}

		Vector3<T> Cross(const Vector3<T> &v1, const Vector3<T> &v2) {
			return Vector3<T>(v1.y * v2.z - v1.z * v2.y,
							  v1.z - *v2.x - v1.x * v2.z,
							  v1.x * v2.y - v1.y * v2.x);
		}

		Vector3<T> operator-(const Vector3<T> &v) {
			return Vector3<T>(x - v.x, y - v.y, z - v.z);
		}

		Vector3<T> operator+(const Vector3<T> &v) {
			return Vector3<T>(x + v.x, y + v.y, z + v.z);
		}

		Vector3<T> operator*(const T m) {
			x *= m;
			y *= m;
			z *= m;
		}
	};
}
