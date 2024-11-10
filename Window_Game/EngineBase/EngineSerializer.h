#pragma once

// ���� : ����ȭ �� ������ȭ ���� Ŭ����
class UEngineSerializer
{
public:
	// constrcuter destructer
	UEngineSerializer();
	~UEngineSerializer();
	// delete Function
	UEngineSerializer(const UEngineSerializer& _Other) = delete;
	UEngineSerializer(UEngineSerializer&& _Other) noexcept = delete;
	UEngineSerializer& operator=(const UEngineSerializer& _Other) = delete;
	UEngineSerializer& operator=(UEngineSerializer&& _Other) noexcept = delete;

	//	�����͸� �ۼ��ϴ� �Լ�
	void Write(void* _Data, unsigned int _Size);

	//	�پ��� �����͵�
	void operator<<(int& _Data) { Write(&_Data, sizeof(int)); }
	void operator<<(bool& _Data) { Write(&_Data, sizeof(bool)); }
	void operator<<(FVector2D& _Data) { Write(&_Data, sizeof(FVector2D)); }
	void operator<<(FIntPoint& _Data) { Write(&_Data, sizeof(FIntPoint)); }
	void operator<<(std::string& _Data)
	{
		int Size = static_cast<int>(_Data.size());
		// ���ڿ� ũ�� ���� ����
		operator<<(Size);
		Write(&_Data[0], static_cast<int>(_Data.size()));
	}
	//	����ȭ ������ ��ü�� 
	void operator<<(class SerializableObject& _Data);

	// Vector
	template<typename DataType>
	void operator<<(std::vector<DataType>& _vector)
	{
		int Size = static_cast<int>(_vector.size());
		operator<<(Size);
		for (size_t i = 0; i < _vector.size(); i++)
		{
			operator<<(_vector[i]);
		}
	}
	// �����͸� �о���� �Լ�
	void Read(void* _Data, unsigned int _Size);

	void operator>>(int& _Data) { Read(&_Data, sizeof(int)); }

	void operator>>(bool& _Data) { Read(&_Data, sizeof(bool)); }

	void operator>>(FVector2D& _Data) { Read(&_Data, sizeof(FVector2D)); }

	void operator>>(FIntPoint& _Data) { Read(&_Data, sizeof(FIntPoint)); }

	void operator>>(std::string& _Data)
	{
		int Size;
		// ���ڿ� ũ�� ���� �б�
		operator>>(Size);
		// ���ڿ� ũ�� ����
		_Data.resize(Size);
		Read(&_Data[0], static_cast<int>(_Data.size()));
	}
	void operator>>(class SerializableObject& _Data);

	template<typename DataType>
	void operator>>(std::vector<DataType>& _vector)
	{
		int Size = 0;
		operator>>(Size);
		_vector.resize(Size);
		for (size_t i = 0; i < _vector.size(); i++)
		{
			operator>>(_vector[i]);
		}
	}

	void* GetDataPtr()
	{
		return &Data[0];
	}

	int GetWriteOffset()
	{
		return WriteOffset;
	}

	void DataResize(int _Value)
	{
		Data.resize(_Value);
	}

protected:

private:
	int WriteOffset = 0;
	int ReadOffset = 0;
	// ����ȭ�� ������ 
	std::vector<char> Data;
};

// ����ȭ ������ ��ü �������̽�
class SerializableObject
{
public:
	virtual void Serialize(UEngineSerializer& _Ser) = 0;
	virtual void DeSerialize(UEngineSerializer& _Ser) = 0;
};

