#pragma once
 

//	Ό³Έν:
class BoxUI
{
public:
	//	constrcuter, destructer
	BoxUI();
	BoxUI(int _TextCount);
	virtual ~BoxUI();

	//	delete Function
	BoxUI(const BoxUI& _Other) = delete;
	BoxUI(BoxUI&& _Other) noexcept = delete;
	BoxUI& operator=(const BoxUI& _Other) = delete;
	BoxUI& operator=(BoxUI&& _Other) noexcept = delete;

protected:

private:
	class ABox* Box;
	std::list<class AText*> Texts;

};

