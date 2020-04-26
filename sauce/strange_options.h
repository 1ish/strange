#ifndef COM_ONEISH_STRANGE_OPTIONS_H
#define COM_ONEISH_STRANGE_OPTIONS_H

// options

namespace strange
{
	int64_t const STRANGE_RIVER_DEFAULT_READ_SIZE = 1024;
}

#ifdef _DEBUG
#define STRANGE_DEBUG 1
#define STRANGE_CHECK_STATIC_CASTS 1
#endif

#endif
