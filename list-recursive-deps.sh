#!/bin/bash
# List library dependencies recursively.

# A function to recursively list dependencies
list_deps() {
    local file=$1
    # Avoid infinite loops for circular dependencies
    if [[ ! -z "${visited["$file"]}" ]]; then
        return
    fi
    visited["$file"]=1

    # Use ldd to list dependencies, filter out unwanted lines, and parse output
    local deps=$(ldd "$file" | egrep -o '/[^ ]+' | sort -u)
    for dep in $deps; do
        if [ -f "$dep" ]; then
            echo "$dep"
            # Recursively list dependencies of this dependency
            list_deps "$dep"
        fi
    done
}

# Main body of the script
if [ $# -eq 0 ]; then
    echo "Usage: $0 <executable-or-library>"
    exit 1
fi

declare -A visited

list_deps "$1"

