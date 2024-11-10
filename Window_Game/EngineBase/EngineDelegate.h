#pragma once

// 설명 : Delegate 클래스
class EngineDelegate
{
public:
	// constrcuter destructer
	EngineDelegate();

	//	생성자에서 기본적으로 바인딩 가능
	EngineDelegate(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

	~EngineDelegate();

	//	비어있지 않다면 true
	bool IsBind()
	{
		return false == Functions.empty();
	}

	//	델리게이트 추가
	void operator+=(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

	//	함수처럼 보이게 오버로딩 델리게이트 안에 있는 함수 모두 실행
	void operator()()
	{
		std::list<std::function<void()>>::iterator StartIter = Functions.begin();
		std::list<std::function<void()>>::iterator EndIter = Functions.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			std::function<void()>& Function = *StartIter;
			Function();
		}
	}
	void Clear()
	{
		Functions.clear();
	}

protected:

private:
	std::list<std::function<void()>> Functions;
};

