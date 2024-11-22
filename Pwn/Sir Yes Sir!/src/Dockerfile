FROM ubuntu:jammy

EXPOSE 8000

RUN apt update 
RUN apt-get install -y socat qemu qemu-user-static

RUN mkdir /home/pwn
WORKDIR /home/pwn

COPY flag.txt ./flag.txt
COPY siryessir ./siryessir
COPY ld-linux.so.3 ./ld-linux.so.3
COPY libc.so.6 ./libc.so.6

RUN chmod -R 755 .
RUN chmod 700 /usr/bin/* /bin/* /tmp /dev/shm
RUN chmod 755 /usr/bin/env /bin/dash /bin/bash /bin/sh /bin/cat /usr/bin/id /bin/ls
RUN chmod +x ./siryessir

CMD socat TCP-LISTEN:8000,reuseaddr,fork EXEC:/home/pwn/siryessir,su=nobody
