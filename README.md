# Use After Free (UAF)

Use After Free (UAF) is a common memory corruption vulnerability where a program accesses memory that has been freed, potentially leading to unpredictable behavior and security exploits. In the context of exploiting a vulnerable sandbox using GDB, UAF occurs when the sandbox improperly references memory after it has been deallocated. Exploiting this vulnerability allows an attacker to manipulate the program's behavior, potentially executing arbitrary code or gaining unauthorized access to sensitive information.

Using GDB (GNU Debugger), an essential tool for software debugging and vulnerability analysis, attackers can identify and exploit UAF vulnerabilities. GDB provides features to examine program memory, set breakpoints, and step through code execution, making it an invaluable tool for understanding and exploiting memory-related vulnerabilities.

To exploit a UAF vulnerability in a sandbox using GDB, attackers typically follow a series of steps. First, they identify the UAF vulnerability by analyzing the program's source code or behavior. Then, they use GDB to set breakpoints at critical points, such as memory allocation and deallocation functions, and observe the program's memory state. By triggering the UAF condition and manipulating memory contents, attackers can gain control over program execution, leading to privilege escalation or remote code execution.

In summary, UAF vulnerabilities pose significant security risks, and using GDB to exploit them in vulnerable sandboxes demonstrates the importance of thorough vulnerability analysis and secure software development practices.

# Step to Reproduce

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

![Sandbox](https://raw.githubusercontent.com/schooldropout1337/analysis/main/sandbox-0.jpg)


``
gdb -x exploit.gdb sandbox
``

![Sandbox Exploit](https://raw.githubusercontent.com/schooldropout1337/analysis/main/sandbox-exploit-gdb.jpg)

# View All Images for Further Understandings 🥚 \0
