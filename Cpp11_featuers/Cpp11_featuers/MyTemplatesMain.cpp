#include<iostream>
#include<typeinfo>
#include "..\loguru.hpp"
#include"MyTemplates.h"




int main(int argc, char* argv[])
{
	loguru::init(argc, argv, loguru::Options());
	
	{
		LOG_F(INFO, "Starting templates demo");
		//MyTemplateTest(23);
	}
	return 0;
}