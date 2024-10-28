#pragma once

// 설명 :타이머클래스
class UEngineTimer
{
public:
	//	constrcuter destructer
	UEngineTimer();
	~UEngineTimer();

	//	delete Function
	UEngineTimer(const UEngineTimer& _Other) = delete;
	UEngineTimer(UEngineTimer&& _Other) noexcept = delete;
	UEngineTimer& operator=(const UEngineTimer& _Other) = delete;
	UEngineTimer& operator=(UEngineTimer&& _Other) noexcept = delete;

	//	inline
	inline float GetDeltaTime() const { return DeltaTime; }
	inline double GetDoubleDeltaTime() const { return dDeltaTime; }

	//	일반
	void TimeCheck();		//	DeltaTime 구하는 함수
	void TimeStart();		//	타이머 시작
	float End();			//	타이머 끝 (float반환)	
	double DEnd();			//	타이머 끝 (double반환)

private:
	LARGE_INTEGER Count;	//	1초에 셀수있는 count
	LARGE_INTEGER PrevTime;
	LARGE_INTEGER CurTime;

	double TimeCounter;
	double dDeltaTime;
	float DeltaTime;





};

