// The MIT License (MIT)
//
// Copyright (c) 2016 Darrell Wright
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files( the "Software" ), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <cstdlib>

template<typename T>
constexpr auto euclid_gcd( T m, T n ) noexcept {
	auto r = m%n;
	while( (r = m%n) > 0 ) {
		m = n;
		n = r;
	}
	return n;
}

int main( int argc, char** argv ) {
	assert( argc == 3 );
	auto const m = strtoull( argv[1], nullptr, 10 );
	auto const n = strtoull( argv[2], nullptr, 10 );
	if( 0 == m || 0 == n ) { 
		std::cout << "0\n";
		return EXIT_SUCCESS;
	}
	std::cout << euclid_gcd( m, n ) << '\n';
	return EXIT_SUCCESS;
}
