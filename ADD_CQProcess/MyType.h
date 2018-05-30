#pragma once

#include <boost/shared_ptr.hpp>
#include "Event.h"

#ifndef EVENT_PTR
typedef boost::shared_ptr<Event> EventPtr;
#endif // !EVENT_PTR




using namespace std;
using namespace boost;