#ifndef CTK_CONST_STR_HPP
#define CTK_CONST_STR_HPP 1

#include <cstddef>

namespace ctk{
	template<char ... Chars>
	class const_str{
		public:
			static constexpr const char *c_str() noexcept{ return arr; }

			static constexpr char arr[] = {Chars..., 0};
	};

	template<typename...>
	struct concat;

	template<char ... LhsChs, char ... RhsChs>
	struct concat<const_str<LhsChs...>, const_str<RhsChs...>>{
		public:
			using type = const_str<LhsChs..., RhsChs...>;
	};

	namespace detail{
		template<std::size_t N, std::size_t ... Indices>
		auto make_const_str_impl(const char(&str)[N], std::index_sequence<Indices...>){
			return const_str<str[Indices]...>{};
		}
	}

	template<std::size_t N>
	auto make_const_str(const char(&str)[N]){
		return detail::make_const_str_impl(str, std::make_index_sequence<N>{});
	}
}

#endif // CTK_CONST_STR_HPP
