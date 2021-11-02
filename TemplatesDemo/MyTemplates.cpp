#include "MyTemplates.h"

template<typename T> void MyTemplateTest(T value)
{
	std::cout << "The value is : " << value << "and the type is " << typeid(T);
}

void TT()
{
	std::cout << "TT" << std::endl;
}

#pragma region CAppMyTmpl - Implementation

/// <summary>
/// Default constructor
/// </summary>
CAppMyTmpl<class Type>::CAppMyTmpl()
{
	std::cout << "constructor CAppMyTmpl" << std::endl;
}

/// <summary>
/// Default destrouctor
/// </summary>
CAppMyTmpl<class Type>::~CAppMyTmpl()
{
	std::cout << "Destr CAppMyTmpl" << std::endl;
}

/// <summary>
/// 
/// </summary>
std::string CAppMyTmpl<class Type>::toString()
{
	return "CAppMyTmpl <>";// << typeid(Type) << std::endl;
}
#pragma endregion