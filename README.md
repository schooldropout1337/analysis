``
clang -fsanitize=address -fno-omit-frame-pointer -o sandbox-asan sandbox.c
``

``
./sandbox-asan
``

![Sandbox ASAN](https://raw.githubusercontent.com/schooldropout1337/analysis/main/sandbox-asan.jpg)

``
clang -g -o sandbox sandbox.c
``

``
./sandbox
``
