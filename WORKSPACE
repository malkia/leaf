# This is a bazel workspace file!

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "8a8853fd755496288995a603ce9aa2685709cd39",
    remote = "https://github.com/nelhage/rules_boost",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

new_http_archive(
    name = "lua",
    build_file = "lua.BUILD.bazel",
    sha256 = "2640fc56a795f29d28ef15e13c34a47e223960b0240e8cb0a82d9b0738695333",
    strip_prefix = "lua-5.1.5/src",
    urls = [
        "https://mirror.bazel.build/www.lua.org/ftp/lua-5.1.5.tar.gz",
        "https://www.lua.org/ftp/lua-5.1.5.tar.gz",
    ],
)


##


# Change master to the git tag you want.
http_archive(
    name = "com_grail_bazel_toolchain",
    strip_prefix = "bazel-toolchain-master",
    urls = ["https://github.com/grailbio/bazel-toolchain/archive/master.tar.gz"],
)

load("@com_grail_bazel_toolchain//toolchain:configure.bzl", "llvm_toolchain")

# bazel build --crosstool_top=@llvm_toolchain//:toolchain ...

llvm_toolchain(
    name = "llvm_toolchain",
    llvm_version = "6.0.0",
)

