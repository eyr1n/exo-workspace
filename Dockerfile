FROM ubuntu:24.04

ENV UV_LINK_MODE=copy
ENV UV_PROJECT_ENVIRONMENT=/home/ubuntu/venv

COPY --from=ghcr.io/astral-sh/uv:0.11.15 /uv /uvx /bin/
COPY entrypoint.sh /entrypoint.sh

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive \
        apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        git \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
ENTRYPOINT ["/entrypoint.sh"]
CMD ["/bin/bash"]
