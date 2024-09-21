#include <iostream>

using namespace std;

class Vector // struct로도 자주 사용
{
public:
	float x;
	float y;
	float z;

	// 단항 연산자
	Vector operator+() const
	{
		return Vector{ x, y, z };
	}

	Vector operator-() const
	{
		return Vector{ -x, -y, -z };
	}

	// 이항 연산자
	Vector operator+(const Vector v) const // 계산의 대상이 const인 경우 고려
	{
		return Vector{ x + v.x, y + v.y, z + v.z };
	}

	Vector operator-(const Vector v) const
	{
		return Vector{ x - v.x, y - v.y, z - v.z };
	}

	Vector operator*(float f) const
	{
		return Vector{ x * f, y * f, z * f };
	}

	float operator*(const Vector v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	Vector operator/(float f) const
	{
		return Vector{ x / f, y / f, z / f };
	}

	// 전위 연산자
	Vector& operator++() // 자신을 바꾸기 때문에 const는 사용 불가
	{
		++x;
		++y;
		++z;

		return *this;
	}

	Vector& operator--()
	{
		--x;
		--y;
		--z;

		return *this;
	}

	// 후위 연산자
	Vector operator++(int) // 전위 연산자와 함수 모양 구분하기 위해 int 추가
	{
		Vector temp = *this;
		++(*this);
		return temp;
	}

	Vector operator--(int)
	{
		Vector temp = *this;
		--(*this);
		return temp;
	}

	void print()
	{
		cout << "x: " << x << " y: " << y << " z: " << z << endl;
	}
};

int main()
{
	Vector v0{ 1, 2, 3 };
	Vector v1{ 4, 5, 6 };

	Vector v2 = v0 + v1;
	Vector v3 = -v0;
}
