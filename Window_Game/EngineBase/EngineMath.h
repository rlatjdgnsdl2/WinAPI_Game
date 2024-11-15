#pragma once

// 수학 연산을 위한 유틸리티 클래스
class UEngineMath
{
public:
	//	제곱근
	static float Sqrt(float _Value) { return ::sqrtf(_Value); }
	template <typename DataType>
	DataType ClampMax(DataType value, DataType maxValue)
	{
		return (value > maxValue) ? maxValue : value;
	}

	template <typename DataType>
	DataType ClampMin(DataType value, DataType minValue)
	{
		return (value < minValue) ? minValue : value;
	}

	template <typename DataType>
	static DataType Clamp(DataType value, DataType minValue, DataType maxValue)
	{
		if (value < minValue)
			return minValue;
		else if (value > maxValue)
			return maxValue;
		else
			return value;
	}




};

class FVector2D
{
public:
	float X = 0.0f;
	float Y = 0.0f;

	FVector2D() {}
	FVector2D(float _X, float _Y) : X(_X), Y(_Y) {}
	FVector2D(int _X, int _Y) : X(static_cast<float>(_X)), Y(static_cast<float>(_Y)) {}
	FVector2D(long _X, long _Y) : X(static_cast<float>(_X)), Y(static_cast<float>(_Y)) {}

	static const FVector2D ZERO;
	static const FVector2D LEFT;
	static const FVector2D RIGHT;
	static const FVector2D UP;
	static const FVector2D DOWN;

	//	선형보간 (시작 위치와 목표 위치 사이의 값)
	static FVector2D LerpClamp(FVector2D _StartLocation, FVector2D _TargetLocation, float _t);

	//	벡터길이
	float Length() const { return UEngineMath::Sqrt(X * X + Y * Y); }

	//	정규화
	static FVector2D Normalize(FVector2D _Value);
	//	정규화
	void Normalize();

	int iX() const { return static_cast<int>(X); }
	int iY() const { return static_cast<int>(Y); }

	//	중앙값
	FVector2D Half() const { return { X * 0.5f, Y * 0.5f }; }
	float hX() const { return X * 0.5f; }
	float hY() const { return Y * 0.5f; }


	//	FIntPoint로 변환
	class FIntPoint ConvertToPoint() const;

	//	내적
	float Dot(FVector2D _Other) const { return X * _Other.X + Y * _Other.Y; }

	//	0이 있으면 true;
	bool IsZeroed() const { return X == 0.0f || Y == 0.0f; }

	//	연산자들

	FVector2D operator+(const FVector2D& _Other) const
	{
		FVector2D Result;
		Result.X = X + _Other.X;
		Result.Y = Y + _Other.Y;
		return Result;
	}

	FVector2D operator-(const FVector2D& _Other) const
	{
		FVector2D Result;
		Result.X = X - _Other.X;
		Result.Y = Y - _Other.Y;
		return Result;
	}

	FVector2D operator/(int _Value) const
	{
		FVector2D Result;
		Result.X = X / _Value;
		Result.Y = Y / _Value;
		return Result;
	}

	FVector2D operator*(float _Value) const
	{
		FVector2D Result;
		Result.X = X * _Value;
		Result.Y = Y * _Value;
		return Result;
	}

	FVector2D& operator*=(float _Other)
	{
		X *= _Other;
		Y *= _Other;
		return *this;
	}



	FVector2D& operator+=(const FVector2D& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
		return *this;
	}

	FVector2D& operator-=(const FVector2D& _Other)
	{
		X -= _Other.X;
		Y -= _Other.Y;
		return *this;
	}
	FVector2D& operator*=(const FVector2D& _Other)
	{
		X *= _Other.X;
		Y *= _Other.Y;
		return *this;
	}



	// 벡터의 반대 방향을 반환하는 연산자
	FVector2D operator-() const
	{
		FVector2D Result;
		Result.X = -X;
		Result.Y = -Y;
		return Result;
	}

	//	출력용
	std::string ToString()
	{
		std::string Stream;

		Stream += "X : [";
		Stream += std::to_string(X);
		Stream += "] Y : [";
		Stream += std::to_string(Y);
		Stream += "]";
		return Stream;
	}

	// 비교 연산자 오버로드
	bool operator==(const FVector2D& _Other) const
	{
		return X == _Other.X && Y == _Other.Y;
	}
	// 정수로 변환 후 비교
	bool EqualToInt(const FVector2D& _Other) const
	{
		return iX() == _Other.iX() && iY() == _Other.iY();
	}

};

