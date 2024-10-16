#pragma once
#include <type_traits>  // std::enable_if, std::is_arithmetic
typedef int T;
//template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
class FIntPoint {
public:
    T xPos;
    T yPos;

    // �⺻ ������
    FIntPoint() : xPos{ 0 }, yPos{ 0 } {}

    // �Ű����� ������
    FIntPoint(T _xValue, T _yValue) : xPos{ _xValue }, yPos{ _yValue } {}

    // ��� ������ �����ε�
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

    // �� ������
    bool operator==(const FIntPoint& _other) const {
        return xPos == _other.xPos && yPos == _other.yPos;
    }
    bool operator!=(const FIntPoint& _other) const {
        return !(xPos == _other.xPos && yPos == _other.yPos);
    }

    // ���� ������ +=, -=, *=, /=
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

