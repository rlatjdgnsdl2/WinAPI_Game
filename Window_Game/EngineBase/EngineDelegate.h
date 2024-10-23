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

	//	operator overloading
	void operator=(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

	void operator()()	//	���;ȿ� �ִ� ��� �Լ� ����
	{
		std::list<std::function<void()>>::iterator StartIter = Functions.begin();
		std::list<std::function<void()>>::iterator EndIter = Functions.end();
		for (; StartIter != EndIter; ++StartIter)
		{
			std::function<void()>& Function = *StartIter;
			Function();
		}
	}
	
	//	public method
	void Clear()	
	{
		Functions.clear();
	}
	bool IsBind()	//	������� false ����
	{
		return false == Functions.empty();
	}
	
private:
	std::list<std::function<void()>> Functions;		//	��Ǻ���
};

