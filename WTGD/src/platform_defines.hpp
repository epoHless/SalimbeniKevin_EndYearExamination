#pragma once
namespace WTGD
{


#ifdef DLL_EXPORT
#define WTGD_API __declspec(dllexport)
#else
#define WTGD_API __declspec(dllimport)
#endif

}
