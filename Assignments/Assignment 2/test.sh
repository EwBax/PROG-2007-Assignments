# Run tests based on the following input files:
# leapyear-table-sample.txt

returnStatus=0

# Only show colours on local "Git Bash" terminal
passFormat="if [ $TERM = "xterm" ]; then tput sgr0 && tput setaf 2; fi"
failFormat="if [ $TERM = "xterm" ]; then tput sgr0 && tput setaf 1; fi"
normalFormat="if [ $TERM = "xterm" ]; then tput sgr0; fi"

# If not on Linux set output to .exe
unameValue="$(uname -s)"
echo "Testing OS Platform: $unameValue"
fileExtension=".exe"
if [  $unameValue = "Linux" ] || [  $unameValue = "Darwin" ]; then
    fileExtension=".out"
fi

echo "Running tests..."
echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
1900
2000
2008
2021
abc
3.14
-5
N
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output=$(./a$fileExtension <<'EOF'
1900
2000
2008
2021
abc
3.14
-5
N
EOF
)

newOutput=""
while read line
do
  newOutput=$newOutput$(echo "$line" | xargs)
done <<< "$output"

expected_output_1="1900 IS NOT a leap year!"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_1" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #1 Year 1900 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #1 Year 1900 - Did not get Expected Output: '$expected_output_1'"
  returnStatus=1
fi

expected_output_2="2000 IS a leap year!"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_2" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #2 Year 2000 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #2 Year 2000 - Did not get Expected Output: '$expected_output_2'"
  returnStatus=1
fi

expected_output_3="2008 IS a leap year!"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_3" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #3 Year 2008 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #3 Year 2008 - Did not get Expected Output: '$expected_output_3'"
  returnStatus=1
fi

expected_output_4="2021 IS NOT a leap year!"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_4" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #4 Year 2021 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #4 Year 2021 - Did not get Expected Output: '$expected_output_4'"
  returnStatus=1
fi

expected_output_5="Sorry that input is invalid"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_5" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #5 Year abc - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #5 Year abc - Did not get Expected Output: '$expected_output_5'"
  returnStatus=1
fi

expected_output_6="Sorry that input is invalid"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_6" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #6 Year 3.14 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #6 Year 3.14 - Did not get Expected Output: '$expected_output_6'"
  returnStatus=1
fi

expected_output_7="Sorry that input is invalid"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_7" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #7 Year -5 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #7 Year -5 - Did not get Expected Output: '$expected_output_7'"
  returnStatus=1
fi



# Need to read in original file line by line and check it
testOneStatus=0
badLine=""
while read line
do
  newLine=$(echo $line | xargs)
  if grep -q "$newLine" <<< "$newOutput"; then
    continue
  else
    testOneStatus=1
    badLine="$line"
    break
  fi
done < leapyear-table-sample.txt

if [ $testOneStatus -eq 0 ] ; then
  eval "$passFormat"
  echo "Test #8 Leap Year Chart  - Pass: Normal Output is correct"
else
  eval "$failFormat"
  echo "Test #8 Leap Year Chart - Fail: Normal Output Missing Expected line: `echo $badLine`"
  returnStatus=1
fi

echo
if [ $returnStatus -eq 0 ] ; then
    eval "$passFormat"
    echo "All tests passed."
else
    eval "$failFormat"
    echo "One or more tests failed."
fi

eval "$normalFormat"

echo
exit $returnStatus