// 충돌 타입을 정의하는 열거형
enum class ECollisionType
{
	Point,
	Rect,
	CirCle,
	Max
};

class FTransform
{
private:
	friend class CollisionFunctionInit;

	static std::function<bool(const FTransform&, const FTransform&)> AllCollisionFunction[static_cast<int>(ECollisionType::Max)][static_cast<int>(ECollisionType::Max)];

public:
	static bool Collision(ECollisionType _LeftType, const FTransform& _Left, ECollisionType _RightType, const FTransform& _Right);

	// 완전히 같은 형의 함수죠?
	static bool PointToCirCle(const FTransform& _Left, const FTransform& _Right);
	static bool PointToRect(const FTransform& _Left, const FTransform& _Right);

	static bool RectToRect(const FTransform& _Left, const FTransform& _Right);
	static bool RectToCirCle(const FTransform& _Left, const FTransform& _Right);

	static bool CirCleToCirCle(const FTransform& _Left, const FTransform& _Right);
	static bool CirCleToRect(const FTransform& _Left, const FTransform& _Right);


	FVector2D Scale;
	FVector2D Location;


	FVector2D CenterLeftTop() const
	{
		return Location - Scale.Half();
	}

	FVector2D CenterLeftBottom() const
	{
		FVector2D Location;
		Location.X = Location.X - Scale.hX();
		Location.Y = Location.Y + Scale.hY();
		return Location;
	}

	float CenterLeft() const
	{
		return Location.X - Scale.hX();
	}

	float CenterTop() const
	{
		return Location.Y - Scale.hY();
	}

	FVector2D CenterRightTop() const
	{
		FVector2D Location;
		Location.X = Location.X + Scale.hX();
		Location.Y = Location.Y - Scale.hY();
		return Location;
	}

	FVector2D CenterRightBottom() const
	{
		return Location + Scale.Half();
	}

	float CenterRight() const
	{
		return Location.X + Scale.hX();
	}

	float CenterBottom() const
	{
		return Location.Y + Scale.hY();
	}
};



// 정수 좌표를 나타내는 클래스
class FIntPoint
{
public:
	int X = 0;
	int Y = 0;

	static const FIntPoint LEFT;
	static const FIntPoint RIGHT;
	static const FIntPoint UP;
	static const FIntPoint DOWN;

	FIntPoint() {}
	FIntPoint(int _X, int _Y) : X(_X), Y(_Y) {}
	FIntPoint(float _X, float _Y) :X(static_cast<int>(_X)), Y(static_cast<int>(_Y)) {}

	FIntPoint operator+(FIntPoint _Other) const
	{
		FIntPoint Result;
		Result.X = X + _Other.X;
		Result.Y = Y + _Other.Y;
		return Result;
	}

	FIntPoint operator-(FIntPoint _Other) const
	{
		FIntPoint Result;
		Result.X = X - _Other.X;
		Result.Y = Y - _Other.Y;
		return Result;
	}

	FIntPoint operator/(int _Value) const
	{
		FIntPoint Result;
		Result.X = X / _Value;
		Result.Y = Y / _Value;
		return Result;
	}

	FIntPoint operator*(int _Value) const
	{
		FIntPoint Result;
		Result.X = X * _Value;
		Result.Y = Y * _Value;
		return Result;
	}

	FVector2D operator*(float _Value) const
	{
		FVector2D Result;
		Result.X = X * _Value;
		Result.Y = Y * _Value;
		return Result;
	}



	bool operator==(FIntPoint _Other) const
	{
		return X == _Other.X && Y == _Other.Y;
	}

	FIntPoint& operator+=(FIntPoint _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
		return *this;
	}
	//	필요하면 추가예정
};







class UColor
{
public:
	static const UColor WHITE;
	static const UColor BLACK;

	union
	{
		int Color;
		struct
		{
			unsigned char R;
			unsigned char G;
			unsigned char B;
			unsigned char A;
		};
	};

	UColor(unsigned long _Value)
		:Color(_Value)
	{

	}

	bool operator==(const UColor& _Other)
	{
		return R == _Other.R && G == _Other.G && B == _Other.B;
	}


	UColor(unsigned char _R, unsigned char _G, unsigned char _B, unsigned char _A)
		:R(_R), G(_G), B(_B), A(_A)
	{

	}
};



