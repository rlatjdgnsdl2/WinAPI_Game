#pragma once

// ���� : ��������Ʈ ����
class EngineDelegate
{
public:
	//������, �Ҹ���
	EngineDelegate() = default;
	EngineDelegate(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}
	~EngineDelegate() = default;

	//������ �����ε�
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
	
	// ����Լ�
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

