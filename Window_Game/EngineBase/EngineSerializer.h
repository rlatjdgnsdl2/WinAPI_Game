#pragma once

// 설명 : 직렬화 및 역직렬화 수행 클래스
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

	//	데이터를 작성하는 함수
	void Write(void* _Data, unsigned int _Size);

	//	다양한 데이터들
	void operator<<(int& _Data) { Write(&_Data, sizeof(int)); }
	void operator<<(bool& _Data) { Write(&_Data, sizeof(bool)); }
	void operator<<(FVector2D& _Data) { Write(&_Data, sizeof(FVector2D)); }
	void operator<<(FIntPoint& _Data) { Write(&_Data, sizeof(FIntPoint)); }
	void operator<<(std::string& _Data)
	{
		int Size = static_cast<int>(_Data.size());
		// 문자열 크기 먼저 저장
		operator<<(Size);
		Write(&_Data[0], static_cast<int>(_Data.size()));
	}
	//	직렬화 가능한 객체들 
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
	// 데이터를 읽어오는 함수
	void Read(void* _Data, unsigned int _Size);

	void operator>>(int& _Data) { Read(&_Data, sizeof(int)); }

	void operator>>(bool& _Data) { Read(&_Data, sizeof(bool)); }

	void operator>>(FVector2D& _Data) { Read(&_Data, sizeof(FVector2D)); }

	void operator>>(FIntPoint& _Data) { Read(&_Data, sizeof(FIntPoint)); }

	void operator>>(std::string& _Data)
	{
		int Size;
		// 문자열 크기 먼저 읽기
		operator>>(Size);
		// 문자열 크기 설정
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
	// 직렬화된 데이터 
	std::vector<char> Data;
};

// 직렬화 가능한 객체 인터페이스
class SerializableObject
{
public:
	virtual void Serialize(UEngineSerializer& _Ser) = 0;
	virtual void DeSerialize(UEngineSerializer& _Ser) = 0;
};

