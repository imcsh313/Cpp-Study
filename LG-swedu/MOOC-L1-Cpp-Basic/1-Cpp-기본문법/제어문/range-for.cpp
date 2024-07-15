#include <iostream>
#include <print>
#include <ranges>

bool isOdd(int x);

int main()
{
	int x[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// for (int i = 0; i < 10; i++) // 배열의 크기가 바뀌면 'i < 10' 부분도 바꿔야 함
	// for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) // C style
	for(int i = 0; i < std::size(x); i++) // C++ style
	{
		std::cout << x[i] << ", ";
	}

	std::cout << std::endl;

	// for(int e : x)
	// for(auto e : x) // 1, 2, ... , 10
	// for(auto e : std::views::reverse(x)) // 거꾸로 출력 10, 9, ... , 1
	// for(auto e : std::views::take(x, 3)) // x부터 3개만 얻음 1, 2, 3
	// for(auto e : std::views::take(std::views::reverse(x), 3)) // 중복 사용 가능 10, 9, 8
	// for(auto e : std::views::drop(x, 3)) // x부터 3개 빼고 시작 4, 5, ... , 10
	// for(auto e : std::views::filter(x, isOdd)) // 함수에 e를 넣어서 참이면 실행 1, 3, ... , 9
	for (auto e : std::views::filter(x, [](auto x) {return x % 2; })) // lambda expression 1, 3, ... , 9
	{
		std::print("{}, ", e);
	}

	std::cout << std::endl;

	return 0;
}

bool isOdd(int x)
{
	return x % 2;
}
