#include <iostream>
#include <fstream>
#include <future>         // std::async, std::future
#include <thread>
#include <chrono>
#include <string>
#include "../loguru.hpp"
#include "MyTemplates.h"

/// <summary>
/// Timer class
/// </summary>
class MyTimer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock>  m_startTime;
public:
	/// <summary>
	/// Defualt constructor
	/// </summary>
	MyTimer()
	{
		m_startTime = std::chrono::high_resolution_clock::now();
	}

	~MyTimer()
	{
		auto stopTime = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast< std::chrono::microseconds >(m_startTime).time_since_epoch().count();
		auto end = std::chrono::time_point_cast< std::chrono::microseconds >(stopTime).time_since_epoch().count();
		
		auto duration =  end - start;
		auto microS = duration * .0001;
		std::cout << duration << "us" << "(" << microS << ")" << std::endl;
	}
};

/// <summary>
/// Runner 1 funct
/// </summary>
void Runner1()
{
	LOG_F(INFO, "Running runer 1" );
	std::this_thread::sleep_for(std::chrono::seconds(5));
	LOG_F(INFO, "Done with runer 1" );
}

/// <summary>
/// Runner 2 funct
/// </summary>
void Runner2()
{
	LOG_F(INFO, "Running runer 2" );
	std::this_thread::sleep_for(std::chrono::seconds(5));
	LOG_F(INFO, "Done with runer 2");
}

/// <summary>
/// Writes 680x 640 range data in to a file
/// </summary>
void WriteFrameToFileDemo()
{
	LOG_F(INFO, "Running Writing to a file" );
	std::ofstream log_frame("log_frame.txt", std::ios_base::out);

	for( int j = 0; j < 640; ++j )
	{
		for( int i = 0; i < 480; ++i )
		{
			log_frame << std::to_string(0.00002) << " " << std::to_string(0.00002) << " " << std::to_string(0.00002) << " " << std::to_string(0.00002) << "\n";
			
		}
	}

	//clean up
	log_frame.close();
	LOG_F(INFO, "Done with write to a file" );
}

int main(int argc, char* argv[])
{
	loguru::init(argc, argv, loguru::Options() );	

	{
		LOG_F(INFO, "Running in sync" );
		MyTimer timer;
		Runner1();
		Runner2();
	}

	{
		LOG_F(INFO, "Running async");
		MyTimer timer;
		auto res1 = std::async(std::launch::async, Runner1);
		auto res2 = std::async(std::launch::async, Runner2);
	}

	{
		LOG_F(INFO, "Running async - write to a file");
		MyTimer timer;
		auto res3 = std::async(std::launch::async, WriteFrameToFileDemo);
		auto res1 = std::async(std::launch::async, Runner1);
		auto res2 = std::async(std::launch::async, Runner2);		
	}

	{
		LOG_F(INFO, "Running templates function");
		/*MyTemplateTest<int>(23);
		MyTemplateTest("Test");
		MyTemplateTest('')*/
		MyTemplateTest(23);
	}
}