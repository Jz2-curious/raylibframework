#pragma once

#if DLLEXPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif