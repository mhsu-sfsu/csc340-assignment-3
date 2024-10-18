CXX = g++
CXXFLAGS = -std=c++11

PROG = InstagramMain.cpp Instagram340.cpp User.cpp Post.cpp Story.cpp Reel.cpp
OBJS = ${PROG:.cpp=.o}
HEADERS = myLibrary.h testing.h

MAIN = main

${MAIN}:${OBJS}
	${CXX} -o ${MAIN} ${OBJS}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} ${MAIN} *.o *~.