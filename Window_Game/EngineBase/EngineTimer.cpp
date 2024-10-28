#include "PreCompile.h"
#include "EngineTimer.h"

UEngineTimer::UEngineTimer() :Count{}, PrevTime{}, CurTime{}, TimeCounter {}, dDeltaTime{}, DeltaTime{}
{
	//	Ÿ�̸� ���� Init
	QueryPerformanceFrequency(&Count);					//	1�ʿ� �� �� �ִ� ī��Ʈ�� Count������ ����
	TimeCounter = static_cast<double>(Count.QuadPart);	//	double������ ĳ����	

	// PrevTime�� CurTime�� ���� ���� ī���� ������ �ʱ�ȭ
	QueryPerformanceCounter(&PrevTime);
	QueryPerformanceCounter(&CurTime);
}

UEngineTimer::~UEngineTimer()
{
}

void UEngineTimer::TimeCheck()	// ���� �ð��� ������ ��ϵ� �ð� ���� �ð� ���̸� ���
{
	QueryPerformanceCounter(&CurTime);

	// ����� ƽ�� ����ϰ� �� ������ ��ȯ
	double Tick = static_cast<double>(CurTime.QuadPart - PrevTime.QuadPart);
	dDeltaTime = Tick / TimeCounter;
	DeltaTime = static_cast<float>(dDeltaTime);

	// ���� �ð� ����� ���� PrevTime�� ������Ʈ
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

