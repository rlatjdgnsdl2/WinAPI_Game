#pragma once
#include <EngineBase/EngineDebug.h>

enum class KeyEvent
{
	Down,
	Press,
	Free,
	Up,
};

// ���� : Input ��� Ŭ���� (Singleton)
class UEngineInput
{
public:
	// constrcuter destructer
	~UEngineInput();
	// delete Function
	UEngineInput(const UEngineInput& _Other) = delete;
	UEngineInput(UEngineInput&& _Other) noexcept = delete;
	UEngineInput& operator=(const UEngineInput& _Other) = delete;
	UEngineInput& operator=(UEngineInput&& _Other) noexcept = delete;
	
	//	Singleton
	static UEngineInput& GetInst()
	{
		static UEngineInput Inst = UEngineInput();
		return Inst;
	}

	void KeyCheck(float _DeltaTime);
	void EventCheck(float _DeltaTime);

	bool IsDown(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("��ϵ��� ���� Ű�Դϴ�.");
			return false;
		}
		return Keys[_KeyIndex].IsDown;
	}

	bool IsUp(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("��ϵ��� ���� Ű�Դϴ�.");
			return false;
		}
		return Keys[_KeyIndex].IsUp;
	}

	bool IsPress(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("��ϵ��� ���� Ű�Դϴ�.");
			return false;
		}
		return Keys[_KeyIndex].IsPress;
	}

	float IsPressTime(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("��ϵ��� ���� Ű�Դϴ�.");
			return false;
		}
		return Keys[_KeyIndex].PressTime;
	}

	bool IsFree(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("��ϵ��� ���� Ű�Դϴ�.");
			return false;
		}
		return Keys[_KeyIndex].IsFree;
	}
	bool IsDoubleClick(int _KeyIndex, float _Time)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("������ ��ϵ��� ���� Ű�� �����մϴ�.");
			return false;
		}

		return Keys[_KeyIndex].IsDown && Keys[_KeyIndex].FreeTime < _Time;
	}

	// Ű �̺�Ʈ�� �Լ��� ���ε��ϴ� �Լ�
	void BindAction(int _KeyIndex, KeyEvent _EventType, std::function<void()> _Function);

private:
	//	�̃P������������ ���� ������ private
	UEngineInput();
	void RegistKey();

	//	inner class
	class UEngineKey
	{
	public:
		UEngineKey() {}
		UEngineKey(int _Key) : Key(_Key) {}

		int Key = -1;
		// Ű�� �ȴ����ٰ� ó�� ��������
		bool IsDown = false;
		// Ű�� ���� ���ķ� ��� ������ ������
		bool IsPress = false;
		// Ű�� �����ٰ� ������
		bool IsUp = false;
		// Ű�� �ȴ����� ������
		bool IsFree = true;
		float PressTime = 0.0f;
		float FreeTime = 0.0f;

		std::vector<std::function<void()>> PressEvents;
		std::vector<std::function<void()>> DownEvents;
		std::vector<std::function<void()>> UpEvents;
		std::vector<std::function<void()>> FreeEvents;

		void EventCheck();
		void KeyCheck(float _DeltaTime);

	};

	std::map<int, UEngineKey> Keys;

};


