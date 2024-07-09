target=libsimplelog.so
debugFlag=-g -fPIC -shared 
releaseFlag=-fPIC -shared
LIBS+=-lpthread
src=../simplelog.c ../simplelog.h ../simplelog_config.h

debug:
	gcc ${debugFlag} -o ${target} ${src} ${LIBS}
	gcc -g -o simpplelog_sample  ../c_test/main.c ${src} ${LIBS} 

release:
	gcc ${releaseFlag} -o ${target} ${src} ${LIBS}
	gcc -o simpplelog_sample  ../c_test/main.c ${src} ${LIBS} 

clean:
	rm -rf ${target} simpplelog_sample
