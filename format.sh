#!/usr/bin/env bash
git ls-files --exclude-standard | grep -E '\.(cpp|hpp|h|c|cc|cxx|hxx|ixx)$' | xargs clang-format -i -style=file
