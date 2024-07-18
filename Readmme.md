# simplelog

## 0. Preface

[**Thanks a lot to:**](https://www.bing.com/search?form=SKPBOT&q=Thanks%20a%20lot%20to%3A)

1. My family, friends.
2. [**W. Richard Steven**](https://www.bing.com/search?form=SKPBOT&q=W.%20Richard%20Steven) - Unix Network Programming - Volume I, II. The books bring C/C++ programming career to me.
3. My colleagues: Bùi Khánh Duy, Nguyễn Công Đức, Lê Duy Cương, ...

[**Purpose:**](https://www.bing.com/search?form=SKPBOT&q=Purpose%3A)

1. A C/C++ log is to support multithread.
2. A pattern of designation of multi-thread, signaling.
3. Without using third party except Posix APIs, Win32 APIs.
4. Portable: Windows, Unix-Like (Linux, Mac, Solaris, Android, iOS, ...)
5. Focus on simplicity.
6. An sample following [**W. Richard Steven**](https://www.bing.com/search?form=SKPBOT&q=W.%20Richard%20Steven) Unix Network Programming - Volume II, Part 3 - Synchronization, Chapter 7, 8, 9, 10, 11.
7. Fast and small.

## 1. Configuration and build (did test on x86_64 as below, still in progress)

| OS                | Tool/SDK                 | Steps                                                                                                                                                                                                 | Prerequisite                                                                 |
|-------------------|--------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|
| Windows 10, 32 bits | Microsoft Visual Studio 2022 | 1. Come to [**src**](https://www.bing.com/search?form=SKPBOT&q=src) folder.<br>2. Comment the macro [**UNIX_LINUX**](https://www.bing.com/search?form=SKPBOT&q=UNIX_LINUX) in [**simplelog_config.h**](https://www.bing.com/search?form=SKPBOT&q=simplelog_config.h)<br>3. Run: `cmake -G "Visual Studio 17 2022" -A win32 -B ../build32`.<br>"../build32" is an output folder.<br>4. Move to the output folder "../build32" to build and run test.<br>5. Copy [**src/simpleplog.cfg**](https://www.bing.com/search?form=SKPBOT&q=src%2Fsimpleplog.cfg) to ../build32 | 1. [**cmake**](https://www.bing.com/search?form=SKPBOT&q=cmake), however, you can add the files (from [**src**](https://www.bing.com/search?form=SKPBOT&q=src)) manually/directly.<br>2. Visual Studio 2022 (Community version or any.) |
| Windows 10, 64 bits | Microsoft Visual Studio 2022 | 1. Come to [**src**](https://www.bing.com/search?form=SKPBOT&q=src) folder.<br>2. Comment the macro [**UNIX_LINUX**](https://www.bing.com/search?form=SKPBOT&q=UNIX_LINUX) in [**simplelog_config.h**](https://www.bing.com/search?form=SKPBOT&q=simplelog_config.h)<br>3. Run: `cmake -G "Visual Studio 17 2022" -B ../build64`.<br>"../build64" is an output folder.<br>4. Move to the output folder "../build64" to build and run test.<br>5. Copy [**src/simpleplog.cfg**](https://www.bing.com/search?form=SKPBOT&q=src%2Fsimpleplog.cfg) to ../build64 | 1. [**cmake**](https://www.bing.com/search?form=SKPBOT&q=cmake), however, you can add the files (from [**src**](https://www.bing.com/search?form=SKPBOT&q=src)) manually/directly.<br>2. Visual Studio 2022 (Community version or any.) |
| Linux, 64 bits     | gcc/g++                  | 1. Come to [**src**](https://www.bing.com/search?form=SKPBOT&q=src), change the file.<br>2. Come to [**src/linux**](https://www.bing.com/search?form=SKPBOT&q=src%2Flinux) folder.<br>3. Run: `make`.<br>4. Copy [**src/simpleplog.cfg**](https://www.bing.com/search?form=SKPBOT&q=src%2Fsimpleplog.cfg) to [**src/linux**](https://www.bing.com/search?form=SKPBOT&q=src%2Flinux).                                                      | 1. gcc/g++.<br>2. POSIX, POSIX thread.                                        |

## 2. Run

| OS      | Step                                                                                       | Note                                                                                          |
|---------|--------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|
| Windows | Come to the output folder.<br>Run `simple_c_example.exe 2000`<br>Or run `simple_cpp_example.exe 2000` | Output 2000 is number of threads.<br>Let's assess performance of the library/sample for yourself. |
| Linux   | Come to the output folder.<br>Run `./simpplelog_sample 2000`<br>Run `./simpplelog_cpp_sample 2000`   | Output 2000 is number of threads.<br>With `simpplelog_cpp_sample`, you have to export `LD_LIBRARY_PATH=$LD_LIBRARY_PATH ./`<br>Because `simpplelog_cpp_sample` depends on `libsimplelog.so`.<br>Let's assess performance of the library/sample for yourself. |

## 3. APIs manual

| Index | Name             | Description                                                                 | Thread-safe |
|-------|------------------|-----------------------------------------------------------------------------|-------------|
| 1     | `spl_init_log`   | The path to configuring file.                                               | Yes         |
| 2     | `spllog`         | Level is `SPL_LOG_DEBUG`, `SPL_LOG_INFO`, `SPL_LOG_WARNING`, `SPL_LOG_ERROR`, `SPL_LOG_FATAL` | Yes         |
| 3     | `spl_finish_log` | Finish log.                                                                 | Yes         |