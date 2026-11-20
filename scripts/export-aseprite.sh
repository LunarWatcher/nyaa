#!/usr/bin/bash

git_root=$(git rev-parse --show-toplevel)

cd "${git_root}/assets"
for file in **/*.aseprite; do
    name="${file%.*}"
    if ! aseprite --list-slices --sheet ${name}.png --data ${name}.json --format json-array -b ${name}.aseprite
    then
        exit 1
    fi
done

