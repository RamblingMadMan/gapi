#ifndef GAPI_MATH_HPP
#define GAPI_MATH_HPP 1

namespace gapi{
	class WorldSpace;
	class ScreenSpace;

	template<typename Space>
	class point;

	template<>
	class alignas(16) point<WorldSpace>{
		public:
			constexpr point(){}
			constexpr point(float x_, float y_, float z_)
				: x(x_), y(y_), z(z_){}

			float x = 0.f, y = 0.f, z = 0.f;
	};

	template<>
	class alignas(16) point<ScreenSpace>{
		public:
			constexpr point(){}
			constexpr point(float x_, float y_)
				: x(x_), y(y_){}

			float x = 0.f, y = 0.f;
	};

	using world_point = point<WorldSpace>;
	using screen_point = point<ScreenSpace>;

	constexpr auto dot(const world_point &lhs, const world_point &rhs){
		return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
	}

	constexpr auto dot(const screen_point &lhs, const screen_point &rhs){
		return (lhs.x * rhs.x) + (lhs.y * rhs.y);
	}
}

#endif // GAPI_MATH_HPP
