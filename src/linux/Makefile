target=libsimplelog.so
debugFlag=-g -fPIC -shared 
releaseFlag=-fPIC -shared
LIBS+=-lpthread
src=../simplelog.c ../simplelog.h ../simplelog_config.h
INC=-I../

debug:
	gcc ${debugFlag} -o ${target} ${src} ${LIBS}
	gcc -g -o simpplelog_sample  ../c_test/main.c ${src} ${LIBS} ${INC}
	g++ -g -o simpplelog_cpp_sample  ../cpp_test/main.cpp ${LIBS} ${INC} -L./ -lsimplelog

release:
	gcc ${releaseFlag} -o ${target} ${src} ${LIBS}
	gcc -o simpplelog_sample  ../c_test/main.c ${src} ${LIBS} ${INC}
	g++ -o simpplelog_cpp_sample  ../cpp_test/main.cpp ${src} ${LIBS} ${INC} -L./ -lsimplelog

clean:
	rm -rf ${target} simpplelog_sample simpplelog_cpp_sample
