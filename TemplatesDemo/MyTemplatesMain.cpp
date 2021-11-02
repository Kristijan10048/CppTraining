#include<typeinfo>
#include "..\Cpp11_featuers\loguru.hpp"
#include "MyTemplates.h"
#include "Tester.h"


int main(int argc, char* argv[])
{
	loguru::init(argc, argv, loguru::Options());
	
	{	
		LOG_F(INFO, "Starting templates demo");

		//a function from Tester.cpp
		LOG_F(INFO, Tester().data());

		//auto res = Tester();

		//LOG_F(INFO, res);
		//a function from MyTemplates 
		
		TT();

		///CAppMyTmpl<double> tmp;
		//MyTemplateTest<std::string>("Test");
	}
	return 0;
}