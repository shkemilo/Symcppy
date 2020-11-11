#include"Communication/Module.h"



class Solver:public Module
{
public:
	enum EFunction
	{
		Zeroes=0,
		ValueAt,
		Invalid,
		Count
	};
	Solver(const std::string& name);
	/*
	EStatus GetZeroes(std::vector<double>& zeroes);
	EStatus GetValueAt(const std::string& function,const double& point,double& value);
	*/
};
