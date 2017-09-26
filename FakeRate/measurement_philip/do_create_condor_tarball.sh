#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Help
usage()
{
  echo "ERROR - Usage:"
  echo
  echo "      sh $(basename $0) OPTIONSTRINGS ..."
  echo
  echo "Options with arguments:"
  echo "  -h    Help                   (Display this message)"
  echo "  -o    package output path    (e.g. -o /path/to/condor.tgz)"
  echo
  exit
}

# Command-line opts
while getopts ":o:h" OPTION; do
  case $OPTION in
    o) PACKAGEOUTPUT=${OPTARG};;
    h) usage;;
    :) usage;;
  esac
done

if [ -z ${PACKAGEOUTPUT} ]; then usage; fi

# to shift away the parsed options
shift $(($OPTIND - 1))

if [ -e ${PACKAGEOUTPUT} ]; then

    echo "checking whether existing package content is up to date."

    LATESTFILE=$(find $@ ${PACKAGEOUTPUT} -type f -printf '%T@ %p\n' | sort -n | tail -1 | cut -f2- -d" ")

    if [ "x${LATESTFILE}" == x${PACKAGEOUTPUT} ]; then
        echo "All files up to date in the condor_package.tgz"
        exit
    fi

fi

LOGOINDEX=$((1 + RANDOM % 2))

if [ "x${LOGOINDEX}" == x1 ]; then
    echo ""
    echo "       Assemble for Condor!      "
    echo ""
    echo "            ▄▄▄▄▄▄▄▄▄            "
    echo "         ▄█████████████▄         "
    echo " █████  █████████████████  █████ "
    echo " ▐████▌ ▀███▄       ▄███▀ ▐████▌ "
    echo "  █████▄  ▀███▄   ▄███▀  ▄█████  "
    echo "  ▐██▀███▄  ▀███▄███▀  ▄███▀██▌  "
    echo "   ███▄▀███▄  ▀███▀  ▄███▀▄███   "
    echo "   ▐█▄▀█▄▀███ ▄ ▀ ▄ ███▀▄█▀▄█▌   "
    echo "    ███▄▀█▄██ ██▄██ ██▄█▀▄███    "
    echo "     ▀███▄▀██ █████ ██▀▄███▀     "
    echo "    █▄ ▀█████ █████ █████▀ ▄█    "
    echo "    ███        ███        ███    "
    echo "    ███▄    ▄█ ███ █▄    ▄███    "
    echo "    █████ ▄███ ███ ███▄ █████    "
    echo "    █████ ████ ███ ████ █████    "
    echo "    █████ ████ ███ ████ █████    "
    echo "    █████ ████ ███ ████ █████    "
    echo "    █████ ████▄▄▄▄▄████ █████    "
    echo "     ▀███ █████████████ ███▀     "
    echo "       ▀█ ███ ▄▄▄▄▄ ███ █▀       "
    echo "          ▀█▌▐█████▌▐█▀          "
    echo "             ███████             "
    echo ""
    echo ""
elif [ "x${LOGOINDEX}" == x2 ]; then
    echo ""
    echo "          Assemble for Condor!       "
    echo "  █                                █ "
    echo "  ██         █          █         ██ "
    echo "  ▐██        ██        ██        ██▌ "
    echo "   ████      ███      ███       ███  "
    echo "   ▐█████     ██████████     █████▌  "
    echo "    █████████ ██████████ █████████   "
    echo "    ████▀████ ████  ████ ████▀████   "
    echo "    ████▄     ████  ████     ▄████   "
    echo "    ██████████ ████████ ██████████   "
    echo "    ▐████▄     ████████     ▄████    "
    echo "     █████████  ██████  █████████    "
    echo "      █████████▄  ██  ▄█████████     "
    echo "     █ ████  ▀████  ████▀  ████ █    "
    echo "     ██ ████▄  ████████  ▄████ ██    "
    echo "     ▐██ ████▄ ████████ ▄████ ██▌    "
    echo "      ███ ██████████████████ ███     "
    echo "      ████ ████████████████ ████     "
    echo "      █████ ██████████████ █████     "
    echo "      ▐█████ ████████████ █████▌     "
    echo "       ██████ ██████████ ██████      "
    echo "       ███████ ████████ ███████      "
    echo "         ██████ ██████ ██████        "
    echo "            ████ ████ ████           "
    echo "                █ ██ █               "
    echo ""
    echo ""
fi

tar czf condor_package.tgz $@

INDEX=$((1 + RANDOM % 4))
if [ "x${INDEX}" == x1 ]; then
    echo "Everything I touch is food for my hunger!"
    echo "My hunger for power!"
    echo "                        - Megatron"
elif [ "x${INDEX}" == x2 ]; then
    echo "Megatron doesn't yield. He conquers!"
    echo "                        - Megatron"
elif [ "x${INDEX}" == x3 ]; then
    echo "One shall stand, one shall fall!"
    echo "                        - Optimus Prime"
elif [ "x${INDEX}" == x4 ]; then
    echo "Autobots, roll out!"
    echo "                        - Optimus Prime"
fi

