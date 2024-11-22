#pragma once

//	Ό³Έν:
class UContentsMath
{
public:
	static DIR FIntPoint_To_DIR(const FIntPoint& _FIntPoint);
	static DIR FVector2D_To_DIR(const FVector2D& _FVector2D);
	static FVector2D DIR_To_FVector2D(DIR _Dir);
	static FIntPoint DIR_To_FIntPoint(DIR _Dir);
	static DIR ReverseDir(DIR _Dir);

};

