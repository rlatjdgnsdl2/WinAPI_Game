#pragma once

class FIntPoint {
public:
    int xPos;
    int yPos;

    static const FIntPoint LEFT;
    static const FIntPoint RIGHT;
    static const FIntPoint UP;
    static const FIntPoint DOWN;

    // �⺻ ������
    FIntPoint() : xPos{ 0 }, yPos{ 0 } {}

    // �Ű����� ������
    FIntPoint(int _xValue, int _yValue) : xPos{ _xValue }, yPos{ _yValue } {}

    // ��� ������ �����ε�
    FIntPoint operator+(const FIntPoint& _other) const {
        return FIntPoint(xPos + _other.xPos, yPos + _other.yPos);
    }

    FIntPoint operator-(const FIntPoint& _other) const {
        return FIntPoint(xPos - _other.xPos, yPos - _other.yPos);
    }

    FIntPoint operator*(const int& scalar) const {
        return FIntPoint(xPos * scalar, yPos * scalar);
    }

    FIntPoint operator/(const int& scalar) const {
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

    FIntPoint& operator*=(const int& scalar) {
        xPos *= scalar;
        yPos *= scalar;
        return *this;
    }

    FIntPoint& operator/=(const int& scalar) {
        xPos /= scalar;
        yPos /= scalar;
        return *this;
    }
    
};

