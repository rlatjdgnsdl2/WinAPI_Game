#pragma once

// ���� :Ÿ�̸�Ŭ����
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

	//	�Ϲ�
	void TimeCheck();		//	DeltaTime ���ϴ� �Լ�
	void TimeStart();		//	Ÿ�̸� ����
	float End();			//	Ÿ�̸� �� (float��ȯ)	
	double DEnd();			//	Ÿ�̸� �� (double��ȯ)

private:
	LARGE_INTEGER Count;	//	1�ʿ� �����ִ� count
	LARGE_INTEGER PrevTime;
	LARGE_INTEGER CurTime;

	double TimeCounter;
	double dDeltaTime;
	float DeltaTime;





};

