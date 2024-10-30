#pragma once
#include <string>

// ���� :
class UObject
{
public:
	// constrcuter destructer
	UObject();

	// Ȥ���� �ڽĵ��� �Ҹ��ڰ� ȣ�� �ȵǴ� ��츦 ����������
	// �����Լ� ���̺��� ���� ���̹Ƿ� �ظ��ϸ� �ڽ����� �Ҹ��ڰ� ȣ��ȵǴ� ���� ���� ���̴�.
	virtual ~UObject();

	// delete Function
	UObject(const UObject& _Other) = delete;
	UObject(UObject&& _Other) noexcept = delete;
	UObject& operator=(const UObject& _Other) = delete;
	UObject& operator=(UObject&& _Other) noexcept = delete;

	// �̸� �����Ҷ� ���� �ϰ� ������ �������̵���.
	virtual void SetName(std::string_view _Name)
	{
		Name = _Name.data();
	}

protected:

private:
	std::string Name;

};

