#pragma once

#include "Application.h"

#include <concepts>
#include <type_traits>

namespace GGR {


template <class T, class... SingletonClasses>
constexpr bool exprIsAnyOfAllowedSingletones = (std::is_base_of_v<SingletonClasses, T> || ...);

template <class T>
concept AllowedToBeSingleton = exprIsAnyOfAllowedSingletones<T, Application>;

template <AllowedToBeSingleton T>
class Singleton
{
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T& getInstance() { return Instance; }

private:
	Singleton() {}

	static T& Instance;

};

}  // namespace GGR
