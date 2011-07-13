unix {
	# treat warnings as errors
	QMAKE_CXXFLAGS += -Werror -std=c++0x
	# for debugging an profiling
	QMAKE_CXXFLAGS_DEBUG += -pg
	QMAKE_LFLAGS_DEBUG += -pg
	
	# optimizations
	QMAKE_CXXFLAGS_RELEASE += -O3
}
