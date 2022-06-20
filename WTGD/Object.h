#ifndef OBJECT_H
#define OBJECT_H

#ifdef DLL_EXPORT
#define OBJECT_API __declspec(dllexport)
#else
#define OBJECT_API __declspec(dllimport)
#endif

class OBJECT_API Object
{
};

#endif OBJECT_H

