#include <functional>
#include "Edge.h"
template <> struct std::greater<Edge>
{
	constexpr bool operator()(const Edge& _Left, const Edge& _Right) const {
		return _Left.weight > _Right.weight;
	}
};