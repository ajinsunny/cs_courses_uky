#!/bin/bash
################################################################
# Testing script for CS315 relational operator
#####TESTING SCRIPT DEVELOPED FOR CS315 JWJ CS UK
#####Version February 1, 2017
#####For class use only -- otherwise use on your own risk
#####Do not distribute
################################################################

export TERM="xterm-256color"

# Functions to print colour codes. tput interfaces with the terminfo library.
plain () { tput sgr0; }     # Reset to default foreground/background, no bold.
bold ()  { tput bold; }     # Turn on bold, do not change colors.
red ()   { tput setaf 1; }  # Red foreground.
green () { tput setaf 2; }  # Green foreground.
brown () { tput setaf 3; }  # Brown (dark yellow) foreground.
ltred ()   { bold; red; }   # Bold red.
ltgreen () { bold; green; } # Bold green.
yellow ()  { bold; brown; } # Bold brown = yellow.

# Display a unified diff indented three spaces, with additions in green
# and deletions in red.
showdiff () {
  local difffile="$1"
  sed -e "s/^+.*/$(green)&$(plain)/ ;
          s/^-.*/$(red)&$(plain)/ ;
          s/^/   /" "$difffile"
}

# Variables for the next four functions: count of good, bad, and
# questionable tests, and lists of names of bad and questionable tests.
numgood=0
numbad=0
numquestionable=0
bads=()
questionables=()

# Mark that a test succeeded, failed, or had a questionable result.
# Each of these functions takes the test name as its first argument.
# questionable() takes an optional additional message as its second
# argument.
success() {
  local testname="$1" # unused
  echo " -> $(ltgreen)Success!$(plain)"
  let ++numgood
}
failure() {
  local testname="$1"
  echo " -> $(ltred)Failure:$(plain)"
  let ++numbad
  bads+=("$testname")
}
questionable() {
  local testname="$1"
  local msg="$2"
  echo " -> $(brown)${msg:-Questionable}:$(plain)"
  let ++numquestionable
  questionables+=("$testname")
}
# Summarize number of good/bad/questionable test results, and list again the
# tests with bad or questionable results.
summarize() {
  echo -n "$(ltgreen)$numgood good$(plain), "
  echo -n "$(ltred)$numbad bad$(plain), "
  echo    "$(brown)$numquestionable questionable$(plain)"

  if (( numbad > 0 )); then
    echo -n " --> Failed tests:$(ltred)"
    printf " %s" "${bads[@]}"
    echo "$(plain)"
  fi

  if (( numquestionable > 0 )); then
    echo -n " --> Possibly failed tests:$(brown)"
    printf " %s" "${questionables[@]}"
    echo "$(plain)"
  fi
}

test () {
  touch tmpout tmpdiff

  for t in ./tests/*.in; do
    base=${t%.in}
    echo "-> Testing against ${base}.in..."
    echo " -> $1 < ${base}.in"
    $1 < ${base}.in &> tmpout
    if diff -u tmpout ${base}.out > tmpdiff; then
      success $base
    else
      failure $base
      echo "  -> Diff results:"
      showdiff tmpdiff
    fi
  done;

  rm tmpout tmpdiff
}

case $1 in
  java)
    echo "Compiling Java program..."
    echo "-> javac Main.java"
    javac Main.java
    echo "Testing Java program..."
    test "java Main"
    rm Main.class
    summarize
    ;;
  cpp)
    echo "Compiling C++ program..."
    echo "-> gcc -std=c++11 main.cpp"
    g++ -std=c++11 main.cpp
    echo "Testing C++ program..."
    test "./a.out"
    rm a.out
    summarize
    ;;
  *)
    echo "Please pass either java or cpp as argumets to this script."
    ;;
esac
