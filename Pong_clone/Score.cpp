#include "Score.h"
//#include "Ball.h"
int _n = 0;
int _p = 0;
Score::Score()
{
	
	//Load("./Files/Score0-0.png");
	//assert(IsLoaded());
}

Score::~Score()
{

}

void Score::ScoreCount(int n, int p)
{
	//std::cout << n << p <<"count" << std::endl;
	/*if (_n == 1 && _p == 0)
	{
		Load("./Files/Score0-1.png");
		assert(IsLoaded());
	}*/
}

void Score::Update(float elapsedTime)
{
	
	//std::cout << _p << "render" << std::endl;
	if(_p <= 10)
	{
		NameFile(_p);
		Load(_filename);
		assert(IsLoaded());
	}
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
	SetPosition(979+95+100,82);
	
}


int Score::NameFile(int i)
{
		std::stringstream ss;
		ss << "./Files/Score_" << i << "_P.png";
		_filename = ss.str();
		//std::cout << _filename << '\n';
	return 0;
}

ScoreN::ScoreN()
{

	//Load("./Files/Score0-0.png");
	//assert(IsLoaded());
}

ScoreN::~ScoreN()
{

}

void ScoreN::Update(float elapsedTime)
{

	//std::cout << _n << "render" << std::endl;
	if (_n <= 10)
	{
		NameFile(_n);
		Load(_filename);
		assert(IsLoaded());
	}
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
	SetPosition(979 - 95 - 100, 82);

}


int ScoreN::NameFile(int i)
{
	std::stringstream ss;
	ss << "./Files/Score_" << i << "_N.png";
	_filename = ss.str();
	//std::cout << _filename << '\n';
	return 0;
}

