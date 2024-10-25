#include "PreCompile.h"
#include "EngineTimer.h"

UEngineTimer::UEngineTimer()
{
	//	Init
	QueryPerformanceFrequency(&Count);					//	1�ʿ� �� �� �ִ� ī��Ʈ�� Count������ ����
	TimeCounter = static_cast<double>(Count.QuadPart);		
	QueryPerformanceCounter(&PrevTime);
	QueryPerformanceCounter(&CurTime);
}

UEngineTimer::~UEngineTimer()
{
}

void UEngineTimer::TimeStart()
{
	QueryPerformanceCounter(&PrevTime);
}

float UEngineTimer::End()
{
	TimeCheck();
	return GetDeltaTime();
}

double UEngineTimer::DEnd()
{
	TimeCheck();
	return GetDoubleDeltaTime();
}

void UEngineTimer::TimeCheck()
{
	QueryPerformanceCounter(&CurTime);

	double Tick = static_cast<double>(CurTime.QuadPart - PrevTime.QuadPart);
	dDeltaTime = Tick / TimeCounter;
	DeltaTime = static_cast<float>(dDeltaTime);
	PrevTime.QuadPart = CurTime.QuadPart;
}
