#pragma once
#include <type_traits>  // std::enable_if, std::is_arithmetic
typedef int T;
//template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
class FIntPoint {
public:
    T xPos;
    T yPos;

    // 기본 생성자
    FIntPoint() : xPos{ 0 }, yPos{ 0 } {}

    // 매개변수 생성자
    FIntPoint(T _xValue, T _yValue) : xPos{ _xValue }, yPos{ _yValue } {}

    // 산술 연산자 오버로딩
    FIntPoint operator+(const FIntPoint& _other) const {
        return FIntPoint(xPos + _other.xPos, yPos + _other.yPos);
    }

    FIntPoint operator-(const FIntPoint& _other) const {
        return FIntPoint(xPos - _other.xPos, yPos - _other.yPos);
    }

    FIntPoint operator*(const T& scalar) const {
        return FIntPoint(xPos * scalar, yPos * scalar);
    }

    FIntPoint operator/(const T& scalar) const {
        return FIntPoint(xPos / scalar, yPos / scalar);
    }

    // 비교 연산자
    bool operator==(const FIntPoint& _other) const {
        return xPos == _other.xPos && yPos == _other.yPos;
    }
    bool operator!=(const FIntPoint& _other) const {
        return !(xPos == _other.xPos && yPos == _other.yPos);
    }

    // 복합 연산자 +=, -=, *=, /=
    FIntPoint& operator+=(const FIntPoint& _other) {
        xPos += _other.xPos;
        yPos += _other.yPos;
        return *this;
    }

    FIntPoint& operator-=(const FIntPoint& _other) {
        xPos -= _other.xPos;
        yPos -= _other.yPos;
        return *this;
    }

    FIntPoint& operator*=(const T& _other) {
        xPos *= _other;
        yPos *= _other;
        return *this;
    }

    FIntPoint& operator/=(const T& _other) {
        xPos /= _other;
        yPos /= _other;
        return *this;
    }
    
};

