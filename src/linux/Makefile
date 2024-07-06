target=libsimplelog.so
debugFlag=-g -fPIC -shared 
releaseFlag=-fPIC -shared
src=../simplelog.c ../simplelog.h ../simplelog_config.h

debug:
	gcc ${debugFlag} -o ${target} ${src} 

release:
	gcc ${releaseFlag} -o ${target} ${src} 

clean:
	rm -rf ${target}
