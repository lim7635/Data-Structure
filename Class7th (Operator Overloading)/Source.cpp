#include <iostream>
using namespace std;

class Vector2
{
public:
	int x;
	int y;

	Vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	// 연산자 오버로딩(operator)
	Vector2 operator+(const Vector2& vector)
	{
		Vector2 other(this->x + vector.x, this->y + vector.y);

		return other;
	}

	Vector2 operator-(const Vector2& vector)
	{
		Vector2 other(this->x - vector.x, this->y - vector.y);

		return other;
	}

	Vector2 operator*(const Vector2& vector)
	{
		Vector2 other(this->x * vector.x, this->y * vector.y);

		return other;
	}

	Vector2 operator*(int value)
	{
		Vector2 other(this->x * value, this->y * value);

		return other;
	}

	Vector2 operator/(const Vector2& vector)
	{
		Vector2 other(this->x / vector.x, this->y / vector.y);

		return other;
	}
};

// 연산자 오버로딩 교환 법칙
Vector2 operator*(int value, Vector2 vector)
{
	return vector * value;
}

int main()
{
	Vector2 vector1(10, 20);
	Vector2 vector2(5, 5);

	Vector2 plus = vector1 + vector2;
	cout << "plus의 x 값 : " << plus.x << endl;
	cout << "plus의 y 값 : " << plus.y << endl;

	cout << endl;

	Vector2 minus = vector1 - vector2;
	cout << "minus의 x 값 : " << minus.x << endl;
	cout << "minus의 y 값 : " << minus.y << endl;

	cout << endl;

	Vector2 multiple = vector1 * vector2;
	cout << "multiple의 x 값 : " << multiple.x << endl;
	cout << "multiple의 y 값 : " << multiple.y << endl;

	cout << endl;

	Vector2 divide = vector1 / vector2;
	cout << "divide의 x 값 : " << divide.x << endl;
	cout << "divide의 y 값 : " << divide.y << endl;

	cout << endl;

	Vector2 vector3 = vector1 * 5;
	cout << "vector3의 x 값 : " << vector3.x << endl;
	cout << "vector3의 y 값 : " << vector3.y << endl;

	cout << endl;

	Vector2 vector4 = 10 * vector1;
	cout << "vector4의 x 값 : " << vector4.x << endl;
	cout << "vector4의 y 값 : " << vector4.y << endl;

	return 0;
}