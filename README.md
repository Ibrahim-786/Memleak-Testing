COMPILATION STEPS

export TOP=$(pwd)
export QNX_HOST=$TOP/toolchains/qnx_toolchain/host/linux/x86_64
export QNX_TARGET=$TOP/toolchains/qnx_toolchain/target/qnx7


Create shared .SO library
#qcc -Vgcc_ntoaarch64le  -c -o library.o library.c

#qcc -Vgcc_ntoaarch64le -shared -o libfoo.so library.o

create binary 
#qcc  -Vgcc_ntoaarch64le  -L/home/qabuilder/workspace/memleak/test/my_lib/ -Wall -o memleak  memleak.c  -lfoo

copy libfoo.so and memleak binary to target



Usage:
                             
          -d                          directly_lost()
          -i                          indirectly_lost()
          -p                          indirectly_lost()# Memleak-Testing
