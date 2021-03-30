#pragma once

#include "Math.h"
#include <random>
#include <ctime>

namespace random {
	math::Vector2<float> Vector2(const math::Vector2<float> &min, const math::Vector2<float> &max) {
		std::mt19937 generator(static_cast<int>(time(nullptr)));
		std::uniform_real_distribution<> distr1(min.x, max.x);
		std::uniform_real_distribution<> distr2(min.y, max.y);
		return math::Vector2<float>(static_cast<float>(distr1(generator)), 
									static_cast<float>(distr2(generator)));
	}

	math::Vector3<float> Vector3(const math::Vector3<float> &min, const math::Vector3<float> &max) {
		std::mt19937 generator(static_cast<int>(time(nullptr)));
		std::uniform_real_distribution<> distr1(min.x, max.x);
		std::uniform_real_distribution<> distr2(min.y, max.y);
		std::uniform_real_distribution<> distr3(min.z, max.z);
		return math::Vector3<float>(static_cast<float>(distr1(generator)), 
									static_cast<float>(distr2(generator)), 
									static_cast<float>(distr3(generator)));
	}

	float Range(float min, float max) {
		std::mt19937 generator(static_cast<int>(time(nullptr)));
		std::uniform_real_distribution<> distr(min, max);
		return static_cast<float>(distr(generator));
	}

	template <typename T>
	T Range(T &min, T &max) {
		return (rand() % (max - min + 1) + min);
	}
}