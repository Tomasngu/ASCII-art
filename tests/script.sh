green="\e[92m"
red="\e[91m"
reset="\e[0m"

for file in ./debug/*; do
    if ./"$file" ; then
        echo -e "$green""$file" "OK" "$reset"
    else
        echo -e "$red""$file" "FAIL" "$reset"
    fi
done;
