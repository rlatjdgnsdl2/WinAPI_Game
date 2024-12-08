#pragma once

// ���� : �⺻���� ��ü�� �̸�, �����ֱ�� ���¸� �����ϴ� ���̽� Ŭ����
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
	// �ʿ�� �������̵� ����
	virtual void SetName(std::string_view _Name) { Name = _Name.data(); }

	virtual bool IsActive() { return IsActiveValue && false == IsDestroyValue; }
	virtual bool IsDestroy() { return IsDestroyValue; }

	// ��ü�� �ı��ϴ� �Լ�, _Time �Ŀ� �ı� (�⺻�� 0)
	void Destroy(float _Time = 0.0f) {
		DeathTime = _Time;
		if (0.0f < _Time) {
			IsDeathTimeValue = true;
			return;
		}
		IsDestroyValue = true;
	}

	// �ı��� �ð��� �Ǿ����� Ȯ���ϴ� �Լ� (�� �����Ӹ��� ȣ���Ͽ� �ð� ��� üũ)
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

	// ��ü�� ����� ��� �Լ�
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

