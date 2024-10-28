#pragma once
#include <Windows.h>

// ���� :
class UEngineTimer
{
public:
	// constrcuter destructer
	UEngineTimer();
	~UEngineTimer();

	// delete Function
	UEngineTimer(const UEngineTimer& _Other) = delete;
	UEngineTimer(UEngineTimer&& _Other) noexcept = delete;
	UEngineTimer& operator=(const UEngineTimer& _Other) = delete;
	UEngineTimer& operator=(UEngineTimer&& _Other) noexcept = delete;

	float GetDeltaTime() { return DeltaTime; }
	double GetDoubleDeltaTime() { return dDeltaTime; }

	void TimeCheck();
	void TimeStart();	//	Ÿ�̸� ����
	double DEnd();		//	Ÿ�̸� ��
	float End();		//	Ÿ�̸� ��


private:
	LARGE_INTEGER Count = LARGE_INTEGER();		//	1�ʿ� �����ִ� count
	LARGE_INTEGER PrevTime = LARGE_INTEGER();	
	LARGE_INTEGER CurTime = LARGE_INTEGER();
	
	double TimeCounter = 0.0f;
	double dDeltaTime = 0.0;
	float DeltaTime = 0.0f;
	

	

	

};

