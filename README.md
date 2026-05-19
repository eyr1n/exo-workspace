# exo-workspace

## Setup

```bash
git submodule update --init --recursive
```

## Create Docker container (optional)

```bash
docker build -t exo-workspace . 
docker run --rm -it \
    -e HOST_UID="$(id -u)" \
    -e HOST_GID="$(id -g)" \
    -v "$(pwd):/workspace" exo-workspace
```

## Build

```bash
uv sync
uv run cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
uv run cmake --build build
```

## Test

```bash
uv run pytest
uv run ctest --test-dir build
```

## Benchmark

```bash
./build/benchmark/avx2_matmul_bench
```
