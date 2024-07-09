#include "simplelog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef UNIX_LINUX
	#include <Windows.h>
	DWORD WINAPI win32_thread_routine(LPVOID lpParam);
#else
#	include <unistd.h>
	#include <pthread.h>
	void *win32_thread_routine(void* lpParam);
#endif // !UNIX_LINUX


void dotest();

int number = 2;
int main(int argc, char* argv[]) {
	int n = 0, ret = 0, i = 0;
	if (argc > 1) {
		n = sscanf(argv[1], "%d", &number);
	}
	spl_console_log("Main thread.\n");
	char pathcfg[1024];
	char* path = "simplelog.cfg";
	char nowfmt[64];
	snprintf(pathcfg, 1024, path);
	n = strlen(pathcfg);
	for (i = 0; i < n; ++i) {
		if (pathcfg[i] == '\\') {
			pathcfg[i] = '/';
		}
	}
	ret = spl_init_log(pathcfg);
	spl_fmt_now(nowfmt, 64);
	spllog(SPL_LOG_INFO, "%s", "\n<<-->>\n");
	n = 0;
	dotest();
	while (1) {
		FILE* fp = 0;
#ifndef UNIX_LINUX
		Sleep(10 * 1000);
#else
		sleep(10);
#endif
		
		spllog(SPL_LOG_DEBUG, "%s", "\n<<-->>\n");
		fp = fopen("trigger.txt", "r");
		if (fp) {
			fclose(fp);
			break;
		}

	}
	spllog(SPL_LOG_INFO, "%s", "\n<<--->>\n");
	spl_console_log("--Main close--\n");
	spl_finish_log();
	return EXIT_SUCCESS;
}
void dotest() {
	int i = 0;
#ifndef UNIX_LINUX

	DWORD dwThreadId = 0;
	HANDLE hThread = 0;
	for (i = 0; i < number; ++i) {
		hThread = CreateThread(NULL, 0, win32_thread_routine, 0, 0, &dwThreadId);
	}
#else
	pthread_t idd = 0;
	for (i = 0; i < number; ++i) {
		int err = pthread_create(&idd, 0, win32_thread_routine, 0);
	}
#endif
}

#ifndef UNIX_LINUX
DWORD WINAPI win32_thread_routine(LPVOID lpParam) {
	while (1) {
		spllog(SPL_LOG_INFO, "test log: %llu", (LLU)time(0));
		Sleep(1 * 1000);
	}
	return 0;
}
#else

void* win32_thread_routine(void* lpParam) {
	while (1) {
		spllog(SPL_LOG_INFO, "test log: %llu", (LLU)time(0));
		sleep(1);
	}
	return 0;
}
#endif // !UNIX_LINUX

