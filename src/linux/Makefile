target=libsimplelog.so
debugFlag=-g -fPIC -Wall -shared 
releaseFlag=-fPIC -Wall -shared
LIBS+=-lpthread
src=../simplelog.c ../simplelog.h ../simplelog_config.h
INC=-I../

debug:
	gcc ${debugFlag} -o ${target} ${src} ${LIBS}
	gcc -g -o simpplelog_sample  ../c_test/main.c ${src} ${LIBS} ${INC}
	g++ -g -o simpplelog_cpp_sample  ../cpp_test/main.cpp ${LIBS} ${INC} -L./ -lsimplelog
	g++ -g -o simpplelog_cpp_direct_sample  ../cpp_test/main.cpp ${src} ${LIBS} ${INC}

release:
	gcc ${releaseFlag} -o ${target} ${src} ${LIBS}
	gcc -o simpplelog_sample  ../c_test/main.c ${src} ${LIBS} ${INC}
	g++ -o simpplelog_cpp_sample  ../cpp_test/main.cpp ${LIBS} ${INC} -L./ -lsimplelog
	g++ -o simpplelog_cpp_direct_sample  ../cpp_test/main.cpp ${src} ${LIBS} ${INC}

clean:
	rm -rf ${target} simpplelog_sample simpplelog_cpp_sample
