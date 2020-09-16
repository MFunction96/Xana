//
// Created by MFunction on 09/16/2020.
//

#ifndef _XSHELL_H_
#define _XSHELL_H_

#include "Xana/Xana.hpp"

#if defined(__GNUC__)
#define EXPORT extern "C" __attribute__((visibility("default")))
#elif defined(_MSC_VER)
#define EXPORT extern "C" __declspec(dllexport)
#endif

#endif //_XSHELL_H_
