FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
ENV FORCE_UNSAFE_CONFIGURE=1

RUN apt-get update  \
    && apt-get install -y locales \
    && rm -rf /var/lib/apt/lists/* \
	&& localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8
ENV LANG en_US.utf8

RUN apt-get update; \
    apt-get install -y --no-install-recommends \
        acpica-tools \
	    bc bison build-essential \
        cmake curl cpio \
        device-tree-compiler \
        flex file \
        git \
        libglib2.0-dev libpixman-1-dev libssl-dev \
        ninja-build \
        openssl openssh-client \
        python3-cryptography python3-pip python3-pyelftools python3-venv \
        rsync \
        unzip \
        wget \
        xz-utils; \
    apt-get clean; \
    rm -rf /var/lib/apt/lists/*; \
    curl https://storage.googleapis.com/git-repo-downloads/repo > /usr/local/bin/repo; \
    chmod +x /usr/local/bin/repo; \
    git config --global user.email "atlas@atlassians.com"; \
    git config --global user.name "ATLAS"; \
    git config --global --add safe.directory '*'
# TODO: get toolchains here too
