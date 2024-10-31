#pragma once

// ���� : ��������Ʈ ����
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

	//	���;ȿ� �ִ� ��� �Լ� ����
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
	//	������� false ����
	bool IsBind()	
	{
		return false == Functions.empty();
	}
	
private:
	std::list<std::function<void()>> Functions;	
};

