#pragma once

// 설명 : 델리게이트 구현
class EngineDelegate
{
public:
	//	constrcuter, destructer
	EngineDelegate() = default;
	EngineDelegate(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}
	~EngineDelegate() = default;

	void operator=(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

	//	벡터안에 있는 모든 함수 실행
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
	//	비었으면 false 리턴
	bool IsBind()	
	{
		return false == Functions.empty();
	}
	
private:
	std::list<std::function<void()>> Functions;	
};

