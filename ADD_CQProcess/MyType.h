#pragma once

#include <boost/shared_ptr.hpp>
#include "Event.h"

#ifndef EVENT_PTR
typedef boost::shared_ptr<Event> EventPtr;
#endif // !EVENT_PTR


#ifndef DEBUGGING
#define DEBUGGING
extern bool IS_DEBUGGING = true;
#endif // !DEBUGGING


using namespace std;
using namespace boost;