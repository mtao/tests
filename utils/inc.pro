debug {
    DEBUG_OR_RELEASE = debug
    DEFINES += _DEBUG
}
release {
    DEBUG_OR_RELEASE = release
}
unix {
	# treat warnings as errors
	QMAKE_CXXFLAGS += -Werror -std=c++0x
	# for debugging an profiling
	QMAKE_CXXFLAGS_DEBUG += -pg
	QMAKE_LFLAGS_DEBUG += -pg
	
	# optimizations
	QMAKE_CXXFLAGS_RELEASE += -O3

    # lib stuff
    STATIC_LIB_EXTENSION = a
    SHARED_LIB_EXTENSION = so
}

message(building $$DEBUG_OR_RELEASE build)
