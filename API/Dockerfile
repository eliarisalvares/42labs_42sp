#getting base image
FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

COPY . .API/
COPY ./entrypoint.sh /

RUN apt-get clean
RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y libgnutls28-dev
RUN apt-get install -y libsystemd-dev
RUN apt-get install -y libcurl4-gnutls-dev
RUN apt-get install -y libcurl4-nss-dev
RUN apt-get install -y libcurl4-openssl-dev
RUN apt-get install -y libulfius-dev
RUN apt-get install -y libmicrohttpd-dev
RUN apt-get install -y git-all
RUN apt-get install -y cmake

ENTRYPOINT ["bash", "entrypoint.sh"]
