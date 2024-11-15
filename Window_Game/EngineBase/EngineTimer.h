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

	
	inline float GetDeltaTime() const { return DeltaTime; }
	inline double GetDoubleDeltaTime() const { return dDeltaTime; }

	void TimeCheck();		
	void TimeStart();		
	float End();			
	double DEnd();			

private:
	LARGE_INTEGER Count;	
	LARGE_INTEGER PrevTime;
	LARGE_INTEGER CurTime;

	double TimeCounter;
	double dDeltaTime;
	float DeltaTime;





};

