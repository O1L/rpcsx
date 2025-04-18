#!/bin/sh -ex

cd rpcs3/ || exit 1

git config --global --add safe.directory '*'

# Pull all the submodules except llvm and opencv
# shellcheck disable=SC2046
git submodule -q update --init $(awk '/path/ && !/llvm/ && !/opencv/ { print $3 }' .gitmodules)

if [ "$COMPILER" = "gcc" ]; then
    # These are set in the dockerfile
    export CC="${GCC_BINARY}"
    export CXX="${GXX_BINARY}"
    export LINKER=gold
else
    export CC="${CLANG_BINARY}"
    export CXX="${CLANGXX_BINARY}"
    export LINKER="${LLD_BINARY}"
fi
export CFLAGS="$CFLAGS -fuse-ld=${LINKER}"
export CXXFLAGS="$CXXFLAGS -fuse-ld=${LINKER}"

cmake -B build                                         \
    -DCMAKE_INSTALL_PREFIX=/usr                        \
    -DUSE_NATIVE_INSTRUCTIONS=OFF                      \
    -DUSE_PRECOMPILED_HEADERS=OFF                      \
    -DCMAKE_C_FLAGS="$CFLAGS"                          \
    -DCMAKE_CXX_FLAGS="$CFLAGS"                        \
    -DUSE_SYSTEM_CURL=ON                               \
    -DUSE_SDL=ON                                       \
    -DUSE_SYSTEM_SDL=ON                                \
    -DUSE_SYSTEM_FFMPEG=OFF                            \
    -DUSE_SYSTEM_OPENCV=ON                             \
    -DUSE_DISCORD_RPC=ON                               \
    -DOpenGL_GL_PREFERENCE=LEGACY                      \
    -DLLVM_DIR=/opt/llvm/lib/cmake/llvm                \
    -DSTATIC_LINK_LLVM=ON                              \
    -DWITH_RPCSX=off                                   \
    -DWITH_RPCS3=on                                    \
    -DWITH_RPCS3_QT_UI=on                              \
    -G Ninja

cmake --build build; build_status=$?;

shellcheck .ci/*.sh

# If it compiled succesfully let's deploy.
# Azure and Cirrus publish PRs as artifacts only.
{   [ "$CI_HAS_ARTIFACTS" = "true" ];
} && SHOULD_DEPLOY="true" || SHOULD_DEPLOY="false"

if [ "$build_status" -eq 0 ] && [ "$SHOULD_DEPLOY" = "true" ]; then
    .ci/deploy-linux.sh "aarch64"
fi
