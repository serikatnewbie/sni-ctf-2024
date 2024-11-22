FROM ubuntu:22.04

RUN apt-get update && apt-get install -y socat
RUN useradd -UM perpisahan

COPY perpisahan /home/perpisahan/perpisahan
COPY flag.txt /home/perpisahan/flag.txt
COPY run.sh /home/perpisahan/run.sh
COPY ld-linux-x86-64.so.2 /home/perpisahan/ld-linux-x86-64.so.2
COPY libc.so.6 /home/perpisahan/libc.so.6
RUN chown perpisahan:perpisahan /home/perpisahan/flag.txt && chmod 644 /home/perpisahan/flag.txt
USER perpisahan

WORKDIR /home/perpisahan
EXPOSE 7294
CMD /home/perpisahan/run.sh
