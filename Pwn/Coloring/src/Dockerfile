FROM ubuntu:22.04 AS challenge

RUN apt-get update && \
    apt-get install -y --no-install-recommends socat && \
    rm -rf /var/cache/apt/archives /var/lib/apt/lists

RUN groupadd -r ctf && useradd -r -g ctf ctf

COPY flag.txt /home/ctf/flag.txt
COPY chall /home/ctf/chall

RUN chmod 644 /home/ctf/flag.txt
RUN chmod 755 /home/ctf/chall
RUN chown -R root:ctf /home/ctf

WORKDIR /home/ctf
USER ctf
CMD ["socat", "TCP-LISTEN:5000,reuseaddr,fork", "EXEC:./chall,stderr,pty,cfmakeraw,echo=0"]
