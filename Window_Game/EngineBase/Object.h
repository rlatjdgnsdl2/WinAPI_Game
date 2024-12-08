#pragma once

// 설명 : 기본적인 객체의 이름, 생명주기와 상태를 관리하는 베이스 클래스
class UObject
{
public:
	// constrcuter destructer
	UObject();
	virtual ~UObject() = 0;

	// delete Function
	UObject(const UObject& _Other) = delete;
	UObject(UObject&& _Other) noexcept = delete;
	UObject& operator=(const UObject& _Other) = delete;
	UObject& operator=(UObject&& _Other) noexcept = delete;

	std::string GetName() const { return Name; }
	std::string_view GetNameView() const { return Name.c_str(); }
	// 필요시 오버라이드 가능
	virtual void SetName(std::string_view _Name) { Name = _Name.data(); }

	virtual bool IsActive() { return IsActiveValue && false == IsDestroyValue; }
	virtual bool IsDestroy() { return IsDestroyValue; }

	// 객체를 파괴하는 함수, _Time 후에 파괴 (기본값 0)
	void Destroy(float _Time = 0.0f) {
		DeathTime = _Time;
		if (0.0f < _Time) {
			IsDeathTimeValue = true;
			return;
		}
		IsDestroyValue = true;
	}

	// 파괴될 시간이 되었는지 확인하는 함수 (매 프레임마다 호출하여 시간 경과 체크)
	virtual void ReleaseTimeCheck(float _DeltaTime) {
		if (false == IsDeathTimeValue) {
			return;
		}
		CurDeathTime += _DeltaTime;
		if (DeathTime <= CurDeathTime) {
			IsDestroyValue = true;
		}
	}

	virtual void ReleaseCheck(float _DeltaTime) {}
	virtual void SetDeathTime(float _DeathTime) {
		DeathTime = _DeathTime;
	}

	void SetActive(bool _IsActive) { IsActiveValue = _IsActive; }
	void SetActiveSwitch() { IsActiveValue = !IsActiveValue; }

	// 객체의 디버그 모드 함수
	bool IsDebug() const { return IsDebugValue; }
	void DebugOn() { IsDebugValue = true; }
	void DebugOff() { IsDebugValue = false; }
	void DebugSwitch() { IsDebugValue = !IsDebugValue; }


	void TestDebugCheck()
	{
		if (true == TestDebug)
		{
			int a = 0;
		}
	}

protected:

private:
	std::string Name;

	bool TestDebug = false;

	bool IsActiveValue = true;
	bool IsDestroyValue = false;
	bool IsDeathTimeValue = false;

	float DeathTime = 0.0f;
	float CurDeathTime = 0.0f;

	bool IsDebugValue = false;

};

