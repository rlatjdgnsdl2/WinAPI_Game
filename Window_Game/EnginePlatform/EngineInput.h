#pragma once


enum class KeyEvent
{
	Down,
	Press,
	Free,
	Up,
};

// 설명 : Input
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
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}
		return Keys[_KeyIndex].IsDown;
	}

	bool IsUp(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}
		return Keys[_KeyIndex].IsUp;
	}

	bool IsPress(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}
		return Keys[_KeyIndex].IsPress;
	}

	float IsPreeTime(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}
		return Keys[_KeyIndex].PressTime;
	}

	bool IsFree(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}
		return Keys[_KeyIndex].IsFree;
	}


	void BindAction(int _KeyIndex, KeyEvent _EventType, std::function<void()> _Function);

private:
	//	싱긑톤패턴적용을 위해 생성자 private
	UEngineInput();

	//	inner class
	class UEngineKey
	{
	public:
		UEngineKey() {}
		UEngineKey(int _Key) : Key(_Key) {}

		int Key = -1;
		// 키가 안눌리다가 처음 눌렸을때
		bool IsDown = false;
		// 키가 눌린 이후로 계속 누르고 있을때
		bool IsPress = false;
		// 키가 눌리다가 땠을때
		bool IsUp = false;
		// 키가 안누르고 있을때
		bool IsFree = true;
		float PressTime = 0.0f;

		std::vector<std::function<void()>> PressEvents;
		std::vector<std::function<void()>> DownEvents;
		std::vector<std::function<void()>> UpEvents;
		std::vector<std::function<void()>> FreeEvents;

		void EventCheck();
		void KeyCheck(float _DeltaTime);

	};
	std::map<int, UEngineKey> Keys;

};

