# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "F:/CLion 2022.2.4/Progi/OOP/Lab3_OOP/cmake-build-debug/_deps/googletest-src"
  "F:/CLion 2022.2.4/Progi/OOP/Lab3_OOP/cmake-build-debug/_deps/googletest-build"
  "F:/CLion 2022.2.4/Progi/OOP/Lab3_OOP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "F:/CLion 2022.2.4/Progi/OOP/Lab3_OOP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "F:/CLion 2022.2.4/Progi/OOP/Lab3_OOP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "F:/CLion 2022.2.4/Progi/OOP/Lab3_OOP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "F:/CLion 2022.2.4/Progi/OOP/Lab3_OOP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "F:/CLion 2022.2.4/Progi/OOP/Lab3_OOP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
