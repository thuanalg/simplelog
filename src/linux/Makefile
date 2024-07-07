target=libsimplelog.so
debugFlag=-g -fPIC -shared 
releaseFlag=-fPIC -shared
LIBS+=-lpthread
src=../simplelog.c ../simplelog.h ../simplelog_config.h

debug:
	gcc ${debugFlag} -o ${target} ${src} ${LIBS}
	gcc -g -o simpplelog_sample  ../main.c  -L./ -lsimplelog ${LIBS} 

release:
	gcc ${releaseFlag} -o ${target} ${src} ${LIBS}
	gcc -o simpplelog_sample  ../main.c  -L./ -lsimplelog ${LIBS} 

clean:
	rm -rf ${target} simpplelog_sample
