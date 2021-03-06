//Copyright (c) 2018 Emil Dotchevski
//Copyright (c) 2018 Second Spectrum, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_3BAB50A2B87E11E89EEB30600C39171A
#define UUID_3BAB50A2B87E11E89EEB30600C39171A

#include <ostream>

namespace boost { namespace leaf {

	template <class Name>
	char const * type() noexcept
	{
#ifdef __FUNCSIG__
		return __FUNCSIG__;
#else
		return __PRETTY_FUNCTION__;
#endif
	}

	namespace leaf_detail
	{
		template<class F, class E = void>
		struct is_printable
		{
			static constexpr bool value=false;
		};

		template<class F>
		struct is_printable<F, decltype(std::declval<std::ostream&>()<<std::declval<F const &>(), void())>
		{
			static constexpr bool value=true;
		};

		////////////////////////////////////////

		template <class Wrapper, bool WrapperPrintable=is_printable<Wrapper>::value, bool ValuePrintable=is_printable<decltype(Wrapper::value)>::value>
		struct diagnostic;

		template <class Wrapper, bool ValuePrintable>
		struct diagnostic<Wrapper, true, ValuePrintable>
		{
			static bool print( std::ostream & os, Wrapper const & x )
			{
				os << x;
				return true;
			}
		};

		template <class Wrapper>
		struct diagnostic<Wrapper, false, true>
		{
			static bool print( std::ostream & os, Wrapper const & x )
			{
				os << type<Wrapper>() << " = " << x.value;
				return true;
			}
		};

		template <class Wrapper>
		struct diagnostic<Wrapper, false, false>
		{
			static bool print( std::ostream & os, Wrapper const & )
			{
				os << type<Wrapper>() << " = N/A";
				return true;
			}
		};
	} //leaf_detail

} }

#endif
