#pragma once

// 설명 : 델리게이트 구현
class EngineDelegate
{
public:
	//생성자, 소멸자
	EngineDelegate() = default;
	EngineDelegate(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}
	~EngineDelegate() = default;

	//연산자 오버로딩
	void operator=(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

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
	
	// 멤버함수
	void Clear()
	{
		Functions.clear();
	}
	bool IsBind()
	{
		return false == Functions.empty();
	}
	
private:
	std::list<std::function<void()>> Functions;
};

