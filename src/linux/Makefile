target=libsimplelog.so
debugFlag=-g -fPIC -shared -o
releaseFlag=-fPIC -shared -o 
src=../simplelog.c ../simplelog.h ../simplelog_config.h

debug:
	echo "debug"
	gcc ${debugFlag} ${target} ${src} 

release:
	echo "release"
	gcc ${releaseFlag} ${target} ${src} 

clean:
	rm -rf ${target}
