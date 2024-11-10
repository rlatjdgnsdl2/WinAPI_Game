#pragma once

// ���� : Delegate Ŭ����
class EngineDelegate
{
public:
	// constrcuter destructer
	EngineDelegate();

	//	�����ڿ��� �⺻������ ���ε� ����
	EngineDelegate(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

	~EngineDelegate();

	//	������� �ʴٸ� true
	bool IsBind()
	{
		return false == Functions.empty();
	}

	//	��������Ʈ �߰�
	void operator+=(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

	//	�Լ�ó�� ���̰� �����ε� ��������Ʈ �ȿ� �ִ� �Լ� ��� ����
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

