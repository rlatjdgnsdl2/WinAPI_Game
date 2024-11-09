#include "PreCompile.h"
#include "EngineTimer.h"

UEngineTimer::UEngineTimer() :Count{}, PrevTime{}, CurTime{}, TimeCounter {}, dDeltaTime{}, DeltaTime{}
{
	//	타이머 성능 Init
	QueryPerformanceFrequency(&Count);					//	1초에 셀 수 있는 카운트를 Count변수에 저장
	TimeCounter = static_cast<double>(Count.QuadPart);	//	double형으로 캐스팅	

	// PrevTime과 CurTime을 현재 성능 카운터 값으로 초기화
	QueryPerformanceCounter(&PrevTime);
	QueryPerformanceCounter(&CurTime);
}

UEngineTimer::~UEngineTimer()
{
}

void UEngineTimer::TimeCheck()	// 현재 시간과 이전에 기록된 시간 간의 시간 차이를 계산
{
	QueryPerformanceCounter(&CurTime);

	// 경과된 틱을 계산하고 초 단위로 변환
	double Tick = static_cast<double>(CurTime.QuadPart - PrevTime.QuadPart);
	dDeltaTime = Tick / TimeCounter;
	DeltaTime = static_cast<float>(dDeltaTime);

	// 다음 시간 계산을 위해 PrevTime을 업데이트
	PrevTime.QuadPart = CurTime.QuadPart;
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

