/**
*	For compiling on Linux systems:
*	gcc -c -fPIC SimpleMath.h SimpleMath.c		-> Compiles to position independent code
*	gcc -shared -o lib<NAME>.so SimpleMath.o	-> Creates the shared object file itself. Nameing convention is lib<NAME>.so, this is important for linking
*	gcc -o main Main.c -l<NAME> -L <location>	-> Main depends on the library we wrote, specify the libraries name -l<NAME> and it's location
*/

#ifndef _DLL_SIMPLEMATH_H_
#define _DLL_SIMPLEMATH_H_
#ifdef WIN32
#	ifdef DLL_EXPORT	//if exporting the dll use the __declspec(dllexport)
#		define DECLIDER __declspec(dllexport)
#	else				//else import the dll
#		define DECLIDER __declspec(dllimport)
#	endif
#else	//In linux all public symbols are exported by default
#	define DECLIDER 
#endif // WIN32


#ifdef __cplusplus		//if it is a cpp/hpp file then extern "C" will mark these definitions so the name does not get mangaled
//cpp mangels the names 
extern "C" {
#endif //__cplusplus


	DECLIDER int Add(int, int);
	DECLIDER int Sub(int, int);
	DECLIDER int Mult(int, int);


#ifdef __cplusplus
}
#endif //__cplusplus	-> extern "C" is needed 
#endif //_DLL_SIMPLEMATH_H	-> Make sure file is imported only once