CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -w




SOURCES1 = stringEncrypt.cpp
HEADERS = 
OBJS1 = stringEncrypt.o 

make:${SOURCES1} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SOURCES1} -o encrypt

${OBJS}: ${SOURCES1}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean:
	rm encrypt 
