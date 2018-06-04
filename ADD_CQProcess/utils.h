#pragma once

#ifndef UTILS
#define UTILS

#include <chrono>

using namespace std;
using namespace chrono;

// only for the default name of query
int querySize = 0;

//get the current time, millisecond.
long long getTime() {
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	return ms.count();
}


#endif // !UTILS