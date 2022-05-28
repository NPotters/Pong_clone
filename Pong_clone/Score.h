#pragma once
#include "stdafx.h"
#include "VisibleGameObjects.h"
extern int _n;
extern int _p;
class Score:
	public VisibleGameObject
{
public:
	Score();
	virtual ~Score();
	void ScoreCount(int n, int p);
	void Update(float elapsedTime);
private:
	int NameFile(int i);
	std::string _filename;
};

class ScoreN :
	public VisibleGameObject
{
public:
	ScoreN();
	virtual ~ScoreN();
	void Update(float elapsedTime);
private:
	int NameFile(int i);
	std::string _filename;
};