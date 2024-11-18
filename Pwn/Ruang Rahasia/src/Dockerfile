FROM ubuntu:22.04

RUN apt-get update && apt-get install -y socat
RUN useradd -UM ruang_rahasia

COPY ruang_rahasia /home/ruang_rahasia/ruang_rahasia
COPY flag-26c03116c571f27a1ddbfb9.txt /home/ruang_rahasia/flag-26c03116c571f27a1ddbfb9.txt
COPY run.sh /home/ruang_rahasia/run.sh
RUN chown ruang_rahasia:ruang_rahasia /home/ruang_rahasia/flag-26c03116c571f27a1ddbfb9.txt && chmod 644 /home/ruang_rahasia/flag-26c03116c571f27a1ddbfb9.txt
USER ruang_rahasia

WORKDIR /home/ruang_rahasia
EXPOSE 8018
CMD /home/ruang_rahasia/run.sh
