all:
	gcc -o chall chall.c -fstack-protector-strong -fPIE -pie -Wl,-z,relro,-z,now -Wl,-z,noexecstack -D_FORTIFY_SOURCE=2
