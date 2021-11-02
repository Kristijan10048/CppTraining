#pragma once
#include<iostream>

template<typename T> void MyTemplateTest(T value);


/// <summary>
/// Dummy TT function
/// </summary>
void TT();

/// <summary>
/// 
/// </summary>
/// <typeparam name="Type"></typeparam>
template <class Type> class CAppMyTmpl
{

public:
	/// <summary>
	/// 
	/// </summary>
	CAppMyTmpl();

	
	~CAppMyTmpl();

	/// <summary>
	/// 
	/// </summary>
	std::string toString();
};