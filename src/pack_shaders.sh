#!/bin/bash
# find glsl shaders in current directory and export them as a C header removing comments and whitespace wherever possible

function process {
    prepr_lines="`echo "$2"|grep .|grep '#'|sed 's/.*/"&\\\\\\\n"/'`"
    no_comments="`echo "$2"|gcc -fpreprocessed -w -E -P -x c -w - 2> /dev/null`"
    no_spaces="`echo "$no_comments"|sed "s/^[ \t]*//"|sed 's/[[:space:]]\([^[:alnum:]]\)/\1/g'|sed 's/\([^[:alnum:]]\)[[:space:]]/\1/g'`"
    in_quotes="`echo "$no_spaces"|sed 's/.*/"&"/'`"
    printf "\n\nconst char*\n$3$4 =\n$prepr_lines\n$in_quotes;\n"
}

echo "/* This file was autogenerated. */"

for file in $(find . -type f -name "*.geom.glsl"); do
    process res "$(cat $file)" ${file:2:-10} '_gs_src'
done
for file in $(find . -type f -name "*.vert.glsl"); do
    process res "$(cat $file)" ${file:2:-10} '_vs_src'
done
for file in $(find . -type f -name "*.frag.glsl"); do
    process res "$(cat $file)" ${file:2:-10} '_fs_src'
done
