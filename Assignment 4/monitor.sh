#!/bin/bash
echo "" >log.txt
for (( ; ; )); do
    for p in $(pgrep -u "$USER"); do
        count=$(pstree -p $p | grep -o '([0-9]\+)' | wc -l)
        if [[ $count -gt 6 ]]
        then
            date >>log.txt
            pstree -p $p >>log.txt
        fi
    done
    sleep 5
done